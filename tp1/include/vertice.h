#ifndef VERTICE_H
#define VERTICE_H

#include <iostream>
#include <list>

//cores para o DFS, que significam
//não explorado, explorando, explorado, respectivamente
enum Cor {BRANCO, CINZA, PRETO};

class Vertice{
private:
  unsigned int id;
  unsigned int idade;
  unsigned int t; //tempo de término do DFS
  unsigned int antecessor; //id do vértice anterior; 0 é default
  Cor cor;
  std::list<Vertice*> vizinhos; //lista de vértices adjacentes
public:
  Vertice(unsigned int id, unsigned int idade);
  ~Vertice();
  void addVizinho(Vertice* v);
  void removeVizinho(Vertice* v);
  void imprimirVizinhos(); //imprime os vizinhos a, b, c, ... do vértice v
  void imprimirArestas(); //imprime as arestas v a, v b, v c, ... do vértice v
  bool inverterAresta(Vertice* v); //inverte se existe uma aresta (u, v) ou (v, u)
  bool temVizinhos();
  bool temArestaPara(Vertice* v);
  unsigned int get_id();
  unsigned int get_idade();
  unsigned int get_t();
  unsigned int get_antecessor();
  std::list<Vertice*> get_vizinhos();
  std::list<Vertice*>* get_pointer_vizinhos();
  Cor get_cor();

  void set_t(unsigned int t);
  void set_antecessor(unsigned int id_antecessor);
  void set_cor(Cor cor);
};

#endif
