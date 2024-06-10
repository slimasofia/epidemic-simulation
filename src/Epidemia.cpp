#include <iostream>
#include "Epidemia.h"
#include <cstdlib>
#include <ctime>
using namespace std;

Epidemia::Epidemia() : n_infectados(0), n_recuperados(0) {
    srand(static_cast<unsigned int>(time(nullptr)));
}

void Epidemia::infectar(vector<Pessoa>& pessoas) {
  const float DISTANCIA_INFEC = 60.0f; // Distância mínima para infecção

    // FUNÇÃO INFECTAR - POR APROXIMAÇÃO

    //para cada pessoa do vetor
    for (size_t i = 0; i < pessoas.size(); ++i) {
        // se a pessoa for saudável
        if (pessoas[i].getEstado() == EstadoSaude::Saudavel) {
            // percorrer novamente cada pessoa do vetor 
            for (size_t j = 0; j < pessoas.size(); ++j) {
                // se pessoa i for diferente de pessoa j e o estado de j estiver infectada
                if (i != j && pessoas[j].getEstado() == EstadoSaude::Infectado) {
                    // comparando distancia entre i e j
                    float distancia = pessoas[i].distancia(pessoas[j]);
                    // se a distãncia entre os dois for menor do que a distância definida para infecção:
                    if (distancia < DISTANCIA_INFEC) {
                            // infectar!
                            pessoas[i].setEstado(EstadoSaude::Infectado);
                            n_infectados++;
                            break; // Uma vez infectado, não precisa verificar mais
                    }
                }
            }
        }
    }
}

/* FUNÇÃO INFECTAR - POR TAXA DE INFECÇÃO
    percorrendo cada pessoa do vetor
    for (size_t i = 0; i < pessoas.size(); ++i) {
        se encontrar uma pessoa saudável, criar uma chance de infecção para ela
        if (pessoas[i].getEstado() == EstadoSaude::Saudavel) {
            float chance_infeccao = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
            se a chance de infecção for menor que a taxa de infecção: infectar
            if (chance_infeccao < taxa_infeccao) {
                pessoas[i].setEstado(EstadoSaude::Infectado);
                n_infectados++;
            }
        }
    }
}

*/

void Epidemia::recuperar(vector<Pessoa>& pessoas, float tempo_recup) {
    for (size_t i = 0; i < pessoas.size(); ++i) {
        //para cada pessoa infectada, se ela está a mais tempo infectada que o tempo de recuperação: recuperar
        if (pessoas[i].getEstado() == EstadoSaude::Infectado && pessoas[i].getTempoInfectado() >= tempo_recup) {
            pessoas[i].setEstado(EstadoSaude::Recuperado);
            n_infectados--;
            n_recuperados++;
        }
    }
}

int Epidemia::getNumInfectados() const {
    return n_infectados;
}

int Epidemia::getNumRecuperados() const{
    return n_recuperados;
}