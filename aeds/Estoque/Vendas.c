#include <stdio.h>
#include <stdlib.h>
#include "Vendas.h"

void IniciarModuloVendas(TModuloVendas *modulo)
{
    modulo->indice = 0;
}

//Função Ler Venda
void LerVendas(TVendas *Venda)
{
    printf("\n======CADASTRO DE VENDA======");
    printf("\nDigite o nome: ");
    fflush(stdin);
    fgets(Venda->Nome, TAM, stdin);

    printf("\nDigite o codigo: ");
    fflush(stdin);
    scanf("%d", &Venda->Codigo);

    printf("\nDia da venda: ");
    fflush(stdin);
    scanf("%d", &Venda->DataDeVenda.dia);

    printf("\nMes da venda: ");
    fflush(stdin);
    scanf("%d", &Venda->DataDeVenda.mes);

    printf("\nAno da venda: ");
    fflush(stdin);
    scanf("%d", &Venda->DataDeVenda.ano);

    printf("\nDia do pagamento: ");
    fflush(stdin);
    scanf("%d", &Venda->DataDoPagamento.dia);

    printf("\nMes do pagamento: ");
    fflush(stdin);
    scanf("%d", &Venda->DataDoPagamento.mes);

    printf("\nAno do pagamento: ");
    fflush(stdin);
    scanf("%d", &Venda->DataDoPagamento.ano);

    printf("\nTipo do pagamento: a vista digite 0, no credito digite 1");
    fflush(stdin);
    scanf("%d",&Venda->tipo);
}


void ImprimirVendas(TVendas IVenda)
{
    printf("\n\n==========VENDAS==========");
    printf("\nNome: %s", IVenda.Nome);
    printf("Codigo: %d", IVenda.Codigo);
    printf("\nData da compra: %d/%d/%d", IVenda.DataDeVenda.dia, IVenda.DataDeVenda.mes, IVenda.DataDeVenda.ano);
    printf("\nData do pagamento: %d/%d/%d", IVenda.DataDoPagamento.dia, IVenda.DataDoPagamento.mes, IVenda.DataDoPagamento.ano);
    if(IVenda.tipo == 0)
    {
        printf("\nTipo do pagamento: A vista");
    }
    else
    {
        printf("\nTipo do pagamento: Credito");
    }
}

void InserirVendas(TModuloVendas *modulo, TVendas venda)
{
    if(modulo->indice < TAM)
    {
        modulo->vetor[modulo->indice] = venda;
        modulo->indice++;
        printf("\nVenda cadastrado com sucesso!!");
    }
    else
    {
        printf("\nNao e possivel cadastrar, memoria cheia!!");
    }
}

int PesquisarVendas(TModuloVendas modulo, TVendas venda)
{
    int i;
    for( i = 0; i < modulo.indice; i++)
    {
        if(venda.Codigo == modulo.vetor[i].Codigo)
        {
            return i;
        }
    }
    return -1;
}

void ImprimirGeralV(TModuloVendas modulo, TVendas venda)
{
     int i;
    for( i = 0; i < modulo.indice; i++)
    {
        ImprimirVendas(modulo.vetor[i]);
    }
}

void AlterarVendas(TModuloVendas *modulo, TVendas venda)
{
    int i;
    i = PesquisarVendas(*modulo, venda);
    if( i != -1)
    {
        printf("\nVenda encontrada!!");
        LerVendas(&venda);
        modulo->vetor[i] = venda;
        ImprimirVendas(modulo->vetor[i]);
        printf("\nVenda alterada com sucesso!!");
    }
    else
    {
        printf("\nVenda nao encontrada!!");
    }
}

void ExcluirVendas(TModuloVendas *modulo, TVendas vendas)
{
    int i, n;
    i = PesquisarVendas(*modulo, vendas);
    if( i != -1)
    {
        printf("\nVenda encontrada!!");
        for( n = i ; n < modulo->indice - 1; n++)
        {
            modulo->vetor[n] = modulo->vetor[n+1];
        }
        modulo->indice = modulo->indice -1;
        printf("\nVenda excluida com sucesso!!");
    }
    else
    {
        printf("\nVenda nao encontrada!!");
    }
}
