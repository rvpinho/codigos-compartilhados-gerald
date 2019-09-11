#include <stdio.h>
#include <stdlib.h>
#include "Vendas.h"


int main()
{
    //Declaração auxiliares
    TClientes cliente1;
    TProdutos produto1;
    TVendas venda1;
    TModuloProduto modulo1;
    TModuloCliente modulo2;
    TModuloVendas modulo3;

    //Inicialização
    IniciarModuloProduto(&modulo1);
    IniciarModuloCliente(&modulo2);
    IniciarModuloVendas(&modulo3);

    //Teste 1: Leitura
    for(int a = 0; a < 4; a++){
    LerProduto(&produto1);
    InserirProduto(&modulo1, produto1);
    }
    system("cls");

    /*LerCliente( &cliente1);
    InserirCliente(&modulo2, cliente1);
    system("cls");

    LerVendas( &venda1 );
    InserirVendas(&modulo3, venda1);
    system("cls");*/

    //Teste 2: Pesquisa
    printf("\nDigite um codigo: ");
    fflush(stdin);
    scanf("%d", &produto1.CodigoProduto);

    int i; //indice auxiliar
    i = PesquisarProduto(modulo1, produto1);

    if( i != -1 )
    {
        printf("\nProduto encontrado!!\n");
        ImprimirProduto(modulo1.vetor[i]);
    }
    else
    {
        printf("\nNao encontrado!!\n");
    }

    ImprimirGeral(modulo1, produto1);
    //Teste 3: Alterar
    printf("\nDigite o codigo do produto para alterar: ");
    fflush(stdin);
    scanf("%d", &produto1.CodigoProduto);
    AlterarProduto(&modulo1, produto1);
    printf("\n");
    ImprimirGeral(modulo1, produto1);
    printf("\n");

    //Teste 4: Excluir
    printf("\nDigite o codigo do produto para excluir: ");
    fflush(stdin);
    scanf("%d", &produto1.CodigoProduto);
    ExcluirProduto(&modulo1, produto1);
    printf("\n");
    ImprimirGeral(modulo1, produto1);
    return 0;
}
