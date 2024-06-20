#ifndef PERSON_H
#define PERSON_H

#include <SFML/Graphics.hpp>
using namespace sf;

enum class HealthCondition {
    Susceptible,
    Infected,
    Recovered
};

class Person {
    private:
    float x, y;
    float v_x, v_y;
    float infectedTime; 
    HealthCondition condition;

    public:
    Person(float x, float y, float v_x, float v_y, HealthCondition condition);
    
    float getX() const;
    float getY() const;
    HealthCondition getCondition() const;
    void setCondition(HealthCondition newCondition);
    void update(float dt, float w_width, float w_height);
    void draw(RenderWindow& window, float w_width, float w_height);
    void increaseInfectedTime(float days);
    float getInfectedTime() const;
    float distance(const Person& other) const;
};

#endif
