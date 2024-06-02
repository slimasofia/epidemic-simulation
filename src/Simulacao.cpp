#include "Simulacao.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

Simulacao::Simulacao(int largura, int altura) : window(sf::VideoMode(largura, altura), "Epidemic Simulation"), largura(largura), altura(altura), epidemia() {

    srand(static_cast<unsigned>(time(nullptr)));

    //adicionando pessoas saudáveis
    for(int i = 0; i < 100; ++i) {
        float x = static_cast<float>(rand() % largura); // Posição x aleatória
        float y = static_cast<float>(rand() % altura); // Posição y aleatória
        EstadoSaude estado = EstadoSaude::Saudavel; // Estado inicial: Saudável
        float v_x = static_cast<float>(rand() % 200 - 100); // Velocidade inicial aleatória em x (-100 a 100 pixels/segundo)
        float v_y = static_cast<float>(rand() % 200 - 100);
        pessoas.push_back(Pessoa(x, y, v_x, v_y, estado)); // Adiciona pessoa no vetor
    }
    int total_saudaveis = pessoas.size();

    //infectando algumas
    epidemia.infectar(pessoas, total_saudaveis);
}

void Simulacao::run(){
        while (window.isOpen()){
        float dt = clock.restart().asSeconds(); //Calculando o intervalo de tempo desde o último quadro em segundos
        processEvents();
        update(dt);
        render();
    }  
}

void Simulacao::processEvents(){
            Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
}

void Simulacao::update(float dt){
    for (auto& pessoa : pessoas) {
            pessoa.atualizar(dt, largura, altura); //Atualizar lógica da pessoa
    }
}

void Simulacao::render(){
    window.clear();
    for (auto& pessoa : pessoas) {
        pessoa.desenhar(window, largura, altura);
    }
    window.display();
}

//pessoa.desenhar(window, largura, altura); // Desenhar a pessoa na janela