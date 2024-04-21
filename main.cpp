#include <SFML/Graphics.hpp>
#include "Pessoa.h"
#include <cstdlib> // Para srand e rand
#include <ctime> // Para time
using namespace std;
using namespace sf;

/* instalar sfml: sudo apt-get install libsfml-dev

 g++ -c main.cpp
 g++ main.o -o sfml-app Pessoa.cpp -lsfml-graphics -lsfml-window -lsfml-system 
 ./sfml-app

a taxa de infecção e a população serão parâmetros que o "usuário" poderá editar?

*/
int main()
{
    srand(time(nullptr));
    RenderWindow window(VideoMode(800, 600), "Epidemic Simulation");

    // vetor para armazenar as pessoas
    vector<Pessoa> pessoas;

    // adicionando 100 pessoas saudáveis
    for (int i = 0; i < 100; ++i) {
        float x = static_cast<float>(rand() % 800); // Posição x aleatória
        float y = static_cast<float>(rand() % 600); // Posição y aleatória
        EstadoSaude estado = EstadoSaude::Saudavel; // Estado inicial: Saudável
        pessoas.push_back(Pessoa(x, y, estado)); // Adiciona pessoa ao vetor
    }
    //adicionando 1 pessoa infectada
    for (int i = 0; i < 1; ++i) {
        float x = static_cast<float>(rand() % 800); // Posição x aleatória
        float y = static_cast<float>(rand() % 600); // Posição y aleatória
        EstadoSaude estado = EstadoSaude::Infectado; // Estado inicial: Infectado
        pessoas.push_back(Pessoa(x, y, estado)); // Adiciona pessoa ao vetor
    }

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear();

               // Atualizar e desenhar cada pessoa no vetor
        for (auto& pessoa : pessoas) {
            //pessoa.atualizar(); Atualizar lógica da pessoa
            pessoa.desenhar(window); // Desenhar a pessoa na janela
        }
        window.display();
    }

    return 0;
}