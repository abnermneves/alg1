#include "grafo.h"
#include "funcoes.h"
#include <iostream>

Grafo::Grafo(unsigned int n, unsigned int m, unsigned int** tabuleiro){
    this->n = n;
    this->m = m;

    //adicionando adjacências
    unsigned int v, c, x, y, mx, my;
    for (unsigned int i = 0; i < n; i++){
        for (unsigned int j = 0; j < m; j++){
            v = index(i, j, this->m); //vértice atual
            c = tabuleiro[i][j]; // quantidade de casas a andar
            this->vertices.push_back(new std::list<int>);
            this->descoberto.push_back(false);

            if (c == 0)
                continue;

            //vizinho na direção +x
            if (indicesValidos(i, j+c, this->n, this->m)){
                x = index(i, j+c, this->m);
                this->vertices.at(v)->push_back(x);
            }

            //vizinho na direção +y
            if (indicesValidos(i-c, j, this->n, this->m)){
                y = index(i-c, j, this->m);
                this->vertices.at(v)->push_back(y);
            }

            //vizinho na direção -x
            if (indicesValidos(i, j-c, this->n, this->m)){
                mx = index(i, j-c, this->m);
                this->vertices.at(v)->push_back(mx);
            }

            //vizinho na direção -y
            if (indicesValidos(i+c, j, this->n, this->m)){
                my = index(i+c, j, this->m);
                this->vertices.at(v)->push_back(my);
            }
        }
    }
}

Grafo::~Grafo(){

}

std::vector<std::list<int>*>* Grafo::BFS(unsigned int s){
    //árvore BFS com camadas Li
    std::vector<std::list<int>*>* tree = new std::vector<std::list<int>*>;
    tree->push_back(new std::list<int>);

    //define todos os vértices como ainda não descobertos
    for (auto it = this->descoberto.begin(); it != this->descoberto.end(); it++){
        *it = false;
    }

    //define s como descoberto
    this->descoberto.at(s) = true;

    //inicializa contador
    unsigned int i = 0;

    //L0 = {s}
    tree->at(0)->push_back(s);

    //enquanto Li não é vazia, preenche Li+1
    while (!tree->at(i)->empty()){
        //cria camada Li+1
        tree->push_back(new std::list<int>);
        auto li = tree->at(i);

        //para todo vértice u em Li
        for (auto u = li->begin(); u != li->end(); u++){
            auto vizinhos = this->vertices.at(*u);

            //consideramos todas as arestas (u, v) incidentes a u
            for (auto v = vizinhos->begin(); v != vizinhos->end(); v++){

                //se v ainda não foi descoberto, acrescentamos na próxima camada
                if (!this->descoberto.at(*v)){
                    this->descoberto.at(*v) = true;
                    tree->at(i+1)->push_back(*v);
                }
            }
        }
        i++;
    }
    return tree;
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
