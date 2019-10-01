#include <stdio.h>
#include <stdlib.h>
#include "TVendas.h"
#include "Menu.h"


int main()
{
    TModuloCliente modulo1;
    TModuloProduto modulo2;
    TModuloVendas modulo3;

    TClientes cliente1;
    TProdutos produto1;
    TVendas venda1;

    IniciarModuloCliente(&modulo1);
    IniciarModuloProduto(&modulo2);
    IniciarModuloVendas(&modulo3);

    MenuPrincipal(&modulo2, produto1, &modulo1, cliente1, &modulo3, venda1);
{}}
