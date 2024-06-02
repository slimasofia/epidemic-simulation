#ifndef EPIDEMIA_H
#define EPIDEMIA_H

#include <vector>
#include "Pessoa.h"
#include <SFML/Graphics.hpp>

using namespace std;

class Epidemia{
    public:
    Epidemia();   
    //int n_infectados;
    //const float DISTANCIA_MINIMA = 10.0f;
    int getNumInfectados() const;
    void infectar(std::vector<Pessoa>& pessoas, int dias, float taxa_infeccao);
    void recuperar();

};

#endif