#include "diamantes.h"

unsigned int bruto(std::vector<unsigned int> d, unsigned int* melhor, std::vector<unsigned int>* melhorespares, std::vector<unsigned int> paresatual){
    unsigned int resultado = *melhor;
    unsigned int n = d.size();
    std::vector<unsigned int> copia;

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
            imprimir(&d);
            //std::cout << "oi2" << std::endl;
            paresatual.push_back(a);
            paresatual.push_back(b);
            resultado = bruto(d, melhor, melhorespares, paresatual);
            d.assign(copia.begin(), copia.end());
            paresatual.pop_back();
            paresatual.pop_back();
        }
    }

    if (d.size() <= 1){
        if (d.size() == 0)
            resultado = 0;
        else
            resultado = d.at(0);

        if (resultado < *melhor){
            *melhor = resultado;
            melhorespares->assign(paresatual.begin(), paresatual.end());
        }
        //std::cout << "The road so far to " << resultado << " " << *melhor << ": ";
        //imprimir(&paresatual);
    }
    return resultado;
}

unsigned int billybruto(std::vector<unsigned int>* diamantes){
    // pares vai guardar a melhor ordem dos pares a serem excluídos
    // atual vai guardar a ordem dos pares da tentativa atual
    std::vector<unsigned int> melhorespares;
    std::vector<unsigned int> paresatual;
    unsigned int melhor, atual, resultado;
    resultado = bruto(*diamantes, &melhor, &melhorespares, paresatual);
    // faz uma cópia para não alterar o vetor original
    //*d = *diamantes;
    //std::cout << "Resultado:" << resultado << std::endl;
    std::cout << "A ordem dos pares excluídos foi:" << std::endl;
    imprimir(&melhorespares);
    return melhor;

}
