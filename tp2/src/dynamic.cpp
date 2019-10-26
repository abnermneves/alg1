#include "include.h"

void knapsack_dynamic(unsigned int W, unsigned int n,
                      std::vector<unsigned int>* custo,
                      std::vector<unsigned int>* pontos){

  //inicializa matrizes que guardarão a melhor solução para cada peso
  //e a quantidade de dias para cada solução
  unsigned int best[n+1][W+1];
  unsigned int dias[n+1][W+1];
  for (unsigned int w = 0; w <= W; w++){
    best[0][w] = 0;
    dias[0][w] = 0;
  }

  //percorre a matriz preenchendo a melhor solução para cada orçamento
  //considerando uma ilha a mais por vez
  for (unsigned int i = 1; i <= n; i++){
    for (unsigned int w = 0; w <= W; w++){
      //se o custo da nova ilha for maior que o orçamento total
      //então ela nem é considerada e a melhor solução é a mesma que a anterior
      if (custo->at(i) > w){
        best[i][w] = best[i-1][w];
        dias[i][w] = dias[i-1][w];
      }

      //se a nova ilha não exceder o orçamento, então compara qual solução é melhor:
      //a que considera apenas as ilhas anteriores ou a que acrescenta essa nova ilha
      //à melhor solução para o restante do dinheiro
      else {
        if (best[i-1][w] > pontos->at(i) + best[i-1][w-custo->at(i)]){
          best[i][w] = best[i-1][w];
          dias[i][w] = dias[i-1][w];
        } else {
          best[i][w] = pontos->at(i) + best[i-1][w-custo->at(i)];
          dias[i][w] = 1 + dias[i-1][w-custo->at(i)];
        }
        //se as duas alternativas têm o mesmo peso e custo, acaba priorizando
        //visitar outra ilha / eu acho / tem que ver melhor
      }
    }
  }

  /*
  //imprime a matriz toda
  for (unsigned int i = 0; i <= n; i++){
    for (unsigned int j = 0; j <= W; j++){
      std::cout << best[i][j] << " ";
    }
    std::cout << std::endl;
  }
  */
  std::cout << best[n][W] << " " << dias[n][W] << std::endl;
}
