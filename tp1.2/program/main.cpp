#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <map>
#include "grafo.h"
#include "funcoes.h"

int main(int argc, char* argv[]) {
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

    //------------------ DECLARAÇÃO E LEITURA DE JOGADORES -----------------//

    std::map<char, unsigned int> jogadores;
    char letra;
    unsigned int indice;
    //lê posições iniciais dos jogadores
    for (unsigned int a = 0; a < k; a++){
        //por enquanto é só bullshit até eu implementar de vdd
        unsigned int i, j;
        file >> i >> j;
        letra = a + 65; //ASCII
        indice = index(i, j, m);
        jogadores.insert(std::pair<char, unsigned int>(letra, indice));
    }

    file.close();


    //imprime tabuleiro
    for (unsigned int i = 0; i < n; i++){
        for (unsigned int j = 0; j < m; j++){
            std::cout << tabuleiro[i][j] << " ";
        }
        std::cout << std::endl;
    }

    //imprime jogadores
    for (auto it = jogadores.begin(); it != jogadores.end(); it++){
        std::cout << it->first << " " << it->second << std::endl;
    }

    Grafo g = Grafo(n, m, tabuleiro);
    g.imprimir();

    return 0;
}
