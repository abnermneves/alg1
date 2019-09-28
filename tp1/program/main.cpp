#include <iostream>
#include "vertice.h"
#include "grafo.h"

int main(){
  unsigned int n, m, a, b;
  Vertice* v;
  std::cin >> n >> m;
  Grafo* g = new Grafo(n, m);
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

  return 0;
}
