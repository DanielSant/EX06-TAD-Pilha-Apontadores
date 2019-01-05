#ifndef PILHA_APONTADORES_H_INCLUDED
#define PILHA_APONTADORES_H_INCLUDED

// =----------------------------------

#include <iostream>
using namespace std;
#include <stdlib.h>
#include <conio2.h>
#include <stdio.h>
#include <windows.h>

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
opcoes menu(TPilha& pilha);
bool vazia(TPilha& pilha);
void setDados(TInfo& item);
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

opcoes menu(TPilha& pilha)
{
    int o;
    clrscr();
    imprime(pilha);
    cout << "\n Menu:" << endl
        << " 1 - Empilhar\n"
        << " 2 - Desempilhar\n"
        << " 3 - Ver Topo\n"
        << " 4 - Imprimir\n"
        << " 5 - Sair\n"
        << " Digite uma opção: ";
    scanf("%d", &o);
    fflush(stdin);
    return (opcoes) o;
}

bool vazia(TPilha& pilha)
{
    return pilha.primeiro == pilha.ultimo ? true : false;
}

void setDados(TInfo& item)
{
    cout << "\n Informe o código: ";
    cin >> item.chave;
}

void empilha(TPilha& pilha, TInfo item)
{
    apontador p = (apontador) malloc(sizeof(struct nodoPilha));
    p->item = item;
    p->proximo = pilha.primeiro->proximo;
    pilha.primeiro->proximo = p;
    if (p->proximo == NULL)
        pilha.ultimo = p;
}

void desempilha(TPilha& pilha)
{
    if(vazia(pilha))
    {
        cout << "\n ERRO: A pilha já está vazia!";
        cout << "\n Pressione uma tecla para continuar";
        getch();
    }
    else
    {
        apontador aux = pilha.primeiro->proximo;
        textcolor(RED);
        cout << "\n Elemente removido |" << aux->item.chave << "|";
        Sleep(2000);
        textcolor(WHITE);
        pilha.primeiro->proximo = aux->proximo;
        if(pilha.primeiro->proximo == NULL)
            pilha.ultimo = pilha.primeiro;
        free(aux);
    }
}

void topo(TPilha& pilha)
{
    if(vazia(pilha))
    {
        cout << "\n Não há item no topo para mostrar!";
        cout << "\n Pressione uma tecla para voltar.";
        getch();
    }
    else
    {
        apontador aux = pilha.primeiro->proximo;
        cout << "\n Elemento do TOPO:\n\n";
        textcolor(GREEN);
        cout << "\t|" << aux->item.chave << "|";
        Sleep(3000);
        textcolor(WHITE);
    }
}

void imprime(TPilha& pilha)
{
    if(vazia(pilha))
        cout << "\n Não há o que imprimir, pilha vazia!" << endl;
    else
    {
        cout << " Elementos na PILHA:\n";
        cout << endl;
        apontador aux = pilha.primeiro->proximo;
        while(aux != NULL)
        {
            cout << "\t|" << aux->item.chave << "|" << endl;
            aux = aux->proximo;
        }
        cout << " |===============|\n";
    }
}

#endif // PILHA_APONTADORES_H_INCLUDED
