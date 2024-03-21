#include "IndividuoStruct.h"
 
int genes;

int8_t* dnaX;
int8_t* dnaY;

int vitorias = 0;
int derrotas = 0;
int empates = 0;
int pontuacao = 0;

Individuo::Individuo() {

    this->genes = 0;

    this->vitorias = 0;
    this->derrotas = 0;
    this->empates = 0;
    this->pontuacao = 0;

    this->dnaX = new int8_t[genes];
    this->dnaY = new int8_t[genes];

    // for (int i = 0; i < genes; i++) {
    //     dnaX[i] = randomGene();
    //     dnaY[i] = randomGene();
    // }
}


Individuo::Individuo(int genes) {

    this->genes = genes;

    this->vitorias = 0;
    this->derrotas = 0;
    this->empates = 0;
    this->pontuacao = 0;

    this->dnaX = new int8_t[genes];
    this->dnaY = new int8_t[genes];

    for (int i = 0; i < genes; i++) {
        dnaX[i] = randomGene();
        dnaY[i] = randomGene();
    }
}

Individuo::Individuo(Individuo pai, Individuo mae) {

    this->genes = pai.genes;

    this->vitorias = 0;
    this->derrotas = 0;
    this->empates = 0;
    this->pontuacao = 0;

    this->dnaX = new int8_t[genes];
    this->dnaY = new int8_t[genes];

    for (int i = 0; i < genes; i++) {
        if (zeroOuUm() == 0) {
            dnaX[i] = pai.dnaX[i];
        }
        else {
            dnaX[i] = mae.dnaX[i];
        }

        if (zeroOuUm() == 0) {
            dnaY[i] = pai.dnaY[i];
        }
        else {
            dnaY[i] = mae.dnaY[i];
        }
    }
}

void Individuo::pais(Individuo pai, Individuo mae)
{
    this->genes = pai.genes;
    this->dnaX = new int8_t[genes];
    this->dnaY = new int8_t[genes];

    for (int i = 0; i < genes; i++) {
        if (zeroOuUm() == 0) {
            dnaX[i] = pai.dnaX[i];
        }
        else {
            dnaX[i] = mae.dnaX[i];
        }

        if (zeroOuUm() == 0) {
            dnaY[i] = pai.dnaY[i];
        }
        else {
            dnaY[i] = mae.dnaY[i];
        }
    }
}

int8_t Individuo::randomGene()
{
    // Return the generated random integer
    return randomA(9);
}

int Individuo::zeroOuUm()
{
    // Return the generated random integer
    return randomA(2);
}

void Individuo::limparPontuacaoIndividuo() {
    this->vitorias = 0;
    this->derrotas = 0;
    this->empates = 0;
    this->pontuacao = 0;
}

void Individuo::mutacao() {
    dnaX[randomA(genes)] = randomGene();
    dnaY[randomA(genes)] = randomGene();
}

void Individuo::premiarVitoria() {
    vitorias++;
    pontuacao += 3;
}

void Individuo::premiarDerrota() {
    derrotas++;
    pontuacao += 0;
}

void Individuo::premiarEmpate() {
    empates++;
    pontuacao += 1;
}

int Individuo::randomA(int max) {
    // Seed para o gerador de n�meros aleat�rios
    std::random_device rd;
    std::mt19937 gen(rd());

    // Definindo os limites inferior e superior para a gera��o de n�meros aleat�rios
    int lower_limit = 0;
    int upper_limit = max - 1;

    // Definindo a distribui��o de n�meros aleat�rios
    std::uniform_int_distribution<> distrib(lower_limit, upper_limit);

    // Gerando o valor aleat�rio
    int random_number = distrib(gen);

    return random_number;
}

int Individuo::randomA(int min, int max) {
    // Seed para o gerador de n�meros aleat�rios
    std::random_device rd;
    std::mt19937 gen(rd());

    // Definindo os limites inferior e superior para a gera��o de n�meros aleat�rios
    int lower_limit = min;
    int upper_limit = max;

    // Definindo a distribui��o de n�meros aleat�rios
    std::uniform_int_distribution<> distrib(lower_limit, upper_limit);

    // Gerando o valor aleat�rio
    int random_number = distrib(gen);

    return random_number;
}
