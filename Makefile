CC = g++
CFLAGS =

VelhaInoORetorno: VelhaInoORetorno.o AlgoritmoGenetico.o IndividuoStruct.o Tabuleiro.o
	$(CC) $(CFLAGS) -o VelhaInoORetorno VelhaInoORetorno.o AlgoritmoGenetico.o Tabuleiro.o IndividuoStruct.o

VelhaInoORetorno.o: VelhaInoORetorno.cpp AlgoritmoGenetico.h
	$(CC) $(CFLAGS) -c VelhaInoORetorno.cpp
 
AlgoritmoGenetico.o: AlgoritmoGenetico.h Tabuleiro.h IndividuoStruct.h
 
Tabuleiro.o: Tabuleiro.h

IndividuoStruct.o: IndividuoStruct.h

clean:
	rm VelhaInoORetorno VelhaInoORetorno.o AlgoritmoGenetico.o Tabuleiro.o IndividuoStruct.o  