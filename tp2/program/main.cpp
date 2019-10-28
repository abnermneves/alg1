#include <fstream>
#include <time.h>
#include "include.h"

int main(int argc, char* argv[]){
  unsigned int n, m, d, p;
  std::vector<unsigned int> custo, pontos;
  custo.push_back(0);
  pontos.push_back(0);

  /*
  clock_t tempoInicialGreedy;
  clock_t tempoInicialDynamic;
  clock_t tempoFinalGreedy;
  clock_t tempoFinalDynamic;
  */

  //se foi executado com um parâmetro, lê do arquivo
  if (argc == 2){
    std::string line, fname;
    fname = argv[1];

    std::ifstream file(fname);
    if (file.is_open()){
        file >> n >> m;

        //lê o custo e pontuação das m ilhas
        for (unsigned int i = 0; i < m; i++){
          file >> d >> p;
          custo.push_back(d);
          pontos.push_back(p);
        }

      file.close();

      //tempoInicialGreedy = clock();
      knapsack_greedy(n, m, &custo, &pontos);
      //tempoFinalGreedy = clock();

      //tempoInicialDynamic = clock();
      knapsack_dynamic(n, m, &custo, &pontos);
      //tempoFinalDynamic = clock();

      /*
      std::cout << (tempoFinalGreedy - tempoInicialGreedy) * 1000.0 / CLOCKS_PER_SEC
                << std::endl;
      std::cout << (tempoFinalDynamic - tempoInicialDynamic) * 1000.0 / CLOCKS_PER_SEC
                << std::endl;
      */

    } else {
      std::cout << "Arquivo inválido!" << std::endl;
    }
  }

  return 0;
}
