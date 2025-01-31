#pragma once
#include "Tabuleiro.h"
#include "IndividuoStruct.h"
#include <random>

class AlgoritmoGenetico
{
public:
	int rounds;

	int genes;
	int numIndividuos;
	float removerPercent;
	float mutacaoPercent;

	int maiorPontuacaoRound = 0;
	int pontuacaoMaxima;

	Tabuleiro tabuleiro;

	Individuo* individuos;

	AlgoritmoGenetico(int genes, int numIndividuos, float removerPercent, float mutacaoPercent);

	void gerarPopulacaoInicial();

	void competir();

	void competir(int i, int j);

	void ordenarPopulacao();

	bool compareIndividuos(const Individuo& a, const Individuo& b);

	void eliminarPopulacao();

	void limparPontuacaoPopulacao();

	void cruzarPopulacao();

	void iniciarSelecao();

	void selecao();

	void apresentacao();

	int(*getMovimentos())[2];

	int(*getLinhaVencedora())[2];

	int getVencedor();

	int randomA(int max);

	int randomA(int min, int max);
};

