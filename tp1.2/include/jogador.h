#ifndef JOGADOR_H
#define JOGADOR_H

#include <vector>
#include <list>

class Jogador {
private:
    char nome;
    unsigned int posicao; //posição inicial
    unsigned int casas_andadas_ultima_rodada;
    std::vector<int>* li; //camada Li para a BFS
    std::vector<int>* li1; //camada Li+1 para a BFS;
public:
    Jogador(char nome, unsigned int posicao_inicial);
    ~Jogador();

    char get_nome() const;
    unsigned int get_posicao() const;
    unsigned int get_casas_andadas() const;

    void set_casas_andadas(unsigned int casas);
};

class comparator_jogadores {
public:
    bool operator() (const Jogador* j1, const Jogador* j2) const;
};

#endif
