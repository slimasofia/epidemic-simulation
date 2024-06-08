#include <SFML/Graphics.hpp>
#include <vector>
#include "Pessoa.h"
#include "Epidemia.h"

class Simulacao {
public:
    Simulacao(int largura, int altura);
    void run();

private:
    void processEvents();
    void update(float dt);
    void render();

    sf::RenderWindow window;
    sf::Clock clock;
    int largura;
    int altura;
    int total_infectados;
    int dia_atual; // Dia atual da simulação
    float tempo_decorrido; // Tempo decorrido desde o último dia
    std::vector<Pessoa> pessoas;
    Epidemia epidemia;
};
