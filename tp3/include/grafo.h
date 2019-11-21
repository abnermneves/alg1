#ifndef GRAFO_H
#define GRAFO_H

#include <vector>
#include "vertice.h"

class Grafo {
private:
  unsigned int n;
  std::vector<unsigned int> vertices; //n^2 vértices no total, armazena a cor
  bool** arestas; //n^4 possíveis arestas
public:
  Grafo(unsigned int n);
  ~Grafo();
};

#endif
