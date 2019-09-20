#include <stdio.h>
#include <stdlib.h>
#include "Vendas.h"
#include "Menu.h"


int main()
{
    //Declaração auxiliares
    TClientes cliente1;
    TProdutos produto1;
    TVendas venda1;
    TModuloProduto modulo1;
    TModuloCliente modulo2;
    TModuloVendas modulo3;

    //Inicialização
    IniciarModuloProduto(&modulo1);
    IniciarModuloCliente(&modulo2);
    IniciarModuloVendas(&modulo3);

    MenuPrincipal(&modulo1, produto1, &modulo2, cliente1, &modulo3, venda1);

    return 0;
}
