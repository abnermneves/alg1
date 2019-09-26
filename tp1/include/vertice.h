#ifndef VERTICE_H
#define VERTICE_H

#include <iostream>
#include <list>

class Vertice{
private:
  unsigned int id;
  unsigned int idade;
  unsigned int t; //tempo de término do DFS
  std::list<Vertice*> vizinhos; //lista de vértices adjacentes
public:
  Vertice(unsigned int id, unsigned int idade);
  ~Vertice();
  void addVizinho(Vertice* v);
  void imprimirVizinhos(); //imprime os vizinhos a, b, c, ... do vértice v
  void imprimirArestas(); //imprime as arestas v a, v b, v c, ... do vértice v

  unsigned int get_id();
  unsigned int get_idade();
  unsigned int get_t();
};

#endif
