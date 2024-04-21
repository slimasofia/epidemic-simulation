#include <SFML/Graphics.hpp>
using namespace sf;

enum class EstadoSaude {
    Saudavel,
    Infectado,
    Recuperado
};

class Pessoa{
    public:
    float x, y; //posição
    EstadoSaude estado;

    Pessoa(float x, float y, EstadoSaude estado);
    //void atualizar();
    void desenhar(RenderWindow& window);

};