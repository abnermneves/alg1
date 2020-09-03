#ifndef GRAFO_H
#define GRAFO_H

#include <vector>
#include <list>

class Grafo {
private:
    unsigned int n, m; //dimensões do tabuleiro
    std::vector<std::list<int>*> vertices; //vector de lists para as adjacências
    std::vector<unsigned int> casas; //casas a andar em cada posição do tabuleiro
    std::vector<bool> descoberto; //marca se o vértice já foi descoberto na BFS
public:
    //construtor e destrutor
    Grafo(unsigned int n, unsigned int m, unsigned int** tabuleiro);
    ~Grafo();

    std::vector<std::list<int>*>* BFS(unsigned int s);

    //setters, getters e impressão
    unsigned int get_n();
    unsigned int get_m();
    unsigned int get_casas(unsigned int v);
    void imprimir();
};

#endif
