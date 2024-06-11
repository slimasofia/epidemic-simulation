#include "Simulation.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

Simulation::Simulation(int windowWidth, int windowHeight, int infectionDuration) 
    : window(sf::VideoMode(windowWidth, windowHeight), "Epidemic Simulation"), 
      clock(),
      windowWidth(windowWidth), 
      windowHeight(windowHeight), 
      infectedCount(0), 
      recoveredCount(0),
      currentDay(0), 
      infectionDuration(infectionDuration), 
      elapsedTime(0), 
      epidemic() {

    srand(static_cast<unsigned>(time(nullptr)));

    for (int i = 0; i < 100; ++i) {
        float x = static_cast<float>(rand() % windowWidth);
        float y = static_cast<float>(rand() % windowHeight); 
        HealthCondition condition = HealthCondition::Susceptible; 
        float v_x = static_cast<float>(rand() % 200 - 100);
        float v_y = static_cast<float>(rand() % 200 - 100);
        people.push_back(Person(x, y, v_x, v_y, condition)); 
    }

    people[0].setCondition(HealthCondition::Infected);
    infectedCount++;


    if (!textManager.loadFont("/usr/share/fonts/truetype/ubuntu/Ubuntu-L.ttf")) {
        cout << "Error loading font!" << endl;
    }

    textManager.addText("day", "Day: 0", 20, sf::Color::White, 10, 10);
    textManager.addText("infected", "Total Infected: 0", 20, sf::Color::Red, 10, 40);
    textManager.addText("recovered", "Total Recovered: 0", 20, sf::Color::Blue, 10, 70);
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
    // atualizando o tempo decorrido
    elapsedTime += dt;

    // Se 1 dia passou (usando 3 segundos reais como 1 dia de simulação)
    if (elapsedTime >= 3.0f) {
        elapsedTime = 0.0f;
        currentDay++;

        if (currentDay > infectionDuration) {
            window.close();
            return;
        }

        float RECOVERY_TIME = 4.0f; 

        epidemic.infect(people); 
        epidemic.recover(people, RECOVERY_TIME);   
    
        infectedCount = std::max(epidemic.getNumInfected(), 0);
        recoveredCount = std::max(epidemic.getNumRecovered(), 0);

        textManager.setText("day", "Day: " + to_string(currentDay));
        textManager.setText("infected", "Total Infected: " + to_string(infectedCount));
        textManager.setText("recovered", "Total Recovered: " + to_string(recoveredCount));

        cout << "End of day " << currentDay << endl;
        cout << "Total Infected: " << infectedCount << endl;
        cout << "Total Recovered: " << recoveredCount << endl;
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
