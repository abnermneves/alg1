#include "grafo.h"

Grafo::Grafo(unsigned int n, unsigned int m){
  this->n = n;
  this->m = m;
}

Grafo::~Grafo(){

}

void Grafo::addVertice(Vertice* v){
  this->vertices.push_back(v);
}

void Grafo::addAresta(unsigned int a, unsigned int b){
  this->vertices.at(a-1)->addVizinho(this->vertices.at(b-1));
}

void Grafo::imprimirVertices(){
  for (unsigned int i = 0; i < this->n; i++){
    std::cout << this->vertices.at(i) << " ";
  }
  std::cout << std::endl;
}

void Grafo::imprimirArestas(){
  for (unsigned int i = 0; i < this->n; i++){
    this->vertices.at(i)->imprimirArestas();
  }
  std::cout << std::endl;
}

void Grafo::imprimirGrafo(){
  this->imprimirVertices();
  this->imprimirArestas();
}
