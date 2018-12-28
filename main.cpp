#include "Pilha_Apontadores.h"
#include <locale.h>
#include <windows.h>

int main()
{
    setlocale(LC_ALL, "portuguese");
    opcoes opc;

    while((opc = menu()) != FIM)
    {
        switch(opc)
        {
            case EMPILHA:
                //empilha();
                break;
            case DESEMPILHA:
                //desempilha();
                break;
            case TOPO:
                //topo();
                break;
            case IMPRIME:
                //imprime();
                break;
            default:
                cout << "\n Opção inválida!\n";
                Sleep(2000);
        }
    }

    return 0;
}
