#pragma once
#include <cstdint>
#include <random>

struct Individuo {
    
public:
    int genes;

    int8_t* dnaX;
    int8_t* dnaY;

    int vitorias = 0;
    int derrotas = 0;
    int empates = 0;
    int pontuacao = 0;

    Individuo();
    Individuo(int genes);
    Individuo(Individuo pai, Individuo mae);

    void pais(Individuo pai, Individuo mae);

    int8_t randomGene();
    int zeroOuUm();

    void limparPontuacaoIndividuo();
    void mutacao();

    void premiarVitoria();
    void premiarDerrota();
    void premiarEmpate();

    // Function prototypes for random number generation with different ranges
    int randomA(int max);
    int randomA(int min, int max);
};
