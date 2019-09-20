#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "Vendas.h"

void MenuPrincipal (TModuloProduto *ModuloP, TProdutos Produto, TModuloCliente *ModuloC, TClientes Clientes, TModuloVendas *ModuloV, TVendas Vendas );
void SubMenuProdutos(TModuloProduto *moduloP, TProdutos produto);
void SubMenuVenda(TModuloProduto* ModuloP, TProdutos Produto, TModuloCliente* ModuloC, TClientes Clientes, TModuloVendas* ModuloV, TVendas Vendas);
void SubMenuClientes (TModuloCliente* ModuloC, TClientes Cliente);

void MensagemPrincipal();
void MensagemClientes();
void MensagemProdutos();
void MensagemVendas();

#endif // MENU_H_INCLUDED
