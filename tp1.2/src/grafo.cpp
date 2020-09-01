#include "grafo.h"
#include <iostream>

Grafo::Grafo(unsigned int n, unsigned int m, unsigned int** tabuleiro){
    this->n = n;
    this->m = m;

    //adicionando adjacências
    unsigned int v, x, y, mx, my;
    for (unsigned int i = 0; i < n; i++){
        for (unsigned int j = 0; j < m; j++){
            v = index(i, j); //vértice atual
            this->vertices.push_back(new std::list<int>);

            //vizinho na direção +x
            if (indicesValidos(i, j+1)){
                x = index(i, j+1);
                this->vertices.at(v)->push_back(x);
            }

            //vizinho na direção +y
            if (indicesValidos(i-1, j)){
                y = index(i-1, j);
                this->vertices.at(v)->push_back(y);
            }

            //vizinho na direção -x
            if (indicesValidos(i, j-1)){
                mx = index(i, j-1);
                this->vertices.at(v)->push_back(mx);
            }

            //vizinho na direção -y
            if (indicesValidos(i+1, j)){
                my = index(i+1, j);
                this->vertices.at(v)->push_back(my);
            }
        }
    }
}

Grafo::~Grafo(){

}

unsigned int Grafo::index(int i, int j){
    return this->m*i + j;
}

bool Grafo::indicesValidos(int i, int j){
    //se os índices estão fora do tabuleiro, retorna false
    if (i < 0 || i >= (int)this->n || j < 0 || j >= (int)this->m)
        return false;
    return true;
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
