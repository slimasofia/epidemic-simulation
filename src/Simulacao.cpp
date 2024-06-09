#include "Simulacao.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

Simulacao::Simulacao(int largura, int altura, int duracao_infeccao) 
    : window(sf::VideoMode(largura, altura), "Epidemic Simulation"), 
      clock(),
      largura(largura), 
      altura(altura), 
      total_infectados(0), 
      total_recuperados(0),
      dia_atual(0), 
      duracao_infeccao(duracao_infeccao), 
      tempo_decorrido(0), 
      epidemia() {

    srand(static_cast<unsigned>(time(nullptr)));

    // Adicionando pessoas saudáveis
    for (int i = 0; i < 20; ++i) {
        float x = static_cast<float>(rand() % largura); // Posição x aleatória
        float y = static_cast<float>(rand() % altura); // Posição y aleatória
        EstadoSaude estado = EstadoSaude::Saudavel; // Estado inicial: Saudável
        float v_x = static_cast<float>(rand() % 200 - 100); // Velocidade inicial aleatória em x (-100 a 100 pixels/segundo)
        float v_y = static_cast<float>(rand() % 200 - 100);
        pessoas.push_back(Pessoa(x, y, v_x, v_y, estado)); // Adiciona pessoa no vetor
    }

    if (!textManager.loadFont("/usr/share/fonts/truetype/ubuntu/Ubuntu-L.ttf")) {
        cout << "Erro ao carregar a fonte!" << endl;
    }

    textManager.addText("dia", "Dia: 0", 20, sf::Color::White, 10, 10);
    textManager.addText("infectados", "Total de infectados: 0", 20, sf::Color::Red, 10, 40);
    textManager.addText("recuperados", "Total de recuperados: 0", 20, sf::Color::Blue, 10, 70);
}

void Simulacao::run() {
    while (window.isOpen()) {
        float dt = clock.restart().asSeconds(); // Calculando o intervalo de tempo desde o último quadro em segundos
        processEvents();
        update(dt);
        render();
    }
}

void Simulacao::processEvents() {
    sf::Event event;
    //A SIMULAÇÃO DEVE TERMINAR TAMBÉM SE O NÚMERO DE INFECTADOS = 0
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
    }
}

void Simulacao::update(float dt) {
    // Atualizar o tempo decorrido
    tempo_decorrido += dt;

    // Se um dia passou (usando 3 segundos de tempo real como 1 dia na simulação)
    if (tempo_decorrido >= 3.0f) {
        tempo_decorrido = 0.0f;
        dia_atual++;

        // Se a duração da infecção terminou, fechar simulação
        if (dia_atual > duracao_infeccao) {
            window.close();
            return;
        }

        float TAXA_INFECCAO = 0.05f;
        float TEMPO_RECUP = 4.0f;

        epidemia.infectar(pessoas, TAXA_INFECCAO); 
        epidemia.recuperar(pessoas, TEMPO_RECUP);   
    

        total_infectados = epidemia.getNumInfectados();
        total_recuperados = epidemia.getNumRecuperados();

        textManager.setText("dia", "Dia: " + to_string(dia_atual));
        textManager.setText("infectados", "Total de infectados: " + to_string(total_infectados));
        textManager.setText("recuperados", "Total de recuperados: " + to_string(total_recuperados));

        cout << "Fim do dia " << dia_atual << endl;
        cout << "Total de infectados: " << total_infectados << endl;
        cout << "Total de recuperados: " << total_recuperados << endl;
    }

    for (auto& pessoa : pessoas) {
        pessoa.atualizar(dt, largura, altura); // Atualizar lógica da pessoa
    }
}

void Simulacao::render() {
    window.clear();
    for (auto& pessoa : pessoas) {
        pessoa.desenhar(window, largura, altura);
    }

    textManager.draw(window);
    window.display();
}
