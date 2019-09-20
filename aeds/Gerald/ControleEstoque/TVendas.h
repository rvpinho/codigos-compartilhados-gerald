#ifndef TVENDAS_H_INCLUDED
#define TVENDAS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "TProduto.h"


typedef struct vendas
{
    char Nome [TAM];
    int Codigo;
    TData DataDeVenda;
    TData DataDoPagamento;
    int tipo;
} TVendas;

typedef struct moduloVendas
{
    TVendas vetor[TAM];
    int indice;
} TModuloVendas;

void LerVendas(TVendas *vendaa);
void ImprimirVendas(TVendas impvendas);
int PesquisarVendas(TModuloVendas modulo, TVendas venda, TModuloCliente moduloC, TClientes cliente, TModuloProduto moduloP, TProdutos produto);
void IniciarModuloVendas(TModuloVendas *modulo);
void InserirVendas(TModuloVendas *modulo, TVendas vendas);
void ImprimirGeralVendas(TModuloVendas modulo);
void AlterarVendas(TModuloVendas *modulo, TVendas venda, TModuloCliente moduloC, TClientes cliente, TModuloProduto moduloP, TProdutos produto);
void ExcluirVenda(TModuloVendas *modulo, TVendas Venda);

#endif // TVENDAS_H_INCLUDED
