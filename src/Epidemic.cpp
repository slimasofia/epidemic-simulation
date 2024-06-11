#include <iostream>
#include "Epidemic.h"
#include <cstdlib>
#include <ctime>
using namespace std;

Epidemic::Epidemic() : infectedCount(0), recoveredCount(0) {
    srand(static_cast<unsigned int>(time(nullptr)));
}

void Epidemic::infect(vector<Person>& people) {
    const float INFEC_DISTANCE = 60.0f; // Distância mínima para infecção

    // FUNÇÃO INFECTAR - POR APROXIMAÇÃO

    // para cada pessoa do vetor
    for (size_t i = 0; i < people.size(); ++i) {
        // se a pessoa for suscetível
        if (people[i].getCondition() == HealthCondition::Susceptible) {
            // percorrer novamente cada pessoa do vetor 
            for (size_t j = 0; j < people.size(); ++j) {
                // se pessoa i for diferente de pessoa j e o estado de j estiver infectada
                if (i != j && people[j].getCondition() == HealthCondition::Infected) {
                    // comparando distancia entre i e j
                    float d = people[i].distance(people[j]);
                    // se a distância entre os dois for menor do que a distância definida para infecção:
                    if (d < INFEC_DISTANCE) {
                        // infectar!
                        people[i].setCondition(HealthCondition::Infected);
                        infectedCount++;
                        break; // Uma vez infectado, não precisa verificar mais
                    }
                }
            }
        }
    }
}

/* FUNÇÃO INFECTAR - POR TAXA DE INFECÇÃO
    percorrendo cada pessoa do vetor
    for (size_t i = 0; i < people.size(); ++i) {
        se encontrar uma pessoa saudável, criar uma chance de infecção para ela
        if (people[i].getCondition() == HealthCondition::Healthy) {
            float chance_infeccao = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
            se a chance de infecção for menor que a taxa de infecção: infectar
            if (chance_infeccao < taxa_infeccao) {
                people[i].setCondition(HealthCondition::Infected);
                infectedCount++;
            }
        }
    }
*/

void Epidemic::recover(vector<Person>& people, float recoveryTime) {
    for (size_t i = 0; i < people.size(); ++i) {
        // para cada pessoa infectada, se ela está a mais tempo infectada que o tempo de recuperação: recuperar
        if (people[i].getCondition() == HealthCondition::Infected && people[i].getInfectedTime() >= recoveryTime) {
            people[i].setCondition(HealthCondition::Recovered);
            infectedCount--;
            recoveredCount++;
        }
    }
}

int Epidemic::getNumInfected() const {
    return infectedCount;
}

int Epidemic::getNumRecovered() const {
    return recoveredCount;
}
