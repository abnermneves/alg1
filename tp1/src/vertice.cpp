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

void Vertice::removeVizinho(Vertice* v){
  this->vizinhos.remove(v);
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

bool Vertice::inverterAresta(Vertice* v){
  Vertice* u = this;
  //std::cout << "sera que vai inverter" << std::endl;
  if (u->temArestaPara(v)){
    //std::cout << "removeu 1" << std::endl;
    //std::cout << "Vizinhos de " << u->get_id() << ": ";
    //u->imprimirVizinhos();
    //std::cout << std::endl;
    u->removeVizinho(v);
    //std::cout << "Vizinhos de " << u->get_id() << ": ";
    //u->imprimirVizinhos();
    //std::cout << std::endl;
    //std::cout << "adicionou 1" << std::endl;
    //std::cout << "adicionou 3" << std::endl;
    v->addVizinho(u);
    return true;
  }
  else if (v->temArestaPara(u)){
    //std::cout << "removeu 2" << std::endl;
    v->removeVizinho(u);
    //std::cout << "adicionou 2" << std::endl;
    u->addVizinho(v);
    return true;
  }
  //std::cout << "nao inverteu" << std::endl;
  return false;
}

bool Vertice::temVizinhos(){
  return !this->vizinhos.empty();
}

bool Vertice::temArestaPara(Vertice* v){
  for (auto it = this->vizinhos.begin(); it != this->vizinhos.end(); it++){
    if (v == (*it))
      return true;
  }
  return false;
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

std::list<Vertice*>* Vertice::get_pointer_vizinhos(){
  return &(this->vizinhos);
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
