#include "grafo.h"

Grafo::Grafo(){
  this->n = 0;
  this->m = 0;
  this->ordTopoPronta = false;
  this->temCiclo = false;
}

Grafo::~Grafo(){

}

Grafo* Grafo::transposto(){
  Grafo* g = this;
  Grafo* gt = new Grafo();
  Vertice* u;
  Vertice* v;

  //copia os vértices de G para Gtransposto
  for (unsigned int i = 0; i < g->n; i++){
    u = g->vertices.at(i);
    v = new Vertice(u->get_id(), u->get_idade());
    gt->addVertice(v);
  }

  //copia todas as arestas com o sentido invertido
  for (unsigned int i = 0; i < g->n; i++){
    u = g->vertices.at(i);
    std::list<Vertice*>* adj = u->get_pointer_vizinhos();

    for (auto it = adj->begin(); it != adj->end(); it++){
      v = *it;
      gt->addAresta(v->get_id(), u->get_id());
    }
  }

  return gt;
}

void Grafo::addVertice(Vertice* v){
  this->vertices.push_back(v);
  this->n++;
}

void Grafo::addAresta(unsigned int a, unsigned int b){
  this->vertices.at(a-1)->addVizinho(this->vertices.at(b-1));
  this->m++;
}

void Grafo::imprimirVertices(){
  for (unsigned int i = 0; i < this->n; i++){
    std::cout << "(" << this->vertices.at(i)->get_id()
              << ", " << this->vertices.at(i)->get_idade() << ") ";
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

void Grafo::DFS(){
  //std::cout << "oi" << std::endl;
  Vertice* x;
  unsigned int* tempo = new unsigned int(0);
  unsigned int icmj;
  //std::cout << *tempo << " " << tempo << std::endl;

  //define todos os vértices como não visitados,
  // e todos os antecessores como 0
  //pro caso de o DFS já ter sido executado
  for (unsigned int i = 0; i < this->n; i++){
    x = this->vertices.at(i);
    //std::cout << "X: ";
    //td::cout << x->get_id() << " ";
    x->set_cor(Cor::BRANCO);
    x->set_antecessor(0);
  }

  //esvazia ordTopologica, porque esse DFS sempre
  //define uma ordenação de novo
  this->ordTopologica.clear();
  this->ordTopoPronta = false;

  for (unsigned int i = 0; i < this->n; i++){
    x = this->vertices.at(i);
    icmj = x->get_idade();
    if (x->get_cor() == Cor::BRANCO){
      this->visitaDFS(x, tempo, icmj);
    }
  }

  this->ordTopoPronta = true;

  delete tempo;
}

//procedimento recursivo que visita o vértice atual e o colore de cinza
//visita cada vizinho dele recursivamente
//quando termina de visitar os vizinhos, colore de preto
//e o adiciona à ordenação topológica do grafo
void Grafo::visitaDFS(Vertice* u, unsigned int* tempo, unsigned int icmj){
  u->set_cor(Cor::CINZA);
  (*tempo)++;

  if (u->temVizinhos()){
    Vertice* v;
    //copia os vizinhos para uma lista da qual eles poderão ser apagados
    //à medida que forem visitados
    std::list<Vertice*> adj = u->get_vizinhos();

    if(u->get_idade() < icmj){
      icmj = u->get_idade();
    }

    while (!adj.empty()){
      v = adj.front();
      //std::cout << "V: " << v->get_id() << " ";
      adj.pop_front();
      //std::cout << v->get_idade() << std::endl;


      //chama visitaDFS recursivamente para o vizinho
      //se ele ainda não foi visitado
      if (v->get_cor() == Cor::BRANCO){
        v->set_antecessor(u->get_id());
        this->visitaDFS(v, tempo, icmj);
      }
      //se encontra algum vértice cinza,
      //então o grafo tem um ciclo
      else if (v->get_cor() == Cor::CINZA){
        this->temCiclo = true;
      }
    }
  }

  //quando terminar de visitar todos os vizinhos
  //colore o vértice de preto e o adiciona à ordenação topológica
  u->set_cor(Cor::PRETO);
  (*tempo)++;
  u->set_t(*tempo);
  u->set_icmj(icmj);
  this->ordTopologica.push_front(u->get_id());
}

//roda o DFS e, se chegar em algum vértice cinza,
//atualiza a variável temCiclo para TRUE
void Grafo::verificaCiclo(){
  this->DFS();
}

void Grafo::swap(unsigned int a, unsigned int b){
  Vertice* u = this->vertices.at(a-1);
  Vertice* v = this->vertices.at(b-1);
  //std::cout << "oi" << std::endl;
  bool inverteu = false;
  std::cout << "S ";

  inverteu = u->inverterAresta(v);
  //std::cout << "oi2" << std::endl;
  //se não inverteu porque a aresta não existia, termina
  if (!inverteu){
    std::cout << "N" << std::endl;
    return;
  }

  //se criou um ciclo, inverte de novo e termina
  this->verificaCiclo();
  if (this->temCiclo){
    u->inverterAresta(v);
    std::cout << "N" << std::endl;
    return;
  } else {
    //std::cout << "nao tem ciclo" << std::endl;
    std::cout << "T" << std::endl;
  }
}

void Grafo::commander(unsigned int id){
  Vertice* v = this->vertices.at(id-1);
  std::cout << "C ";
  if (v->get_icmj() == v->get_idade()){
    std::cout << "*" << std::endl;
  } else {
    std::cout << v->get_icmj() << std::endl;
  }
}

void Grafo::meeting(){
  this->DFS();

  std::cout << "M ";

  for (auto it = this->ordTopologica.begin(); it != this->ordTopologica.end(); it++){
    std::cout << (*it) << " ";
  }
  std::cout << std::endl;
}
