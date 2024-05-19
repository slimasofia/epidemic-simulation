#include <SFML/Graphics.hpp>
#include "Pessoa.h"
#include "Epidemia.h"
#include <cstdlib> // Para srand e rand
#include <ctime> // Para time
using namespace std;
using namespace sf;

#define W_WIDTH 800
#define W_HEIGHT 600

int main()
{
    srand(time(nullptr));
    RenderWindow window(VideoMode(W_WIDTH, W_HEIGHT), "Epidemic Simulation");

    // vetor para armazenar as pessoas
    vector<Pessoa> pessoas;

    // adicionando 100 pessoas saudáveis
    for (int i = 0; i < 100; ++i) {
        float x = static_cast<float>(rand() % W_WIDTH); // Posição x aleatória
        float y = static_cast<float>(rand() % W_HEIGHT); // Posição y aleatória
        EstadoSaude estado = EstadoSaude::Saudavel; // Estado inicial: Saudável
        float v_x = static_cast<float>(rand() % 200 - 100); // Velocidade inicial aleatória em x (-100 a 100 pixels/segundo)
        float v_y = static_cast<float>(rand() % 200 - 100);
        pessoas.push_back(Pessoa(x, y, v_x, v_y, estado)); // Adiciona pessoa no vetor
    }
    
    Epidemia epidemia(0.1f, 10.0f); //passando uma taxa de infecção e recuperação
    epidemia.infectar(pessoas, W_WIDTH, W_HEIGHT);

    Clock clock;
    while (window.isOpen()){
        float dt = clock.restart().asSeconds(); //Calculando o intervalo de tempo desde o último quadro em segundos
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        window.clear();

        // Atualizar e desenhar cada pessoa no vetor
        for (auto& pessoa : pessoas) {
            pessoa.atualizar(dt, W_WIDTH, W_HEIGHT); //Atualizar lógica da pessoa
            pessoa.desenhar(window, W_WIDTH, W_HEIGHT); // Desenhar a pessoa na janela
        }
        window.display();
    }

    return 0;
}
