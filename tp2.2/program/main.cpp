#include <iostream>
#include <fstream>
#include <vector>
#include "diamantes.h"

using namespace std;

int main(int argc, char* argv[]) {

//--------------------------- FLUXO DE ARQUIVO ----------------------------//

    if (argc != 2)
        return 0;

    std::string fname;
    fname = argv[1];
    std::ifstream file(fname);

    if (!file.is_open())
        return 0;

//-------------------------- DECLARAÇÃO E LEITURA ----------------------//

    unsigned int n, d;
    file >> n;

    vector<unsigned int> diamantes;

    for (unsigned int i = 0; i < n; i++) {
        file >> d;
        diamantes.push_back(d);
    }
    imprimir(&diamantes);
    cout << guloso(&diamantes) << endl;
    return 0;
}
