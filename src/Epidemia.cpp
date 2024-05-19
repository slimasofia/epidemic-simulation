#include "Epidemia.h"
#include <cstdlib>
#include <ctime>

Epidemia::Epidemia(float taxaInfec, float taxaRecup)
    : taxaInfec(taxaInfec), taxaRecup(taxaRecup) {
    srand(static_cast<unsigned int>(time(nullptr)));
}

void Epidemia::infectar(std::vector<Pessoa>& pessoas, int largura, int altura) {
    for (int i = 0; i < 10; ++i) {
        float x = static_cast<float>(rand() % largura); // Posição x aleatória
        float y = static_cast<float>(rand() % altura); // Posição y aleatória
        float v_x = static_cast<float>((rand() % 200) - 100); // Velocidade inicial aleatória em x
        float v_y = static_cast<float>((rand() % 200) - 100); // Velocidade inicial aleatória em y
        EstadoSaude estado = EstadoSaude::Infectado; // Estado inicial: Infectado
        pessoas.push_back(Pessoa(x, y, v_x, v_y, estado)); // Adiciona pessoa no vetor
    }
}
