#include "jogador.h"
#include <vector>
#include <queue>

//apenas algumas funções úteis para diversas partes do programa e para debugar

//converte os índices da matriz para uma indexação linear (m*i + j)
unsigned int index(int i, int j, unsigned int m);

//verifica se os índices estão dentro dos limites do tabuleiro
bool indicesValidos(int i, int j, unsigned int n, unsigned int m);

void imprimir_tabuleiro(unsigned int** tabuleiro, unsigned int n, unsigned int m);
void imprimir_jogadores(std::priority_queue<Jogador*, std::vector<Jogador*>, comparator_jogadores>* jogadores);
