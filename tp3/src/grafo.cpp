#include "grafo.h"

Grafo::Grafo(unsigned int n){
  this->n = n;
  this->arestas = new bool*[n^2];
  for (unsigned int i = 0; i < n^2; i++){
    this->arestas[i] = new bool[n^2];
  }
}

Grafo::~Grafo(){
  for (unsigned int i = 0; i < this->n^2; i++){
    delete[] this->arestas[i];
  }
  delete[] this->arestas;
}
