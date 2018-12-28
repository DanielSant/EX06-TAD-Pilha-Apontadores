#ifndef PILHA_APONTADORES_H_INCLUDED
#define PILHA_APONTADORES_H_INCLUDED

// =----------------------------------

#include <iostream>
using namespace std;
#include <stdlib.h>
#include <conio2.h>
#include <stdio.h>

// =----------------------------------

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

enum opcoes
{
    CRIA, EMPILHA, DESEMPILHA,
    TOPO, IMPRIME, FIM
};

// =----------------------------------

void cria(TPilha& pilha);
opcoes menu();
bool vazia(TPilha& pilha);
void empilha(TPilha& pilha, TInfo item);
void desempilha(TPilha& pilha);
void topo(TPilha& pilha);
void imprime(TPilha& pilha);

// =----------------------------------

void cria(TPilha& pilha)
{
    pilha.primeiro = (apontador) malloc(sizeof(struct nodoPilha));
    pilha.ultimo = pilha.primeiro;
    pilha.primeiro->proximo = NULL;
}

opcoes menu()
{
    int o;
    clrscr();
    cout << "\n Menu:" << endl
        << " 1 - Empilhar\n"
        << " 2 - Desempilhar\n"
        << " 3 - Ver Topo\n"
        << " 4 - Imprimir\n"
        << " 5 - Sair\n"
        << " Digite uma opção: ";
    scanf("%d", &o);
    //fflush(stdin);
    return (opcoes) o;
}

#endif // PILHA_APONTADORES_H_INCLUDED
