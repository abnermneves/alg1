#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>
#include <cmath>
#include "diamantes.h"

using namespace std;

int main(int argc, char* argv[]) {

//--------------------------- FLUXO DE ARQUIVO ----------------------------//

    if (argc < 2)
        return 0;

    std::string fname;
    fname = argv[1];
    std::ifstream file(fname);

    if (!file.is_open())
        return 0;

//-------------------------- DECLARAÇÃO E LEITURA ----------------------//

    unsigned int n, d, resultado;
    file >> n;

    vector<unsigned int> diamantes;

    for (unsigned int i = 0; i < n; i++) {
        file >> d;
        diamantes.push_back(d);
    }

//------------------------------- EXECUÇÃO ------------------------------//

    string tempo = "tempo";
    if ((argc > 2) && (tempo.compare(argv[2]) == 0)){
        chrono::high_resolution_clock::time_point start, end;

        //marca o horário antes e depois da execução
        start = chrono::high_resolution_clock::now();
        resultado = powerpuffdynamo(&diamantes);
        end = chrono::high_resolution_clock::now();

        //calcula a diferença do tempo de fim e início
        chrono::duration<double, micro> elapsed_time
        = chrono::duration_cast<chrono::duration<double>>(end - start);
        cout << resultado << endl << "Tempo de execução: " << elapsed_time.count() << endl;

    } else {
        //resultado = billybruto(&diamantes);
        resultado = powerpuffdynamo(&diamantes);
        cout << resultado << endl;
    }


    return 0;
}
