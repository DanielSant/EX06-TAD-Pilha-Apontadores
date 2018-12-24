#ifndef PILHA_APONTADORES_H_INCLUDED
#define PILHA_APONTADORES_H_INCLUDED

#include <iostream>
using namespace std;

typedef struct nodoPilha *apontador;

typedef struct {
    int chave;
    /*outros componentes*/
} TInfo;

struct nodoPilha {
    TInfo item;
    struct nodoPilha *proximo;
};

typedef struct {
    struct nodoPilha *primeiro;
    struct nodoPilha *ultimo;
} TPilha;

#endif // PILHA_APONTADORES_H_INCLUDED
