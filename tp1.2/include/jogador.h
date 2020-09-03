#ifndef JOGADOR_H
#define JOGADOR_H

#include <vector>
#include <list>

class Jogador {
private:
    char nome;
    unsigned int posicao; //posição atual
    unsigned int casas_andadas_ultima_rodada;
    unsigned int ultima_rodada; //ultima rodada que participou
    std::vector<unsigned int> visitado; //posições do tabuleiro em que já esteve
public:
    //construtor e destrutor
    Jogador(char nome, unsigned int posicao);
    ~Jogador();

    //setters e getters
    char get_nome() const;
    unsigned int get_posicao() const;
    unsigned int get_casas_andadas() const;
    unsigned int get_ultima_rodada() const;
    bool visitou(unsigned int posicao) const;
    void add_visitado(unsigned int posicao);
    void set_posicao(unsigned int posicao);
    void set_casas_andadas(unsigned int casas);
    void set_ultima_rodada(unsigned int rodada);
};

//comparator para a priority_queue levar em consideração os critérios
//descritos no enunciado: 1) menor quantidade de casas andadas na última rodada
//e 2)ordem de jogada da primeira rodada
class comparator_jogadores {
public:
    bool operator() (const Jogador* j1, const Jogador* j2) const;
};

#endif
