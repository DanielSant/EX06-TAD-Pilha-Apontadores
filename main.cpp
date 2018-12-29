#include "Pilha_Apontadores.h"
#include <locale.h>
#include <windows.h>

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
                //desempilha();
                break;
            case TOPO:
                //topo();
                break;
            case IMPRIME:
                imprime(pilha);
                break;
            default:
                cout << "\n Opção inválida!\n";
                Sleep(2000);
        }
    }

    return 0;
}
