#include "jogador.h"

// --------------------------- CONSTRUTOR E DESTRUTOR -----------------------//

Jogador::Jogador(char nome, unsigned int posicao){
    this->nome = nome;
    this->posicao = posicao;
    this->casas_andadas_ultima_rodada = 0;
    this->ultima_rodada = 0;
    this->visitado.push_back(posicao);
}

Jogador::~Jogador(){

}

//--------------------------- SETTERS E GETTERS ----------------------------//

char Jogador::get_nome() const{
    return this->nome;
}

unsigned int Jogador::get_posicao() const{
    return this->posicao;
}

unsigned int Jogador::get_casas_andadas() const{
    return this->casas_andadas_ultima_rodada;
}

unsigned int Jogador::get_ultima_rodada() const{
    return this->ultima_rodada;
}

bool Jogador::visitou(unsigned int posicao) const{
    for (auto it = this->visitado.begin(); it != this->visitado.end(); it++){
        if (*it == posicao)
            return true;
    }
    return false;
}

void Jogador::add_visitado(unsigned int posicao){
    this->visitado.push_back(posicao);
}

void Jogador::set_posicao(unsigned int posicao){
    this->posicao = posicao;
}

void Jogador::set_casas_andadas(unsigned int casas){
    this->casas_andadas_ultima_rodada = casas;
}

void Jogador::set_ultima_rodada(unsigned int rodada){
    this->ultima_rodada = rodada;
}

// ----------------------------- COMPARATOR -----------------------------//

bool comparator_jogadores::operator() (const Jogador* j1, const Jogador* j2) const {
    //compara os jogadores levando em consideração os critérios do enunciado
    //o nome de A é anterior ao de B se, e somente se, A jogou antes de B na primeira rodada
    if (j1->get_casas_andadas() != j2->get_casas_andadas())
        return j1->get_casas_andadas() > j2->get_casas_andadas();
    else
        return j1->get_nome() > j2->get_nome();
}
