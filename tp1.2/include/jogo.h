#include <queue>
#include <vector>
#include "grafo.h"
#include "jogador.h"

Jogador* jogar(unsigned int** tabuleiro, Grafo* g,
               std::priority_queue<Jogador*, std::vector<Jogador*>, comparator_jogadores>* jgdrs);
