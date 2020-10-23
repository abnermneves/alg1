#include "diamantes.h"
#include <algorithm>

unsigned int dinamico(std::vector<unsigned int> d,
                    unsigned int* hits, unsigned int* misses,
                    std::vector<std::vector<unsigned int>>* memo,
                    std::vector<int>* resultados, unsigned int* melhor,
                    std::vector<unsigned int>* melhorespares,
                    std::vector<unsigned int> paresatual){

    // se sobrou 0 pedras, atualiza o resultado geral
    if (d.size() == 0){
        if (0 < *melhor){
            *melhor = 0;
            melhorespares->assign(paresatual.begin(), paresatual.end());
        }
        return 0;
    }

    // ordena o vetor antes de procurá-lo na memória
    std::sort(d.begin(), d.end());

    // verifica se esse vetor de pesos já foi resolvido
    // e, caso positivo, retorna o resultado
    for (unsigned int i = 0; i < memo->size(); i++){
        if (d == memo->at(i)){
            (*hits)++;
            return resultados->at(i);
        }
    }

    // se ainda não foi resolvido, então continua o processo
    (*misses)++;
    unsigned int resultado = *melhor;
    std::vector<unsigned int> copia;

    // posição do array atual na memória
    unsigned int pos = memo->size();
    memo->push_back(d);
    resultados->push_back(-1);

    // testa todas as possibilidades de ordem de exclusão dos pares de pedras
    for (unsigned int a = 0; a < d.size(); a++){
        for (unsigned int b = a+1; b < d.size(); b++){
            // mantém uma cópia do vetor antes de combinar o par
            copia.assign(d.begin(), d.end());

            combinaPedras(&d, a, b);

            // mantém um histórico dos pares excluídos para um eventual backtracking
            paresatual.push_back(a);
            paresatual.push_back(b);

            resultado = dinamico(d, hits, misses, memo, resultados, melhor, melhorespares, paresatual);

            // armazena a solução na memória
            if (resultados->at(pos) == -1 || resultado < resultados->at(pos)){
                resultados->at(pos) = resultado;
            }

            // restaura o vetor ao que era antes de combinar as pedras
            d.assign(copia.begin(), copia.end());
            paresatual.pop_back();
            paresatual.pop_back();

        }
    }

    // se sobrou apenas uma pedra, atualiza o resultado
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
    std::vector<int> resultados;
    unsigned int melhor, hits, misses;

    // quantidade de vezes que o algoritmo evitou e não evitou
    // de processar novamente um mesmo vetor
    hits = 0;
    misses = 0;

    dinamico(*diamantes, &hits, &misses, &memo, &resultados, &melhor, &melhorespares, paresatual);

    melhor = resultados.at(0);

    return melhor;

}
