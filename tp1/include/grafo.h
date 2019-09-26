#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>
#include <vector>
#include "vertice.h"

class Grafo {
private:
  unsigned int n; //número de vértices
  unsigned int m; //número de arestas
  std::vector<Vertice*> vertices;

public:
  Grafo(unsigned int n, unsigned int m);
  ~Grafo();
  void addVertice(Vertice* v);
  void addAresta(unsigned int a, unsigned int b);
  void imprimirVertices();
  void imprimirArestas();
  void imprimirGrafo();
};

#endif
