#include "Pessoa.h"

Pessoa::Pessoa(float x, float y, float v_x, float v_y, EstadoSaude estado) : x(x), y(y), v_x(v_x), v_y(v_y), estado(estado) {}


void Pessoa::atualizar(float dt, float w_width, float w_height) {
    // Atualizar posição da pessoa com base em sua velocidade e no intervalo de tempo (delta_t)
    x += v_x * dt;
    y += v_y * dt;

    // Verificar se a pessoa ultrapassou os limites da tela e ajustar as posições
    if (x < 0) {
        x = 0;
        v_x = -v_x; // Inverte a direção da velocidade em x
    } else if (x >= w_width) {
        x = w_width - 1; // Ajusta a posição para a borda direita da tela
        v_x = -v_x; // Inverte a direção da velocidade em x
    }

    if (y < 0) {
        y = 0;
        v_y = -v_y; // Inverte a direção da velocidade em y
    } else if (y >= w_height) {
        y = w_height - 1; // Ajusta a posição para a borda inferior da tela
        v_y = -v_y; // Inverte a direção da velocidade em y
    }
}

//float w_width, float w_height

// EVITAR QUE AS BOLINHAS SEJAM DESENHADAS FORA DO ESPAÇO DA TELA
void Pessoa::desenhar(RenderWindow& window, float w_width, float w_height) {
    
    if (x >= 0 && x < w_width && y >= 0 && y < w_height) {
       CircleShape circle(5); // cria bolinha com raio 5 pixels
       circle.setPosition(x, y); // Define a posição da bolinha com base na posição da pessoa

    // Define a cor da bolinha com base no estado de saúde da pessoa
    switch (estado) {
        case EstadoSaude::Saudavel:
            circle.setFillColor(Color::Green); // saudável
            break;
        case EstadoSaude::Infectado:
            circle.setFillColor(Color::Red); // infectada
            break;
        case EstadoSaude::Recuperado:
            circle.setFillColor(Color::Blue); // recuperada
            break;
    }
    // Desenha a bolinha na janela
    window.draw(circle);
    }
}
