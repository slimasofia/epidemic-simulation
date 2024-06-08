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
    int tempoInfectado; ///////
    EstadoSaude estado;
    
    // Métodos para obter a posição x e y
    float getX() const { return x; }
    float getY() const { return y; }
    int getTempoInfectado() const; /////////////////

    // Método para obter o estado de saúde
    EstadoSaude getEstado() const { return estado; }

    // Método para definir o estado de saúde
    void setEstado(EstadoSaude novoEstado) { estado = novoEstado; }

    Pessoa(float x, float y, float v_x, float v_y, EstadoSaude estado);
    void atualizar(float dt, float w_width, float w_height);
    void setTempoInfectado(int tempo); ///////////
    void desenhar(RenderWindow& window, float w_width, float w_heigth); //float w_width, float w_height
    void incrementarTempoInfectado();
};

#endif