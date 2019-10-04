#ifndef TVENDAS_H_INCLUDED
#define TVENDAS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "TProduto.h"
#include "TCliente.h"


typedef struct vendas
{
    char Nome [TAM];
    int Codigo;
    TData DataDeVenda;
    TData DataDoPagamento;
    int tipo;
    float Preco;
} TVendas;

typedef struct moduloVendas
{
    TVendas vetor[TAM];
    int indice;
} TModuloVendas;

typedef struct moduloNotaFiscal
{
        TVendas vetor[TAM];
        int indice;
}TModuloNotaFiscal;

void LerVendas(TVendas *vendaa);
void ImprimirVendas(TVendas impvendas);
int PesquisarVendas(TModuloVendas modulo, TVendas venda, TModuloCliente moduloC, TClientes cliente, TModuloProduto moduloP, TProdutos produto);
void IniciarModuloVendas(TModuloVendas *modulo);
void InserirVendas(TModuloVendas *modulo, TVendas vendas);
void ImprimirGeralVendas(TModuloVendas modulo);
void AlterarVendas(TModuloVendas *modulo, TVendas venda, TModuloCliente moduloC, TClientes cliente, TModuloProduto moduloP, TProdutos produto);
void ExcluirVenda(TModuloVendas *modulo, TVendas Venda);

void VendasAVista(TModuloVendas modulo);
void CompraComum(TModuloVendas modulo, TClientes Cliente1, TClientes Cliente2);
void GerarNotaFiscal(TModuloVendas modulo, TClientes Cliente, TData data, TModuloNotaFiscal *Nfiscal);


#endif // TVENDAS_H_INCLUDED
