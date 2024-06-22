#include "Simulation.h"
#include <iostream>
using namespace std;

#define WIDTH 800
#define HEIGHT 600
//#define INFEC_DURATION 15
#define RECOVERY_TIME 7


int main() {
    int population;
    cout << "\nPopulation: ";
    cin >> population;
    Simulation simulation(WIDTH, HEIGHT, population);

    simulation.run();

    return 0;
}
