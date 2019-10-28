#include "include.h"
#include <cmath>
#include <map>

void knapsack_greedy(unsigned int W, unsigned int m,
                     std::vector<unsigned int>* custo,
                     std::vector<unsigned int>* pontos){

  //multimap para armazenar a razão pontuação/custo de cada ilha
  std::multimap<float, unsigned int> pc;

  //calcula as razões mencionadas acima
  for (unsigned int i = 0; i <= m; i++){
    float razao = float(pontos->at(i))/float(custo->at(i));
    pc.insert(std::pair<float, unsigned int>(razao, i));
  }

  unsigned int w = W;
  unsigned int dias = 0;
  unsigned int pontuacao = 0;
  unsigned int repeticoes = 0;

  //percorre o map do final para o início
  //pois ele está em ordem crescente de razão pontos/custo
  auto it = pc.end();
  for (it--; it != pc.begin() && w > 0; it--){
    //divide o orçamento restante pelo custo da diária na ilha
    //para saber quantos dias ainda é possível ficar nela
    repeticoes = 0;
    repeticoes = std::floor(w/custo->at(it->second));
    dias += repeticoes;

    //multiplica custo e pontos da ilha pelo número de dias repetidos
    //subtrai do peso restante e soma na pontuação total
    w -= custo->at(it->second)*repeticoes;
    pontuacao += pontos->at(it->second)*repeticoes;
  }

  std::cout << pontuacao << " " << dias << std::endl;
}
