#include <iostream>
#include "vertice.h"
#include "grafo.h"

int main(){
  unsigned int n, m, a, b;
  Vertice* v;
  std::cin >> n >> m;
  Grafo* g = new Grafo();
  for (unsigned int i = 0; i < n; i++){
    std::cin >> a;
    v = new Vertice(i+1, a);
    g->addVertice(v);
  }
  for (unsigned int i = 0; i < m; i++){
    std::cin >> a >> b;
    g->addAresta(a, b);
  }

  g->meeting();
  g->swap(4, 2);
  g->swap(3, 6);
  g->swap(4, 7);
  g->imprimirGrafo();
  return 0;
}
