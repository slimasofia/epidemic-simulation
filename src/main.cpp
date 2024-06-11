#include "Simulation.h"

int main() {
    int largura = 800;
    int altura = 600;
    int duracao_infeccao = 15; //em dias

    Simulation simulation(largura, altura, duracao_infeccao);
    simulation.run();

    return 0;
}
