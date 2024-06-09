#ifndef EPIDEMIA_H
#define EPIDEMIA_H

#include <vector>
#include "Pessoa.h"

class Epidemia {
public:
    Epidemia();
    void infectar(std::vector<Pessoa>& pessoas, float taxa_infeccao);
    void recuperar(std::vector<Pessoa>& pessoas, float tempo_recup);
    int getNumInfectados() const;
    int getNumRecuperados() const;

private:
    int n_infectados;
    int n_recuperados;
};

#endif
