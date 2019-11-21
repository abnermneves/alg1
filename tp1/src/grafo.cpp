#include "grafo.h"


//--------------------------------- CONSTRUTOR -------------------------------//


Grafo::Grafo(){
  this->n = 0;
  this->m = 0;
  this->ordTopoPronta = false;
  this->temCiclo = false;
}


//-------------------------------- DESTRUTOR ----------------------------------//


Grafo::~Grafo(){
  for (auto it = this->vertices.begin(); it != this->vertices.end(); it++){
    delete *it;
  }
}


//---------------------------------- TRANSPOSIÇÃO ---------------------------//


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

//---------------------- ADIÇÃO DE VÉRTICES E ARESTAS ---------------------//

void Grafo::addVertice(Vertice* v){
  this->vertices.push_back(v);
  this->n++;
}

void Grafo::addAresta(unsigned int a, unsigned int b){
  this->vertices.at(a-1)->addVizinho(this->vertices.at(b-1));
  this->m++;
}


//-----------------------------IMPRESSÕES----------------------------------//


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


//------------------------------- DFS -------------------------------------//


void Grafo::DFS(){
  Vertice* x;
  unsigned int* tempo = new unsigned int(0);

  //define todos os vértices como não visitados,
  // e todos os antecessores como 0
  //pro caso de o DFS já ter sido executado
  for (unsigned int i = 0; i < this->n; i++){
    x = this->vertices.at(i);
    x->set_cor(Cor::BRANCO);
    x->set_antecessor(0);
  }

  //esvazia ordTopologica, porque esse DFS sempre
  //define uma ordenação de novo
  this->ordTopologica.clear();
  this->ordTopoPronta = false;

  //visita todos os vértices que ainda não foram visitados
  for (unsigned int i = 0; i < this->n; i++){
    x = this->vertices.at(i);
    if (x->get_cor() == Cor::BRANCO){
      this->visitaDFS(x, tempo);
    }
  }

  this->ordTopoPronta = true;

  delete tempo;
}

//procedimento recursivo que visita o vértice atual e o colore de cinza
//visita cada vizinho dele recursivamente
//quando termina de visitar os vizinhos, colore de preto
//e o adiciona à ordenação topológica do grafo
void Grafo::visitaDFS(Vertice* u, unsigned int* tempo){
  u->set_cor(Cor::CINZA);
  (*tempo)++;

  if (u->temVizinhos()){
    Vertice* v;
    //copia os vizinhos para uma lista da qual eles poderão ser apagados
    //à medida que forem visitados
    std::list<Vertice*> adj = u->get_vizinhos();

    while (!adj.empty()){
      v = adj.front();
      adj.pop_front();

      //chama visitaDFS recursivamente para o vizinho
      //se ele ainda não foi visitado
      if (v->get_cor() == Cor::BRANCO){
        v->set_antecessor(u->get_id());
        this->visitaDFS(v, tempo);
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
  this->ordTopologica.push_front(u->get_id());
}


//------------------------------ VERIFICAÇÃO DE CICLO -----------------------//


//roda o DFS e, se chegar em algum vértice cinza,
//atualiza a variável temCiclo para TRUE
void Grafo::verificaCiclo(){
  this->DFS();
}


//------------------------------------ SWAP ---------------------------------//


void Grafo::swap(unsigned int a, unsigned int b){
  Vertice* u = this->vertices.at(a-1);
  Vertice* v = this->vertices.at(b-1);
  bool inverteu = false;
  std::cout << "S ";

  inverteu = u->inverterAresta(v);

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
    std::cout << "T" << std::endl;
  }
}


//-------------------------------- COMMANDER ----------------------------//


//transpõe o grafo e percorre os descendentes do vértice de interesse
//comparando as idades e armazenando a menor
//pois os descendentes em G transposto são os ascendetes em G
void Grafo::commander(unsigned int id){
  Grafo* gt = this->transposto();
  Vertice* x = gt->vertices.at(id-1);
  unsigned int* icmj = new unsigned int(0);

  if (x->temVizinhos()){
    //copia a lista de vizinhos para poder apagar os já visitados
    auto ascendentes = x->get_vizinhos();

    //determina a idade do primeiro ascendente como icmj
    //(icmj = idade do comandante mais jovem)
    Vertice* v = ascendentes.front();
    ascendentes.pop_front();
    *icmj = v->get_idade();

    //chama a função recursiva visitaCommander para todos os ascendentes de x
    //função inspirada na visitaDFS
    while(!ascendentes.empty()){
      v = ascendentes.front();
      ascendentes.pop_front();
      this->visitaCommander(v, icmj);
    }

    gt->~Grafo();
  }

  //depois de visitados todos os vizinhos
  //e todos os vizinhos dos vizinhos, define o icmj
  x->set_icmj(*icmj);

  std::cout << "C ";
  if (x->get_icmj() == 0){
     std::cout << "*" << std::endl;
  } else {
     std::cout << x->get_icmj() << std::endl;
  }
  delete icmj;
}

//função recursiva inspirada na visitaDFS
//visita todos os ascendentes diretos e indiretos de um vértice
void Grafo::visitaCommander(Vertice* u, unsigned int* icmj){
  if (u->get_idade() < *icmj){
    *icmj = u->get_idade();
  }
  std::list<Vertice*> adj = u->get_vizinhos();
  Vertice* v;

  while (!adj.empty()){
    v = adj.front();
    adj.pop_front();
    this->visitaCommander(v, icmj);
  }
}

//------------------------------------ MEETING ----------------------------//

//encontrar a ordem hierárquica desejada
//equivale a encontrar uma ordenação topológica do grafo
void Grafo::meeting(){
  //a DFS implementada já define uma ordenação topológica
  //durante o processo, então é só chamá-la
  this->DFS();

  std::cout << "M ";

  //e retornar a lista gerada
  for (auto it = this->ordTopologica.begin(); it != this->ordTopologica.end(); it++){
    std::cout << (*it) << " ";
  }
  std::cout << std::endl;
}
