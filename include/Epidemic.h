#ifndef EPIDEMIC_H
#define EPIDEMIC_H

#include <vector>
#include "Person.h"

class Epidemic {
public:
    Epidemic();
    void infect(std::vector<Person>& people);
    void recover(std::vector<Person>& people, float recoveryTime);
    int getNumInfected() const;
    int getNumRecovered() const;

private:
    int infectedCount;
    int recoveredCount;
};

#endif
