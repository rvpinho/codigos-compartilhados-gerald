#ifndef MENUS_H_INCLUDED
#define MENUS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "Vendas.h"

void MenuPrincipal(TModuloProduto *ModuloP, TProdutos produto, TModuloCliente *ModuloC, TClientes Clientes, TModuloVendas *ModuloV, TVendas vendas, TModuloNotaFiscal *ModuloNota);
void SubMenuCliente(TModuloCliente *ModuloC, TClientes cliente);
void SubMenuProduto(TModuloProduto *ModuloP, TProdutos produto);
void SubMenuVenda(TModuloProduto *ModuloP, TProdutos produto, TModuloCliente *ModuloC, TClientes Clientes, TModuloVendas *ModuloV, TVendas vendas);
void SubMenuProva(TModuloProduto* ModuloP, TProdutos produto, TModuloCliente* ModuloC, TClientes Clientes, TModuloVendas* ModuloV, TVendas vendas, TModuloNotaFiscal *ModuloNota);
void MSG_Principal();
void MSG_Prova();
void MSG_Cliente();
void MSG_Produto();
void MSG_Vendas();

#endif // MENUS_H_INCLUDED
