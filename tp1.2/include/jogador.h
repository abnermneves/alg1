#ifndef JOGADOR_H
#define JOGADOR_H

class Jogador {
private:
    char nome;
    unsigned int posicao;
    unsigned int casas_andadas_ultima_rodada;
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
