#include <iostream>
#include "Epidemia.h"
#include <cstdlib>
#include <ctime>
#include <math.h>
using namespace std;

int n_infectados = 0;
const float DISTANCIA_MINIMA = 10.0f;

Epidemia::Epidemia() {
    srand(static_cast<unsigned int>(time(nullptr)));
}

void Epidemia::infectar(std::vector<Pessoa>& pessoas, int largura, int altura) {
    float x, y;
    for (int i = 0; i < rand() % 100; ++i) { // gerando o número de pessoas infectadas aleatoriamente (com a função srand)
        x = static_cast<float>(rand() % largura); // Posição x aleatória
        y = static_cast<float>(rand() % altura); // Posição y aleatória
        float v_x = static_cast<float>((rand() % 200) - 100); // Velocidade inicial aleatória em x
        float v_y = static_cast<float>((rand() % 200) - 100); // Velocidade inicial aleatória em y
        EstadoSaude estado = EstadoSaude::Infectado; // Estado inicial: Infectado
        pessoas.push_back(Pessoa(x, y, v_x, v_y, estado)); // Adiciona pessoa no vetor
        n_infectados++;
    }

    // Itera sobre todas as pessoas
    for (vector<Pessoa>::size_type i = 0; i < pessoas.size(); ++i) {
        for (vector<Pessoa>::size_type j = 0; j < pessoas.size(); ++j) {
            // Certifica-se de não verificar a mesma pessoa consigo mesma
            if (i != j) {
                // Calcula a distância entre as posições das pessoas
                float dist = sqrt(pow(pessoas[i].getX() - pessoas[j].getX(), 2) + pow(pessoas[i].getY() - pessoas[j].getY(), 2));
                
                // Se a distância for menor que um certo valor e uma das pessoas for saudável e a outra infectada, então a pessoa saudável se torna infectada
                if (dist < DISTANCIA_MINIMA && pessoas[i].getEstado() == EstadoSaude::Saudavel && pessoas[j].getEstado() == EstadoSaude::Infectado) {
                    pessoas[i].setEstado(EstadoSaude::Infectado);
                    n_infectados++;
                }
            }
        }
    }

    cout << n_infectados << endl;
}