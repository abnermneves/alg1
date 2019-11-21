#include "vertice.h"


//--------------------------------- CONSTRUTOR -------------------------------//


Vertice::Vertice(unsigned int id, unsigned int idade){
  this->id = id;
  this->idade = idade;
  this->t = 0;
  this->antecessor = 0;
  this->icmj = 0;
  this->cor = Cor::BRANCO;
}


//--------------------------------- DESTRUTOR -------------------------------//


Vertice::~Vertice(){

}


//---------------------- ADIÇÃO E REMOÇÃO DE ARESTAS ---------------------//


void Vertice::addVizinho(Vertice* v){
  this->vizinhos.push_back(v);
}

void Vertice::removeVizinho(Vertice* v){
  this->vizinhos.remove(v);
}


//-----------------------------IMPRESSÕES----------------------------------//


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


//----------------------------- INVERSÃO DE ARESTA --------------------------//


bool Vertice::inverterAresta(Vertice* v){
  Vertice* u = this;

  //se existe a aresta (u, v), inverte
  if (u->temArestaPara(v)){
    u->removeVizinho(v);
    v->addVizinho(u);
    return true;
  }

  //se existe a aresta (v, u), inverte
  else if (v->temArestaPara(u)){
    v->removeVizinho(u);
    u->addVizinho(v);
    return true;
  }
  return false;
}


//----------------------------- EXISTÊNCIA DE ARESTAS -------------------------//


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


//----------------------------- GETTERS --------------------------------------//


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

unsigned int Vertice::get_icmj(){
  return this->icmj;
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


//--------------------------------- SETTERS ----------------------------------//


void Vertice::set_t(unsigned int t){
  this->t = t;
}

void Vertice::set_antecessor(unsigned int id_antecessor){
  this->antecessor = id_antecessor;
}

void Vertice::set_cor(Cor cor){
  this->cor = cor;
}

void Vertice::set_icmj(unsigned int icmj){
  this->icmj = icmj;
}
