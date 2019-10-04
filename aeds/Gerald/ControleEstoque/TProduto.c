#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "TProduto.h"
#include "TCliente.h"



void IniciarModuloProduto(TModuloProduto *modulo)
{
    modulo->indice=0;
}

void LerProduto(TProdutos *produto1)     //REALIZAR LEITURA DOS PRODUTOS
{
    printf("\n------CADASTRANDO PRODUTO------");
    printf("\nINSIRA O CODIGO DO PRODUTO: ");
    fflush(stdin);
    scanf("%d", &produto1->CodigoProduto);

    printf("\nINSIRA O NOME DO PRODUTO: ");
    fflush(stdin);
    fgets(produto1->NomeProduto, TAM, stdin);

    printf("\nINSIRA A DESCRICAO DO PRODUTO: ");
    fflush(stdin);
    fgets(produto1->DescricaoProduto, TAM, stdin);

    printf("\nFABRICACAO - DIA: ");
    fflush(stdin);
    scanf("%d", &produto1->DataFabricacao.dia);

    printf("\nFABRICACAO - MES: ");
    fflush(stdin);
    scanf("%d", &produto1->DataFabricacao.mes);

    printf("\nFABRICACAO - ANO: ");
    fflush(stdin);
    scanf("%d", &produto1->DataFabricacao.ano);

    printf("\nLOTE DE PRODUCAO: ");
    fflush(stdin);
    scanf("%d", &produto1->LoteProduto);     //O LOTE DEVE SER NUMERO OU ALFANUMERICO??

    printf("\nVALOR UNITARIO: ");
    fflush(stdin);
    scanf("%f", &produto1->PrecoUnitario);

    printf("\nESTOQUE INICIAL: ");
    fflush(stdin);
    scanf("%d", &produto1->EstoqueProduto);
}
void ImprimirProduto (TProdutos impproduto)
{
    printf("\n========== PRODUTO ==========:");
    printf("\nCODIGO: %d", impproduto.CodigoProduto);
    printf("NOME DO PRODUTO: %s",impproduto.NomeProduto);
    printf("\nDESCRICAO: %s", impproduto.DescricaoProduto);
    printf("\nLOTE DE PRODUCAO: %d  -  DATA DE FABRICACAO: %d/%d/%d", impproduto.LoteProduto, impproduto.DataFabricacao.dia, impproduto.DataFabricacao.mes, impproduto.DataFabricacao.ano);
    printf("\nVALOR UNITARIO: %.2f  -  ESTOQUE INICIAL: %d", impproduto.PrecoUnitario, impproduto.EstoqueProduto);
}



void InserirProduto(TModuloProduto *modulo, TProdutos produto)
{
    if( modulo->indice < TAM )
    {
        modulo->vetor[modulo->indice] = produto;
        modulo->indice++;
        printf("PRODUTO CADASTRADO COM SUCESSO!");
    }
    else
    {
        printf("MEMORIA CHEIA: NAO E POSSIVEL CADASTRAR!");
    }
}

int PesquisarProduto(TModuloProduto modulo, TProdutos produto)
{
    int i;
    for(i=0; i<modulo.indice; i++)

    {
        if(modulo.vetor[i].CodigoProduto == produto.CodigoProduto);
        {
            printf("O PRODUTO FOI ENCONTRADO");
            return i;
        }
    }
    printf("NAO FOI POSSIVEL ENCONTRAR O PRODUTO");
    return -1;
}

void ImprimirGeral(TModuloProduto modulo, TProdutos produto)
{
    int i;
    for(i = 0; i < modulo.indice; i++)
    {
        ImprimirProduto(modulo.vetor[i]);
    }
}

void AlterarProduto(TModuloProduto *modulo, TProdutos Produto)
{
    int i = PesquisarProduto(*modulo,Produto);

    if (i!=-1)
    {
        LerProduto(&Produto);
        modulo->vetor[i]=Produto;
        ImprimirProduto(modulo->vetor[i]);
        printf("PRODUTO ALTERADO COM SUCESSO!");
    }

    else
    {
        printf("CODIGO INVALIDO: A ALTERACAO NAO PODE SER FEITA");
    }
}

void ExcluirProduto(TModuloProduto *modulo, TProdutos Produto)
{
    int i, j;
    i = PesquisarProduto(*modulo, Produto);

    if(i =! -1)
    {
        modulo->indice--;

        for(i=0; i<modulo->indice; i++)
        {
            for(j=i; j<modulo->indice; j++)
            {
                modulo->vetor[j].CodigoProduto = modulo->vetor[j+1].CodigoProduto;
            }
            printf("PRODUTO EXCLUIDO COM SUCESSO");
        }
    }
}


void EncontraMaisVendido(TModuloProduto modulo)
{
    int i, j, aux;
    aux=0;
    j =-1;

    for(i=0; i <= modulo.indice; i++){
        if (modulo.vetor[i].TotalVendido > aux){
          aux = modulo.vetor[i].TotalVendido;
          j = i;
        }
    }
    ImprimirProduto(modulo.vetor[i]);
}
