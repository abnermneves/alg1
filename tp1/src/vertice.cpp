#include "vertice.h"

Vertice::Vertice(unsigned int id, unsigned int idade){
  this->id = id;
  this->idade = idade;
  this->t = 0;
  this->antecessor = 0;
  this->cor = Cor::BRANCO;
}

Vertice::~Vertice(){

}

void Vertice::addVizinho(Vertice* v){
  this->vizinhos.push_back(v);
}

void Vertice::imprimirVizinhos(){
  std::list<Vertice*>::iterator it = this->vizinhos.begin();
  for (; it != this->vizinhos.end(); it++){
    std::cout << (*it)->get_id() << " ";
  }
}

void Vertice::imprimirArestas(){
  std::list<Vertice*>::iterator it = this->vizinhos.begin();
  for (; it != this->vizinhos.end(); it++){
    std::cout << this->id << " " << (*it)->get_id() << std::endl;
  }
}

bool Vertice::temVizinhos(){
  return !this->vizinhos.empty();
}

unsigned int Vertice::get_id(){
  return this->id;
}

unsigned int Vertice::get_idade(){
  return this->idade;
}

unsigned int Vertice::get_t(){
  return this->t;
}

unsigned int Vertice::get_antecessor(){
  return this->antecessor;
}

std::list<Vertice*> Vertice::get_vizinhos(){
  return this->vizinhos;
}

Cor Vertice::get_cor(){
  return this->cor;
}

void Vertice::set_t(unsigned int t){
  this->t = t;
}

void Vertice::set_antecessor(unsigned int id_antecessor){
  this->antecessor = id_antecessor;
}

void Vertice::set_cor(Cor cor){
  this->cor = cor;
}
