#ifndef TPRODUTO_H_INCLUDED
#define TPRODUTO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "TCliente.h"

typedef struct prdutos
{
    int CodigoProduto;
    char NomeProduto[TAM];
    char DescricaoProduto[TAM];
    TData DataFabricacao;
    int LoteProduto;
    float PrecoUnitario;
    int EstoqueProduto;

    int TotalVendido;

} TProdutos;

typedef struct moduloProduto
{
    TProdutos vetor[TAM];
    int indice;
} TModuloProduto;

void LerProduto(TProdutos *produto1);
void ImprimirProduto (TProdutos impproduto);
int PesquisarProduto(TModuloProduto modulo, TProdutos produto);
void IniciarModuloProduto(TModuloProduto *modulo);
void InserirProduto(TModuloProduto *modulo, TProdutos produto);
int PesquisarProduto(TModuloProduto modulo, TProdutos produto);
void ImprimirGeral(TModuloProduto modulo, TProdutos produto);
void AlterarProduto(TModuloProduto *modulo, TProdutos Produto);
void ExcluirProduto(TModuloProduto *modulo, TProdutos Produto);



#endif // TPRODUTO_H_INCLUDED
