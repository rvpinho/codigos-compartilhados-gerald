#ifndef VENDAS_H_INCLUDED
#define VENDAS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "Cliente.h"
#include "Produto.h"

typedef struct vendas
{
    char Nome [TAM];
    int Codigo;
    int Quantidade;
    float Peco;
    TData DataDeVenda;
    TData DataDoPagamento;
    int tipo;
} TVendas;

typedef struct moduloVendas
{
    TVendas vetor [TAM];
    int indice;
} TModuloVendas;

void LerVendas(TVendas *Venda);
void ImprimirVendas(TVendas IVendas);
void IniciarModuloVendas(TModuloVendas *modulo);
void InserirVendas(TModuloVendas *modulo, TVendas venda, TModuloProduto *moduloP, TModuloCliente moduloC);
int PesquisarVendas(TModuloVendas moduloV, TVendas venda, TModuloCliente moduloC, TClientes cliente, TModuloProduto moduloP, TProdutos produto);
void ImprimirGeralV(TModuloVendas modulo, TVendas venda);
void AlterarVendas(TModuloVendas *modulo, TVendas venda, TModuloCliente moduloC, TClientes cliente, TModuloProduto moduloP, TProdutos produto);
void ExcluirVendas(TModuloVendas *modulo, TVendas vendas, TModuloCliente moduloC, TClientes cliente, TModuloProduto moduloP, TProdutos produto);


#endif // VENDAS_H_INCLUDED
