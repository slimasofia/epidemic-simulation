#include <iostream>
#include "Epidemia.h"
#include <cstdlib>
#include <ctime>
using namespace std;

Epidemia::Epidemia() : n_infectados(0), n_recuperados(0) {
    srand(static_cast<unsigned int>(time(nullptr)));
}

void Epidemia::infectar(std::vector<Pessoa>& pessoas, float taxa_infeccao) {
    // percorrendo cada pessoa do vetor
    for (size_t i = 0; i < pessoas.size(); ++i) {
        // se encontrar uma pessoa saudável, criar uma chance de infecção para ela
        if (pessoas[i].getEstado() == EstadoSaude::Saudavel) {
            float chance_infeccao = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
            //se a chance de infecção for menor que a taxa de infecção: infectar
            if (chance_infeccao < taxa_infeccao) {
                pessoas[i].setEstado(EstadoSaude::Infectado);
                n_infectados++;
            }
        }
    }
}


void Epidemia::recuperar(std::vector<Pessoa>& pessoas, float tempo_recup) {
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