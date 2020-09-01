#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 2)
        return 0;

    string fname;
    fname = argv[1];
    ifstream file(fname);

    if (!file.is_open())
        return 0;

    //dimensões do tabuleiro nxm e quantidade k de jogadores
    unsigned int n, m, k;
    file >> n >> m >> k;

    //cria tabuleiro com valores da entrada
    unsigned int tabuleiro[n][m];
    for (unsigned int i = 0; i < n; i++){
        for (unsigned int j = 0; j < m; j++){
            file >> tabuleiro[i][j];
        }
    }

    //lê posições iniciais dos jogadores
    for (unsigned int a = 0; a < k; a++){
        //por enquanto é só bullshit até eu implementar de vdd
        unsigned int i, j;
        file >> i >> j;
    }

    file.close();

    //imprime tabuleiro
    for (unsigned int i = 0; i < n; i++){
        for (unsigned int j = 0; j < m; j++){
            cout << tabuleiro[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
