#include "diamantes.h"

void imprimir(std::vector<unsigned int>* v){
    for (auto it = v->begin(); it != v->end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
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
        std::cout << diamantes->at(maior) << " " << diamantes->at(smaior) << std::endl;
        // se os dois têm o mesmo peso, apaga os dois
        if (diamantes->at(maior) == diamantes->at(smaior)){
            // verificando qual tem o maior índice para apagar primeiro
            if (maior > smaior){
                diamantes->erase(diamantes->begin()+maior);
                diamantes->erase(diamantes->begin()+smaior);
            } else {
                diamantes->erase(diamantes->begin()+smaior);
                diamantes->erase(diamantes->begin()+maior);
            }
            tam -= 2;
        }
        // se têm pesos diferentes, apaga o menor e subtrai seu peso do maior
        else {
            diamantes->at(maior) -= diamantes->at(smaior);
            diamantes->erase(diamantes->begin()+smaior);
            tam--;
        }
        imprimir(diamantes);
    }

    return diamantes->size();
}
