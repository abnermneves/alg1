#include "funcoes.h"

unsigned int index(int i, int j, unsigned int m){
    return (int)m*i + j;
}

bool indicesValidos(int i, int j, unsigned int n, unsigned int m){
    //se os índices estão fora do tabuleiro, retorna false
    if (i < 0 || i >= (int)n || j < 0 || j >= (int)m)
        return false;
    return true;
}
