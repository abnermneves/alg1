#include "diamantes.h"
#include <algorithm>

unsigned int dinamico(std::vector<unsigned int> d,
                    unsigned int* hits, unsigned int* misses,
                    std::vector<std::vector<unsigned int>>* memo,
                    std::vector<int>* resultados, unsigned int* melhor,
                    std::vector<unsigned int>* melhorespares,
                    std::vector<unsigned int> paresatual){

    if (d.size() == 0){
        if (0 < *melhor){
            *melhor = 0;
            melhorespares->assign(paresatual.begin(), paresatual.end());
        }
        return 0;
    }

    std::sort(d.begin(), d.end());
    for (unsigned int i = 0; i < memo->size(); i++){
        if (d == memo->at(i)){
            (*hits)++;
            return resultados->at(i);
        }
    }
    (*misses)++;
    unsigned int resultado = *melhor;
    std::vector<unsigned int> copia;

    // posição do array atual na memória
    unsigned int pos = memo->size();
    memo->push_back(d);
    resultados->push_back(-1);

    for (unsigned int a = 0; a < d.size(); a++){
    //std::cout << "oi3" << std::endl;
        for (unsigned int b = a+1; b < d.size(); b++){
            //std::cout << "oi4" << std::endl;//std::vector<unsigned int> paresatual;
            //imprimir(&d);
            //std::cout << "oi1" << std::endl;
            //paresatual->push_back(i);
            //paresatual->push_back(j);
            //std::cout << a << " " << b << std::endl;
            copia.assign(d.begin(), d.end());
            combinaPedras(&d, a, b);
            std::cout << "Vetor " << pos << " de tamanho " << d.size() << ": ";
            imprimir(&d);
            //std::cout << "oi2" << std::endl;
            paresatual.push_back(a);
            paresatual.push_back(b);
            resultado = dinamico(d, hits, misses, memo, resultados, melhor, melhorespares, paresatual);
            d.assign(copia.begin(), copia.end());

            if (resultados->at(pos) == -1 || resultado < resultados->at(pos)){
                resultados->at(pos) = resultado;
            }

            paresatual.pop_back();
            paresatual.pop_back();
        }
    }

    if (d.size() == 1){
        resultado = d.at(0);
        resultados->at(pos) = resultado;

        if (resultado < *melhor){
            *melhor = resultado;
            melhorespares->assign(paresatual.begin(), paresatual.end());
        }
        //std::cout << "The road so far to " << resultado << " " << *melhor << ": ";
        //imprimir(&paresatual);
    }
    return resultado;
}

unsigned int powerpuffdynamo(std::vector<unsigned int>* diamantes){
    // pares vai guardar a melhor ordem dos pares a serem excluídos
    // atual vai guardar a ordem dos pares da tentativa atual
    std::vector<unsigned int> melhorespares;
    std::vector<unsigned int> paresatual;
    std::vector<std::vector<unsigned int>> memo;
    std::vector<int> resultados, as, bes;
    unsigned int melhor, atual, resultado, hits, misses;
    hits = 0;
    misses = 0;
    resultado = dinamico(*diamantes, &hits, &misses, &memo, &resultados, &melhor, &melhorespares, paresatual);
    // faz uma cópia para não alterar o vetor original
    //*d = *diamantes;
    //std::cout << "Resultado:" << resultado << std::endl;
    //std::cout << "A ordem dos pares excluídos foi:" << std::endl;
    //imprimir(&melhorespares);

    for (unsigned int i = 0; i < memo.size(); i++){
        std::cout << "----------------------------------------------------" << std::endl;
        std::cout << "Vetor " << i << ": " << resultados.at(i) << std::endl;
        imprimir(&memo.at(i));
        std::cout << "----------------------------------------------------" << std::endl;
    }
    std::cout << "Hits: " << hits << std::endl << "Misses: " << misses << std::endl;
    melhor = resultados.at(0);
    return melhor;

}
