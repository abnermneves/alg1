#include "diamantes.h"

void imprimir(std::vector<unsigned int>* v){
    for (auto it = v->begin(); it != v->end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
}

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

unsigned int guloso(std::vector<unsigned int>* diamantes){
    unsigned int maior, smaior, tam;
    tam = diamantes->size();
    while (tam > 1){
        if (diamantes->at(0) >= diamantes->at(1)){
            maior = 0;
            smaior = 1;
        } else {
            maior = 1;
            smaior = 0;
        }

        // encontra os dois diamantes com maiores pesos
        for (unsigned int i = 2; i < tam; i++){
            if (diamantes->at(i) > diamantes->at(maior)){
                smaior = maior;
                maior = i;
            } else if (diamantes->at(i) > diamantes->at(smaior)){
                smaior = i;
            }
        }
        //std::cout << diamantes->at(maior) << " " << diamantes->at(smaior) << std::endl;
        combinaPedras(diamantes, maior, smaior);
        tam = diamantes->size();
        //imprimir(diamantes);
    }

    if (diamantes->size() == 0)
        return 0;
    else
        return diamantes->at(0);
}
