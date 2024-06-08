#ifndef EPIDEMIA_H
#define EPIDEMIA_H

#include <vector>
#include "Pessoa.h"

class Epidemia {
public:
    Epidemia();
    void infectar(std::vector<Pessoa>& pessoas, float taxa_infeccao);
    int getNumInfectados() const;

private:
    int n_infectados;
};

#endif
