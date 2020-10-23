#include "diamantes.h"

unsigned int bruto(std::vector<unsigned int> d, unsigned int* melhor,
                   std::vector<unsigned int>* melhorespares,
                   std::vector<unsigned int> paresatual){

    unsigned int resultado = *melhor;
    std::vector<unsigned int> copia;

    // testa todas possibilidades de ordens de exclusão dos pares
    for (unsigned int a = 0; a < d.size(); a++){
        for (unsigned int b = a+1; b < d.size(); b++){
            // faz uma cópia do vetor antes de combinar as pedras
            copia.assign(d.begin(), d.end());
            
            combinaPedras(&d, a, b);

            // para um eventual backtracking
            paresatual.push_back(a);
            paresatual.push_back(b);

            resultado = bruto(d, melhor, melhorespares, paresatual);

            // restaura o vetor ao que era antes de combinar o par
            d.assign(copia.begin(), copia.end());
            paresatual.pop_back();
            paresatual.pop_back();
        }
    }

    if (d.size() <= 1){
        if (d.size() == 0) // se sobrou nenhuma pedra, o resultado é 0
            resultado = 0;
        else // ou, se sobrou uma, o resultado é seu peso
            resultado = d.at(0);

        // atualiza o melhor resultado dentre todos
        if (resultado < *melhor){
            *melhor = resultado;
            melhorespares->assign(paresatual.begin(), paresatual.end());
        }
        //std::cout << "The road so far: " << *melhor << ": ";
        //imprimir(&paresatual);
    }
    return resultado;
}

unsigned int billybruto(std::vector<unsigned int>* diamantes){
    // pares vai guardar a melhor ordem dos pares a serem excluídos
    // atual vai guardar a ordem dos pares da tentativa atual
    std::vector<unsigned int> melhorespares;
    std::vector<unsigned int> paresatual;
    unsigned int melhor;
    bruto(*diamantes, &melhor, &melhorespares, paresatual);
    // std::cout << "A ordem dos pares excluídos foi:" << std::endl;
    // imprimir(&melhorespares);
    return melhor;

}
