#include <iostream>
#include "Epidemia.h"
#include <cstdlib>
#include <ctime>
#include <math.h>
using namespace std;

int n_infectados = 0;
//const int TEMPO_RECUPERACAO = 14;  Tempo de recuperação em dias
const float TAXA_INFECCAO = 0.05f; // Taxa de infecção (5%)

Epidemia::Epidemia() {
    srand(static_cast<unsigned int>(time(nullptr)));
}

void Epidemia::infectar(std::vector<Pessoa>& pessoas, int dias, float taxa_infeccao = TAXA_INFECCAO) {
        // int index = rand() % num_saudaveis;
        // pessoas[index].setEstado(EstadoSaude::Infectado);
        // n_infectados++;

    // infectar pessoas com base em uma taxa de infecção 
    for (int dia = 0; dia < dias; ++dia) {
        for (size_t i = 0; i < pessoas.size(); ++i) {
            // Verifica se a pessoa é saudável e gera um número aleatório para determinar se ela será infectada
            if (pessoas[i].getEstado() == EstadoSaude::Saudavel) {
                float chance_infeccao = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
                if (chance_infeccao < taxa_infeccao) {
                    pessoas[i].setEstado(EstadoSaude::Infectado);
                    n_infectados++;
                }
            }

            // Atualiza o estado da pessoa para recuperado após um certo período de tempo
            // if (pessoas[i].getEstado() == EstadoSaude::Infectado) {
            //     if (pessoas[i].getTempoInfectado() >= TEMPO_RECUPERACAO) {
            //         pessoas[i].setEstado(EstadoSaude::Recuperado);
            //         n_infectados--;
            //     } else {
            //         pessoas[i].incrementarTempoInfectado();
            //     }
            // }
        }

        // Imprime o numero de infectados ao final de cada dia
        cout << "Fim do dia " << dia + 1 << endl;
        cout << "Número de infectados: " << n_infectados << endl;
    }
}

//número total de infectados
int Epidemia::getNumInfectados() const {
    return n_infectados;
}
