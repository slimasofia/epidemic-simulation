#include <iostream>
#include "Epidemia.h"
#include <cstdlib>
#include <ctime>
using namespace std;

Epidemia::Epidemia() : n_infectados(0) {
    srand(static_cast<unsigned int>(time(nullptr)));
}

void Epidemia::infectar(std::vector<Pessoa>& pessoas, int dias, float taxa_infeccao) {
    for (int dia = 0; dia < dias; ++dia) {
        for (size_t i = 0; i < pessoas.size(); ++i) {
            if (pessoas[i].getEstado() == EstadoSaude::Saudavel) {
                float chance_infeccao = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
                if (chance_infeccao < taxa_infeccao) {
                    pessoas[i].setEstado(EstadoSaude::Infectado);
                    n_infectados++;
                }
            }
        }
    }
}

int Epidemia::getNumInfectados() const {
    return n_infectados;
}
