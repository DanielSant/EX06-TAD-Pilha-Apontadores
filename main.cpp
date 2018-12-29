#include "Pilha_Apontadores.h"
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "portuguese");
    opcoes opc;
    TPilha pilha;
    TInfo item;

    cria(pilha);

    while((opc = menu(pilha)) != FIM)
    {
        switch(opc)
        {
            case EMPILHA:
                setDados(item);
                empilha(pilha, item);
                break;
            case DESEMPILHA:
                desempilha(pilha);
                break;
            case TOPO:
                topo(pilha);
                break;
            case IMPRIME:
                textcolor(GREEN);
                imprime(pilha);
                cout << "\n Aperte uma tecla to back.";
                getch();
                textcolor(WHITE);
                break;
            default:
                cout << "\n Opção inválida!\n";
                Sleep(2000);
        }
    }

    return 0;
}
