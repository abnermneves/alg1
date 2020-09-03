#include "funcoes.h"
#include "jogador.h"
#include <iostream>
#include <vector>
#include <queue>

unsigned int index(int i, int j, unsigned int m){
    return (int)m*i + j;
}

bool indicesValidos(int i, int j, unsigned int n, unsigned int m){
    //se os índices estão fora do tabuleiro, retorna false
    if (i < 0 || i >= (int)n || j < 0 || j >= (int)m)
        return false;
    return true;
}

void imprimir_tabuleiro(unsigned int** tabuleiro, unsigned int n, unsigned int m){
    for (unsigned int i = 0; i < n; i++){
        for (unsigned int j = 0; j < m; j++){
            std::cout << tabuleiro[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void imprimir_jogadores(std::priority_queue<Jogador*, std::vector<Jogador*>, comparator_jogadores>* jogadores){
    std::vector<Jogador*> temp;
    while (!jogadores->empty()){
        auto it = jogadores->top();
        jogadores->pop();
        std::cout << it->get_nome() << " " << it->get_posicao() << std::endl;
        temp.push_back(it);
    }

    for (unsigned int i = 0; i < temp.size(); i++){
        jogadores->push(temp.at(i));
    }
}

/*
    auto tree = g.BFS(2);
    for (auto it = tree->begin(); it != tree->end(); it++){
        for (auto it2 = (*it)->begin(); it2 != (*it)->end(); it2++){
            std::cout << *it2 << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;*/
