#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>
#include <vector>
#include "vertice.h"

class Grafo {
private:
  unsigned int n; //número de vértices
  unsigned int m; //número de arestas
  bool ordTopoPronta; //diz se uma ordenação topológica já foi feita
  bool temCiclo;
  std::vector<Vertice*> vertices;
  std::list<unsigned int> ordTopologica;

public:
  Grafo();
  ~Grafo();
  void addVertice(Vertice* v);
  void addAresta(unsigned int a, unsigned int b);
  void imprimirVertices(); //imprime "(ID, idade)" de cada vértice
  void imprimirArestas(); //imprime "a b" para cada aresta do vértice a para b
  void imprimirGrafo(); //imprime os vértices e as arestas
  void DFS();
  void visitaDFS(Vertice* u, unsigned int* tempo);
  void verificaCiclo();
  void swap(unsigned int a, unsigned int b);
  void meeting();
};

#endif
