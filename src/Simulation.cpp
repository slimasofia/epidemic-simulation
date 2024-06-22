#include "Simulation.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

Simulation::Simulation(int windowWidth, int windowHeight, int population, int recoveryTime) 
    : window(sf::VideoMode(windowWidth, windowHeight), "Epidemic Simulation"), 
      clock(),
      windowWidth(windowWidth), 
      windowHeight(windowHeight), 
      infectedCount(0), 
      recoveredCount(0),
      currentDay(0), 
      population(population),
      recoveryTime(recoveryTime),
      elapsedTime(0), 
      epidemic(),
      simulationEnded(false) { 

    srand(static_cast<unsigned>(time(nullptr)));

    for (int i = 0; i < population; ++i) {
        float x = static_cast<float>(rand() % windowWidth);
        float y = static_cast<float>(rand() % windowHeight); 
        HealthCondition condition = HealthCondition::Susceptible; 
        float v_x = static_cast<float>(rand() % 200 - 100);
        float v_y = static_cast<float>(rand() % 200 - 100);
        people.push_back(Person(x, y, v_x, v_y, condition)); 
    }

    people[0].setCondition(HealthCondition::Infected);

    if (!textManager.loadFont("res/OpenSans-Regular.ttf")) {
        std::cout << "Error loading font!" << endl;
        exit(EXIT_FAILURE);
    }

    textManager.addText("day", "Day: 0", 20, sf::Color::White, 10, 10);
    textManager.addText("infected", "Total Infected: 1", 20, sf::Color::Red, 10, 40);
    textManager.addText("recovered", "Total Recovered: 0", 20, sf::Color::Blue, 10, 70);
    textManager.addText("end", "", 20, sf::Color::White, windowWidth/2, windowHeight/2);
    
}

void Simulation::run() {
    while (window.isOpen()) {
        float dt = clock.restart().asSeconds(); 
        handleEvents();
        update(dt);
        render();
    }
}

void Simulation::handleEvents() {
    sf::Event event;
  
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
    }
}

void Simulation::update(float dt) {
    if (simulationEnded) return;  // Não atualiza mais se a simulação terminou

    // Atualizando o tempo decorrido
    elapsedTime += dt;

    // Se 1 dia passou (usando 2 segundos reais como 1 dia de simulação)
    if (elapsedTime >= 2.0f) {
        elapsedTime = 0.0f;
        currentDay++;

        epidemic.infect(people); 
        epidemic.recover(people, recoveryTime);   
        
        infectedCount = max(epidemic.getNumInfected(), 0);
        recoveredCount = max(epidemic.getNumRecovered(), 0);

        textManager.setText("day", "Day: " + to_string(currentDay));
        textManager.setText("infected", "Total Infected: " + to_string(infectedCount));
        textManager.setText("recovered", "Total Recovered: " + to_string(recoveredCount));

        if (infectedCount == 0) {
            simulationEnded = true;

            int s = 0;
            for (int i = 0; i < population; i++) {   
                if(people[i].getCondition() == HealthCondition::Susceptible){
                s++;
                }
            }

            //textManager.setText("end", "The epidemic is over "); 
            //textManager.centerText("end", window);

            std::cout << "\nEnd of day "<< currentDay << ": The epidemic is over" << endl;
            std::cout << "Days until everyone is healthy again: " << currentDay << endl;
            std::cout << "Recovered: " << recoveredCount << endl;
            std::cout << "Uninfected people: " << s << endl;

        }

        if(!simulationEnded){
        std::cout << "\nEnd of day " << currentDay << endl;
        std::cout << "Total Infected: " << infectedCount << endl;
        std::cout << "Total Recovered: " << recoveredCount << endl;
        }

    }

    for (auto& person : people) {
        person.update(dt, windowWidth, windowHeight); 
    }
}

void Simulation::render() {
    window.clear();
    for (auto& person : people) {
        person.draw(window, windowWidth, windowHeight);
    }

    textManager.draw(window);
    window.display();
}
