# epidemic-simulation
Simulação de uma epidemia utilizando a biblioteca SFML - Projeto para a disciplina de Programação Orientada a Objetos II.


## Descrição
A simulação inicia-se com pelo menos 1 pessoa infectada, de uma população que pode ser escolhida na hora da execução. Uma distância mínima para infecção é definida, e a contaminação se da a partir da aproximação de pessoas suscetíveis com pessoas infectadas. Os novos infectados são atualizados ao fim de cada dia.


É importante saber que, nessa simulação, cada pessoa recebe uma posição e movimentação aleatórias, portanto, alguns pontos podem ser percebidos:

- Densidade Populacional: Em uma população menor, a densidade de pessoas no mesmo espaço pode ser menor, o que pode resultar em menos encontros, tornando a propagação da infecção mais lenta.

- Movimentação: Todas as pessoas têm uma probabilidade de se mover para áreas não habitadas, então a taxa de encontros pode ser significativamente menor em uma população pequena, aumentando o tempo necessário para a infecção se espalhar.

- Probabilidade de Contato: Em uma população maior, a probabilidade de uma pessoa saudável encontrar uma pessoa infectada é maior, devido ao maior número de encontros possíveis. Em uma população menor, essa probabilidade diminui, potencialmente desacelerando a taxa de infecção.


Ao ser infectada, uma contagem é iniciada para a pessoa, e ela irá se recuperar no momento em que o seu tempo de infecção for maior ou igual ao tempo de recuperação. Nessa simulação o tempo **mínimo** de recuperação é de 7 dias.

**Essa simulação considera que pessoas recuperadas não se infectam novamente.**


## Para rodar

### _Requisitos_
- c++17
- biblioteca [SFML](https://www.sfml-dev.org/)
- make

**Para sistemas baseados em Debian, por exemplo, você pode instalar os requisitos com:**

    sudo apt install build-essential 
    sudo apt-get install libsfml-dev

### _Instruções_

#### Clone este repositório:
    git clone https://github.com/slimasofia/epidemic-simulation.git

#### Navegue até o diretório do projeto:
    cd epidemic-simulation 

#### Compile o projeto:
    make

#### Execute:
    ./epidemic-simulation




---