#ifndef PRODUTO_H_INCLUDED
#define PRODUTO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "Cliente.h"


typedef struct prdutos
{
    int CodigoProduto;
    char NomeProduto[TAM];
    char DescricaoProduto[TAM];
    TData DataFabricacao;
    int LoteProduto;
    float PrecoUnitario;
    int EstoqueProduto;

} TProdutos;

typedef struct moduloProduto
{
    TProdutos vetor[TAM];
    int indice;
} TModuloProduto;

void LerProduto(TProdutos *produto);
void ImprimirProduto(TProdutos IProduto);
void IniciarModuloProduto(TModuloProduto *modulo);
void InserirProduto(TModuloProduto *modulo, TProdutos produto);
int PesquisarProduto(TModuloProduto modulo, TProdutos produto);
void ImprimirGeral(TModuloProduto modulo, TProdutos IGProduto);
void AlterarProduto(TModuloProduto *modulo, TProdutos produto);
void ExcluirProduto(TModuloProduto *modulo, TProdutos produto);


#endif // PRODUTO_H_INCLUDED
