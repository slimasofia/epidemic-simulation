#include "Person.h"
#include <cmath>

Person::Person(float x, float y, float v_x, float v_y, HealthCondition condition) : x(x), y(y), v_x(v_x), v_y(v_y), condition(condition) {}

void Person::update(float dt, float w_width, float w_height) {
    // Atualizar posição da pessoa com base em sua velocidade e no intervalo de tempo (delta_t)
    x += v_x * dt;
    y += v_y * dt;

    // Verificar se a pessoa ultrapassou os limites da tela e ajustar as posições
    if (x < 0) {
        x = 0;
        v_x = -v_x; // Inverte a direção da velocidade em x
    } else if (x >= w_width) {
        x = w_width - 1; // Ajusta a posição para a borda direita da tela
        v_x = -v_x; // Inverte a direção da velocidade em x
    }

    if (y < 0) {
        y = 0;
        v_y = -v_y; // Inverte a direção da velocidade em y
    } else if (y >= w_height) {
        y = w_height - 1; // Ajusta a posição para a borda inferior da tela
        v_y = -v_y; // Inverte a direção da velocidade em y
    }

    if (condition == HealthCondition::Infected) {
        infectedTime += dt/3; 
    }
}

void Person::draw(RenderWindow& window, float w_width, float w_height) {
    
    if (x >= 0 && x < w_width && y >= 0 && y < w_height) {
       CircleShape circle(5); // cria bolinha com raio 5 pixels
       circle.setPosition(x, y); // Define a posição da bolinha com base na posição da pessoa

    // Define a cor da bolinha com base no estado de saúde da pessoa
    switch (condition) {
        case HealthCondition::Susceptible:
            circle.setFillColor(Color::Green); // suscetível --> pode se infectar a qualquer momento
            break;
        case HealthCondition::Infected:
            circle.setFillColor(Color::Red); // infectada
            break;
        case HealthCondition::Recovered:
            circle.setFillColor(Color::Blue); // recuperada --> não tem a possobilidade de ficar doente novamente
            break;
    }
    // Desenha a bolinha na janela
    window.draw(circle);
    }
}

HealthCondition Person::getCondition() const {
    return condition;
}

float Person::getX() const {
    return x;
}

float Person::getY() const {
    return y;
}

float Person::distance(const Person& other) const {
    float dx = x - other.getX();
    float dy = y - other.getY();
    return std::sqrt(dx * dx + dy * dy);
}

void Person::setCondition(HealthCondition newCondition) {
    condition = newCondition;
    if (condition == HealthCondition::Infected) {
        infectedTime = 0;
    }
}

void Person::increaseInfectedTime(float days) {
    if (condition == HealthCondition::Infected) {
        infectedTime += days;
    }
}

float Person::getInfectedTime() const {
    return infectedTime;
}