#include "Simulacao.h"

int main() {
    int largura = 800;
    int altura = 600;
    int duracao_infeccao = 10; // Duração da infecção em dias

    Simulacao simulacao(largura, altura, duracao_infeccao);
    simulacao.run();

    return 0;
}
