#include "Pessoa.h"

Pessoa::Pessoa(float x, float y, EstadoSaude estado) : x(x), y(y), estado(estado) {
}

//void Pessoa::atualizar() {
    // Atualizar lógica da pessoa
//}

void Pessoa::desenhar(RenderWindow& window) {
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
