#include "include.h"

void knapsack_dynamic(unsigned int n, unsigned int m,
                      std::vector<unsigned int>* custo,
                      std::vector<unsigned int>* pontos){
  //inicializa vetor que guardará a melhor solução para cada peso
  std::vector<std::vector<unsigned int>> best;


  for (unsigned int i = 0; i < m; i++){
    for (unsigned int c = 0; c <= n; c++){
      if (custo->at(i) > n){
        //best[]
      }
    }
  }

  for (unsigned int i = 0; i < n; i++){
    //std::cout << best.at(0).at(i) << " ";
  }

  std::cout << std::endl;
}
