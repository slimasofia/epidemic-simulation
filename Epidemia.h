#ifndef EPIDEMIA_H
#define EPIDEMIA_H

#include <vector>
#include "Pessoa.h"
#include <SFML/Graphics.hpp>

using namespace std;

class Epidemia{
    public:
    Epidemia(float taxaInfec, float taxaRecup);
    void infectar(std::vector<Pessoa>& pessoas, int largura, int altura);
    void recuperar();

    float taxaInfec;
    float taxaRecup; // ou tempoRecuperacao ?

};

#endif