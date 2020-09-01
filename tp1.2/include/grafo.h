#ifndef GRAFO_H
#define GRAFO_H

#include <vector>
#include <list>

class Grafo {
private:
    unsigned int n, m; //dimensões do tabuleiro
    std::vector<std::list<int>*> vertices; //vector de lists para as adjacências
public:
    //construtor
    Grafo(unsigned int n, unsigned int m, unsigned int** tabuleiro);

    //destrutor
    ~Grafo();

    //imprime grafo
    void imprimir();
};

#endif
