#include <stdio.h>
#include <stdlib.h>
#include "Vendas.h"

void MenuPrincipal()
{
        printf("\n|======MENU======|");
        printf("\n| [1] PRODUTO           |");
        printf("\n| [2] CLIENTE              |");
        printf("\n| [3] VENDAS               |");
        printf("\n| [4] SAIR                     |");
        printf("\n|==================|");
}

void SubMenuProduto(TModuloProduto *modulo, TProdutos produto)
{
    printf("\n|====MODULO PRODUTO==== |");
    printf("\n| [1] INSERIR                              |");
    printf("\n| [2] PESQUISAR                        |");
    printf("\n| [3] ALTERAR                            |");
    printf("\n| [4] EXCLUIR                             |");
    printf("\n| [5] SAIR                                    |");
    printf("\n|=========================|");
}
