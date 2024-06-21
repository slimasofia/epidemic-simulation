#include "Simulation.h"
#include <iostream>
using namespace std;

#define WIDTH 800
#define HEIGHT 600
//#define INFEC_DURATION 15 //em dias
#define RECOVERY_TIME 7


int main() {
    int population;
    cout << "population: " << endl;
    cin >> population;
    Simulation simulation(WIDTH, HEIGHT, population, RECOVERY_TIME);

    simulation.run();

    return 0;
}
