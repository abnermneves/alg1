#include <iostream>
#include "vertice.h"
#include "grafo.h"

int main(){
  unsigned int n, m, k, a, b;
  char c;
  Vertice* v;
  std::cin >> n >> m >> k;
  Grafo* g = new Grafo();

  //lê os n vértices
  for (unsigned int i = 0; i < n; i++){
    std::cin >> a;
    v = new Vertice(i+1, a);
    g->addVertice(v);
  }

  //lê as m arestas
  for (unsigned int i = 0; i < m; i++){
    std::cin >> a >> b;
    g->addAresta(a, b);
  }

  //lê as k instruções
  for (unsigned int i = 0; i < k; i++){
    std::cin >> c;
    switch(c){
      case 'S':
        std::cin >> a >> b;
        g->swap(a, b);
        break;
      case 'C':
        std::cin >> a;
        break;
      case 'M':
        g->meeting();
        break;
    }
  }
  //g->imprimirGrafo();
  return 0;
}
