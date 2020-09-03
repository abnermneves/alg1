#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <map>
#include "jogo.h"
#include "grafo.h"
#include "funcoes.h"
#include "jogador.h"

int main(int argc, char* argv[]) {

//--------------------------- FLUXO DE ARQUIVO ----------------------------//

    if (argc != 2)
        return 0;

    std::string fname;
    fname = argv[1];
    std::ifstream file(fname);

    if (!file.is_open())
        return 0;


//------------------------ DECLARAÇÃO E LEITURA DE TABULEIRO --------------//

    //dimensões do tabuleiro nxm e quantidade k de jogadores
    unsigned int n, m, k;
    file >> n >> m >> k;

    //cria tabuleiro com valores da entrada
    unsigned int** tabuleiro;
    tabuleiro = new unsigned int* [n];
    for (unsigned int i = 0; i < n; i++){
        tabuleiro[i] = new unsigned int[m];
    }

    for (unsigned int i = 0; i < n; i++){
        for (unsigned int j = 0; j < m; j++){
            file >> tabuleiro[i][j];
        }
    }


//---------------------- DECLARAÇÃO E LEITURA DE JOGADORES -----------------//

    std::priority_queue<Jogador*, std::vector<Jogador*>, comparator_jogadores> jogadores;
    char letra;
    unsigned int indice;

    //lê posições iniciais dos jogadores
    for (unsigned int a = 0; a < k; a++){
        //por enquanto é só bullshit até eu implementar de vdd
        unsigned int i, j;
        file >> i >> j;
        letra = a + 65; //ASCII
        indice = index(i, j, m);
        jogadores.push(new Jogador(letra, indice));
    }

    file.close();


//----------------------------- PROCESSAMENTO DO JOGO -----------------------//

    Grafo g = Grafo(n, m, tabuleiro);

    Jogador* vencedor = jogar(tabuleiro, &g, &jogadores);

    if(vencedor){
        std::cout << vencedor->get_nome() << std::endl
                  << vencedor->get_ultima_rodada() << std::endl;
    } else {
        std::cout << "SEM VENCEDORES" << std::endl;
    }


//----------------------- LIBERAÇÃO DE MEMÓRIA UTILIZADA -------------------//

    for (unsigned int i = 0; i < n; i++)
        delete tabuleiro[i];
    delete tabuleiro;

    while (!jogadores.empty()){
        vencedor = jogadores.top();
        jogadores.pop();
        delete vencedor;
    }

    return 0;
}
