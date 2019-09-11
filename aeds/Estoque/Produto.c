#include <stdio.h>
#include <stdlib.h>
#include "Produto.h"

void IniciarModuloProduto(TModuloProduto *modulo)
{
    modulo->indice = 0;
}

//Função para ler os produtos
void LerProduto(TProdutos *produto)
{
    printf("\n=======CADASTRO DE PRODUTO=======");
    printf("\nDigite o codigo: ");
    fflush(stdin);
    scanf("%d", &produto->CodigoProduto);

    printf("\nNome: ");
    fflush(stdin);
    fgets(produto->NomeProduto, TAM, stdin);

    printf("\nDescricao: ");
    fflush(stdin);
    fgets(produto->DescricaoProduto, TAM, stdin);

    printf("\nDia de farbicacao: ");
    fflush(stdin);
    scanf("%d", &produto->DataFabricacao.dia);

    printf("\nMes de farbicacao: ");
    fflush(stdin);
    scanf("%d", &produto->DataFabricacao.mes);

    printf("\nAno de farbicacao: ");
    fflush(stdin);
    scanf("%d", &produto->DataFabricacao.ano);

    printf("\nLote: ");
    fflush(stdin);
    scanf("%d", &produto->LoteProduto);

    printf("\nPreco unitario: ");
    fflush(stdin);
    scanf("%f", &produto->PrecoUnitario);

    printf("\nEstoque: ");
    fflush(stdin);
    scanf("%d", &produto->EstoqueProduto);
}

//Função para imprimir os produtos
void ImprimirProduto(TProdutos IProduto)
{
    printf("\n==========PRODUTO==========");
    printf("\nNome: %s", IProduto.NomeProduto);
    printf("Codigo: %d", IProduto.CodigoProduto);
    printf("\nDescricao: %s", IProduto.DescricaoProduto);
    printf("Data de fabricacao: %d/%d/%d", IProduto.DataFabricacao.dia, IProduto.DataFabricacao.mes, IProduto.DataFabricacao.ano);
    printf("\nLote: %d", IProduto.LoteProduto);
    printf("\nPreco unitario: R$%.2f", IProduto.PrecoUnitario);
    printf("\nEstoque: %d", IProduto.EstoqueProduto);
}

void InserirProduto(TModuloProduto *modulo, TProdutos produto)
{
    if( modulo->indice < TAM )
    {
        modulo->vetor[modulo->indice] = produto;
        modulo->indice++;
        printf("\nProduto cadastrado com sucesso!!");
    }
    else
    {
        printf("\nNao e possivel cadastrar, memoria cheia!!");
    }
}

int PesquisarProduto(TModuloProduto modulo, TProdutos produto)
{
    int i;
    for(i = 0; i < modulo.indice; i++)
    {
        if(produto.CodigoProduto == modulo.vetor[i].CodigoProduto)
        {
            return i;
        }
    }
    return -1;
}

void ImprimirGeral(TModuloProduto modulo, TProdutos IGProduto)
{
    int i;
    for( i = 0; i < modulo.indice; i++)
    {
        ImprimirProduto(modulo.vetor[i]);
    }

}

void AlterarProduto(TModuloProduto *modulo, TProdutos produto)
{
    int i;
    i = PesquisarProduto(*modulo, produto);
    if( i != -1)
    {
        printf("\nProduto encontrado!!");
        LerProduto(&produto);
        modulo->vetor[i] = produto;
        ImprimirProduto(modulo->vetor[i]);
        printf("\nProduto alterado com sucesso!!");
    }
    else
    {
        printf("\nProduto nao encontrado!!");
    }

}

void ExcluirProduto(TModuloProduto *modulo, TProdutos produto)
{
    int i, n;
    i = PesquisarProduto(*modulo, produto);
    if( i != -1)
    {
        printf("\nProduto encontrado!!");
        for( n = i ; n < modulo->indice - 1; n++)
        {
            modulo->vetor[n] = modulo->vetor[n+1];
        }
        modulo->indice = modulo->indice -1;
        printf("\nProduto excluido com sucesso!!");
    }
    else
    {
        printf("\nProduto nao encontrado!!");
    }

}
