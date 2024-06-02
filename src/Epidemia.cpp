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

void Epidemia::infectar(std::vector<Pessoa>& pessoas, int num_saudaveis) {
    // Número de pessoas infectadas aleatório, limitado pelo número de pessoas saudáveis
    int num_infectadas = rand() % num_saudaveis/2;
    //float x, y;
    for (int i = 0; i < num_infectadas; ++i) { // gerando o número de pessoas infectadas aleatoriamente (com a função srand)
        int index = rand() % num_saudaveis; // Seleciona aleatoriamente uma pessoa saudável
        pessoas[index].setEstado(EstadoSaude::Infectado); // Marca como infectada
        n_infectados++;
    }

    // PARA CONTROLE
    cout << "POPULAÇÃO TOTAL: " << pessoas.size() << endl;
    cout << "INFECTADOS INICIALMENTE: " << n_infectados << endl;
    int n_saudaveis_restantes = num_saudaveis - n_infectados;
    cout << "SAUDÁVEIS RESTANTES: " << n_saudaveis_restantes << endl;

}