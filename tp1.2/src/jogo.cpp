#include "jogo.h"
#include "funcoes.h"
#include <iostream>

Jogador* jogar(unsigned int** tabuleiro, Grafo* g, std::priority_queue<Jogador*, std::vector<Jogador*>, comparator_jogadores>* jgdrs){
    unsigned int jogada = 0;
    unsigned int rodada, qntdJgdrs;
    std::vector<Jogador*> copia;

    for (rodada = 1; !jgdrs->empty(); rodada++){

        qntdJgdrs = jgdrs->size();

        for (jogada = 0; jogada < qntdJgdrs; jogada++){

            //próximo jogador a jogar
            Jogador* j = jgdrs->top();
            jgdrs->pop();

            //posição do jogador no tabuleiro
            unsigned int posicao = j->get_posicao();

            //quantidade de casas a andar determinada pela posição do jogador no tabuleiro
            unsigned int casas = g->get_casas(posicao);

            //árvore gerada pela BFS a partir da posição atual do jogador
            std::vector<std::list<int>*>* bfstree = g->BFS(posicao);

            //cálculo da posição final do tabuleiro, o objetivo dos jogadores
            unsigned int final = index(g->get_n()-1, g->get_m()-1, g->get_m());

            //se é possível andar a quantidade de casas determinada
            if (bfstree->size() > 1){
                //posições que estão na distância determinada
                std::list<int>* li = bfstree->at(1);

                //encontra a primeira casa possível ainda não visitada
                auto it = li->begin();
                for (; it != li->end() && j->visitou(*it); it++);

                if (*it == (int)final){
                    //então esse jogador já consegue chegar na posição final e é o vencedor!
                    j->set_ultima_rodada(rodada);
                    return j;
                }
                else if (it != li->end()){
                    //esse jogador ainda não consegue chegar no final,
                    //mas tem alguma casa ainda não visitada, então vai pra ela
                    j->set_posicao(*it);
                    j->set_casas_andadas(casas);
                    j->set_ultima_rodada(rodada);
                    j->add_visitado(*it);

                    //e ele é classificado pra próxima rodada
                    copia.push_back(j);
                } else {
                    delete j;
                }
            }
            else {
                //se não é possível ir pra lugar algum, o jogador já foi retirado
                //da lista de jogadores e não voltará pra próxima rodada
                delete j;
            }

            //liberando a memória ocupada pela árvore BFS desse vértice
            for (unsigned int i = 0; i < bfstree->size(); i++)
                delete bfstree->at(i);
            delete bfstree;
        }
        //passa os jogadores da próxima rodada para a priority queue
        while (!copia.empty()){
            jgdrs->push(copia.back());
            copia.pop_back();
        }
    }
    return nullptr;
}
