#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "TVendas.h"

void MenuPrinci(TModuloProduto *ModuloP, TProdutos Produto, TModuloCliente *ModuloC, TClientes Clientes, TModuloVendas *ModuloV, TVendas Vendas );
void SubMenuProduto(TModuloProduto* ModuloP, TProdutos Produto);
void SubMenuVenda(TModuloProduto* ModuloP, TProdutos Produto, TModuloCliente* ModuloC, TClientes Clientes, TModuloVendas* ModuloV, TVendas Vendas);
void SubMenuCliente(TModuloCliente* ModuloC, TClientes Cliente);
void MensagemPrincipal();
void MensagemClientes();
void MensagemProdutos();
void MensagemVendas();


#endif // MENU_H_INCLUDED
