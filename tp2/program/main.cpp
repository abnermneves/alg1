#include <fstream>
#include "include.h"

int main(int argc, char* argv[]){
  unsigned int n, m, d, p;
  std::vector<unsigned int> custo, pontos;

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
      }

      file.close();
    }

    knapsack_dynamic(n, m, &custo, &pontos);

  return 0;
}
