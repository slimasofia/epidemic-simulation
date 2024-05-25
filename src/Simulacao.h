#ifndef SIMULACAO_H
#define SIMULACAO_H

#include <SFML/Graphics.hpp>
#include "Pessoa.h"
#include "Epidemia.h"
#include <vector>

using namespace std;
using namespace sf;


class Simulacao{
    public:
    Simulacao(int largura, int altura);
    void run();
    void processEvents();
    void update(float dt);
    void render();

    RenderWindow window;
    int largura;
    int altura;
    Epidemia epidemia;
    vector<Pessoa> pessoas;
    Clock clock;
};

#endif