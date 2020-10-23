#include "diamantes.h"

void combinaPedras(std::vector<unsigned int>* v, unsigned int i, unsigned int j){
    //se têm o mesmo peso, apaga os dois
    if (v->at(i) == v->at(j)){
        // verificando qual tem o maior índice para apagar primeiro
        if (i > j){
            v->erase(v->begin()+i);
            v->erase(v->begin()+j);
        } else {
            v->erase(v->begin()+j);
            v->erase(v->begin()+i);
        }
    }
    // se têm pesos diferentes, apaga o menor e subtrai seu peso do maior
    else if (v->at(i) > v->at(j)){
        v->at(i) -= v->at(j);
        v->erase(v->begin()+j);
    } else {
        v->at(j) -= v->at(i);
        v->erase(v->begin()+i);
    }
}

void imprimir(std::vector<unsigned int>* v){
    for (auto it = v->begin(); it != v->end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
}
