#include "diamantes.h"

unsigned int guloso(std::vector<unsigned int>* diamantes){
    unsigned int maior, smaior, tam;
    tam = diamantes->size();

    while (tam > 1){

        // começa com os dois primeiros diamantes
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

        combinaPedras(diamantes, maior, smaior);
        tam = diamantes->size();
    }

    if (diamantes->size() == 0)
        return 0;
    else
        return diamantes->at(0);
}
