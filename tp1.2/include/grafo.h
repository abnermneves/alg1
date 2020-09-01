#ifndef GRAFO_H
#define GRAFO_H

#include <vector>
#include <list>

class Grafo {
private:
    unsigned int n; //quantidade de vértices
    unsigned int m; //quantidade de arestas
    std::vector<std::list<int>*> vertices; //vector de lists para as adjacências
public:
    Grafo(unsigned int n, unsigned int m, unsigned int** tabuleiro);
    ~Grafo();

    //converte os índices da matriz para uma indexação linear
    unsigned int index(int i, int j);
    //imprime grafo
    void imprimir();
};

#endif