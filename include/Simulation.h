#ifndef SIMULATION_H
#define SIMULATION_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Person.h"
#include "Epidemic.h"
#include "TextManager.h"

class Simulation {
public:
    Simulation(int largura, int altura, int duracao_infeccao);
    void run();
    void handleEvents();
    void update(float dt);
    void render();

private:
    sf::RenderWindow window;
    sf::Clock clock;
    int windowWidth;
    int windowHeight;
    int infectedCount;
    int recoveredCount;
    int currentDay; // Current day of the simulation
    int infectionDuration; // Duration of the infection in days
    float elapsedTime; // Elapsed time since the last day
    std::vector<Person> people;
    Epidemic epidemic;
    TextManager textManager;
};

#endif