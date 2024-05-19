#ifndef PESSOA_H
#define PESSOA_H

#include <SFML/Graphics.hpp>
using namespace sf;

enum class EstadoSaude {
    Saudavel,
    Infectado,
    Recuperado
};

class Pessoa{
    public:
    float x, y; //posição
    float v_x, v_y;
    EstadoSaude estado;

    Pessoa(float x, float y, float v_x, float v_y, EstadoSaude estado);
    void atualizar(float dt, float w_width, float w_height);
    void desenhar(RenderWindow& window, float w_width, float w_heigth); //float w_width, float w_height

};

#endif