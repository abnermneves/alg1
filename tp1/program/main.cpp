#include <iostream>
#include <fstream>
#include <string>
#include "vertice.h"
#include "grafo.h"

int main(int argc, char* argv[]){
  unsigned int n, m, k, a, b;
  char c;
  Vertice* v;
  Grafo* g = new Grafo();

  //se foi executado com um parâmetro, lê do arquivo
  if (argc == 2){
    std::string line, fname;
    fname = argv[1];

    std::ifstream file(fname);
    if (file.is_open()){
      file >> n >> m >> k;
      
      //lê os n vértices
      for (unsigned int i = 0; i < n; i++){
        file >> a;
        v = new Vertice(i+1, a);
        g->addVertice(v);
      }

      //lê as m arestas
      for (unsigned int i = 0; i < m; i++){
        file >> a >> b;
        g->addAresta(a, b);
      }

      //lê as k instruções
      for (unsigned int i = 0; i < k; i++){
        file >> c;
        switch(c){
          case 'S':
            file >> a >> b;
            g->swap(a, b);
            break;
          case 'C':
            file >> a;
            g->commander(a);
            break;
          case 'M':
            g->meeting();
            break;
        }
      }

      file.close();
    }
  }
  return 0;
}
