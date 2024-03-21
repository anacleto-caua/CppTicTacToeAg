// VelhaInoORetorno.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <chrono>
#include "AlgoritmoGenetico.h"

using namespace std;
using namespace std::chrono;

int main()
{

    std::cout << "At least it started!!!" << endl;

    int genes = 50;
    int numIndividuos = 30;
    float removerPercent = 50;
    float mutacaoPercent = 20;
    float pontuacaoPercent= 0.7;

    AlgoritmoGenetico ag = AlgoritmoGenetico(genes, numIndividuos, removerPercent, mutacaoPercent);
    auto start = high_resolution_clock::now();

    for (int i = 0; i < 1000; i++) {

        ag.iniciarSelecao();
    
        //std::cout << endl << endl << endl << "Tentativas: " << i << endl;

        while (ag.maiorPontuacaoRound < double(ag.pontuacaoMaxima * pontuacaoPercent) && ag.rounds < 20) {
            ag.selecao();

            /*
            std::cout << "Rounds: " << ag.rounds << endl;
            std::cout << "Pontuacao Maxima: " << ag.pontuacaoMaxima << endl;
            std::cout << "Maior pontuacao round: " << ag.maiorPontuacaoRound << endl;
            */
        }

        /*
        std::cout << "Dna Melhor Individuo: " << std::endl;
        for (int k = 0; k < genes; k++) {
            std::cout << (unsigned int)ag.individuos[0].dnaX[k];
        }
        std::cout << std::endl;
        */

    }
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<milliseconds>(stop - start);

    cout << "Duracao em Millisegundos: " << duration.count() << endl;

    int j;
    cin >> j;

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
