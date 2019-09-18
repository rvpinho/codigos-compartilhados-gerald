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

int PesquisarVendas(TModuloVendas modulo, TVendas venda, TModuloCliente moduloC, TClientes cliente, TModuloProduto moduloP, TProdutos produto)
{
    int i,j,k;
    for( i = 0; i < modulo.indice; i++)
    {
        if(venda.Codigo == modulo.vetor[i].Codigo)
        {   printf("\nCodigo da venda correto!!");
            for( j = 0; j < moduloC.indice; j++)
            {
                if(cliente.ID == moduloC.vetor[i].ID)
                {
                    printf("\nID correto!!");
                    for( k = 0; k < moduloP.indice; j++)
                    {
                        if(produto.CodigoProduto == moduloP.vetor[i].CodigoProduto)
                        {
                            printf("\nCodigo do produto encontrado!!");
                            printf("\nVenda encontrada!!");
                            return i;
                        }else{printf("\nCodigo do produto incorreto");
                        break;}
                    }
                }else{printf("\nID incorreto!!");
                break;}
            }
        }else{printf("\nCodigo da venda incorreto!!");
        break;}
    }

    printf("\nNao foi possivel encontrar a venda!");
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

void AlterarVendas(TModuloVendas *modulo, TVendas venda, TModuloCliente moduloC, TClientes cliente, TModuloProduto moduloP, TProdutos produto)
{
    int i;
    i = PesquisarVendas(*modulo, venda, moduloC, cliente, moduloP, produto);
    if( i != -1)
    {
        LerVendas(&venda);
        modulo->vetor[i] = venda;
        ImprimirVendas(modulo->vetor[i]);
        printf("\nVenda alterada com sucesso!!");
    }
}

void ExcluirVendas(TModuloVendas *modulo, TVendas vendas, TModuloCliente moduloC, TClientes cliente, TModuloProduto moduloP, TProdutos produto)
{
    int i, n;
    i = PesquisarVendas(*modulo, vendas, moduloC, cliente, moduloP, produto);
    if( i != -1)
    {
        for( n = i ; n < modulo->indice - 1; n++)
        {
            modulo->vetor[n] = modulo->vetor[n+1];
        }
        modulo->indice = modulo->indice -1;
        printf("\nVenda excluida com sucesso!!");
    }

}
