#include "grafo.h"
#include <iostream>

Grafo::Grafo(unsigned int n, unsigned int m, unsigned int** tabuleiro){
    this->n = n;
    this->m = m;

    //adicionando adjacências
    unsigned int v, x, y, mx, my;
    for (unsigned int i = 0; i < n; i++){
        for (unsigned int j = 0; j < m; j++){
            //convertendo os índices da matriz para uma indexação linear
            v = index(i, j); //vértice atual
            x = index(i, j+1); //vizinho na direção +x
            y = index(i-1, j); //vizinho na direção y
            mx = index(i, j-1); //vizinho na direção -x
            my = index(i+1, j); //vizinho na direção -y

            this->vertices.push_back(new std::list<int>);
            this->vertices.at(v)->push_back(x);
            this->vertices.at(v)->push_back(y);
            this->vertices.at(v)->push_back(mx);
            this->vertices.at(v)->push_back(my);
        }
    }
}

Grafo::~Grafo(){

}

unsigned int Grafo::index(int i, int j){
    //como o módulo de C++ não é euclidiano,
    //acabaria retornando um valor inválido para operações com -1
    //então precisa colocar essas verificações
    if (i == -1)
        i = this->n - 1;
    else
        i = i % this->n;

    if (j == -1)
        j = this->m - 1;
    else
        j = j % this->m;

    return this->m*i + j;
}

void Grafo::imprimir(){
    for (unsigned int i = 0; i < this->n*this->m; i++){
        auto v = this->vertices.at(i);
        std::cout << i << " : ";
        for (auto it = v->begin(); it != v->end(); it++){
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }
}
