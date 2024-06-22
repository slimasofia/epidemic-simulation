#ifndef SIMULATION_H
#define SIMULATION_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Person.h"
#include "Epidemic.h"
#include "TextManager.h"

class Simulation {
public:
    Simulation(int width, int height, int population, int recoveryTime);
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
    int currentDay;
    //int infectionDuration; 
    int population;
    int recoveryTime;
    float elapsedTime; // tempo decorrido desde o último dia
    std::vector<Person> people;
    Epidemic epidemic;
    sf::Font font;
    TextManager textManager;
    bool simulationEnded;

};

#endif