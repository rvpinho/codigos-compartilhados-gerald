#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Vendas.h"

void IniciarModuloVendas(TModuloVendas *modulo)
{
    modulo->indice = 0;
}

void IniciarModuloNotaFiscal(TModuloNotaFiscal *modulo)
{
    modulo->indice = 0;
}

//Função Ler Venda
void LerVendas(TVendas *Venda)
{
    printf("\n======CADASTRO DE VENDA======");
    printf("\nDigite o CPF/CNPJ do cliente: ");
    fflush(stdin);
    fgets(Venda->Nome, TAM, stdin);

    printf("\nDigite o codigo do produto: ");
    fflush(stdin);
    scanf("%d", &Venda->Codigo);

    printf("\nDigite a quantidade:");
    fflush(stdin);
    scanf("%d", &Venda->Quantidade);

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

    printf("\nTipo do pagamento: a vista digite 0, no credito digite 1: ");
    fflush(stdin);
    scanf("%d",&Venda->tipo);
}


void ImprimirVendas(TVendas IVenda)
{
    printf("\n\n==========VENDAS==========");
    printf("\nCPF/CNPJ: %s", IVenda.Nome);
    printf("Codigo do produto: %d", IVenda.Codigo);
    printf("\nQuantidade: %d", IVenda.Quantidade);
    printf("\nPreco total: %.2f", IVenda.Peco);
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

void InserirVendas(TModuloVendas *modulo, TVendas venda, TModuloProduto *moduloP, TModuloCliente moduloC)
{
    int i, j;
    TProdutos produto;
    TClientes cliente;
    produto.CodigoProduto = venda.Codigo;
    strcpy(cliente.ID, venda.Nome);

    i = PesquisarProduto(*moduloP, produto);
    j = PesquisarCliente(moduloC, cliente);
    if(modulo->indice < TAM)
    {
        if( i != -1)
        {
            if( j != -1)
            {
                if(moduloP->vetor[i].EstoqueProduto >= venda.Quantidade)
                {
                    modulo->vetor[modulo->indice] = venda;
                    modulo->vetor[modulo->indice].Peco = modulo->vetor[modulo->indice].Quantidade * moduloP->vetor[i].PrecoUnitario;
                    moduloP->vetor[i].EstoqueProduto = moduloP->vetor[i].EstoqueProduto - modulo->vetor[modulo->indice].Quantidade;
                    moduloP->vetor[i].Quantidade_Total_Vendida = moduloP->vetor[i].Quantidade_Total_Vendida + venda.Quantidade;
                    modulo->indice++;
                    printf("\nVenda cadastrado com sucesso!!");
                }
                else
                {
                    printf("\nEstoque indisponivel!!");
                    printf("\nNao foi possivel cadastrar a venda!!");
                }

            }
            else
            {
                printf("\nCodigo  do cliente incorreto!!");
            }
        }
        else
        {
            printf("\nCodigo do produto incorreto!");
        }
    }
    else
    {
        printf("\nNao e possivel cadastrar, memoria cheia!!");
    }
}

int PesquisarVendas(TModuloVendas modulo, TVendas venda,  TClientes cliente, TProdutos produto)
{
    int i, j, prod = -1, clie = -1;

    for(i = 0; i <= modulo.indice; i++)
    {
        j = strcmp(cliente.ID, modulo.vetor[i].Nome);
        if( j == 0)
        {
            clie = i;
        }
    }
    for(i = 0; i <= modulo.indice; i++)
    {
        if( produto.CodigoProduto == modulo.vetor[i].Codigo)
        {
            prod = i;
        }
    }

    if( (clie != -1) && (prod != -1) )
    {
        printf("\nVenda encontrada!!");
        return clie;
    }
    else
    {
        printf("\nVenda nao encontrada!!");
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

void AlterarVendas(TModuloVendas *modulo, TVendas venda, TModuloCliente moduloC, TClientes cliente, TModuloProduto *moduloP, TProdutos produto)
{
    int i, j, aux;
    i = PesquisarVendas(*modulo, venda, cliente, produto);
    j= PesquisarProduto(*moduloP, produto);
    if( i != -1)
    {
        LerVendas(&venda);
        aux = moduloP->vetor[j].EstoqueProduto + modulo->vetor[i].Quantidade; //voltar estoque

        if(moduloP->vetor[i].EstoqueProduto + aux >= venda.Quantidade)
        {
            modulo->vetor[i] = venda;

            modulo->vetor[i].Peco = modulo->vetor[i].Quantidade * moduloP->vetor[i].PrecoUnitario;
            moduloP->vetor[j].EstoqueProduto = aux- modulo->vetor[i].Quantidade;
            ImprimirVendas(modulo->vetor[i]);
            printf("\nVenda alterada com sucesso!!");
        }
        else
        {
            printf("\nEstoque insuficiente!!");
        }
    }
}

void ExcluirVendas(TModuloVendas *modulo, TVendas vendas, TModuloCliente moduloC, TClientes cliente, TModuloProduto moduloP, TProdutos produto)
{
    int i, n;
    i = PesquisarVendas(*modulo, vendas, cliente, produto);
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

void VendaVista(TModuloVendas modulo)
{
    float ValorTotal = 0;
    int cont = 0, i;

    for( i = 0; i < modulo.indice; i++)
    {
        if( modulo.vetor[i].tipo == 0)
        {
            ValorTotal += modulo.vetor[i].Peco;
            cont++;
        }
    }

    printf("\nValor total: %.2f", ValorTotal);
    printf("\nQuantidade de vendas: %d", cont);
}

void ComparaCliente(TModuloVendas modulo, TClientes cliente1, TClientes cliente2)
{
    int i, j, aux, aux2;

    for( i = 0; i < modulo.indice; i++)
    {
        aux = strcmp(modulo.vetor[i].Nome, cliente1.ID);
        if ( aux == 0)
        {
            for( j = 0; j < modulo.indice; j++ )
            {
                aux2 = strcmp(modulo.vetor[j].Nome, cliente2.ID);
                if( aux2 == 0)
                {
                    if( modulo.vetor[i].Codigo == modulo.vetor[j].Codigo)
                    {
                        printf("\nCodigo do produto: %d", modulo.vetor[i].Codigo);
                    }
                }
            }
        }
    }
}

void NotaFiscal(TModuloVendas modulo, TClientes cliente, TData data, TModuloNotaFiscal *ModuloNota)
{
    int i, aux;
    for( i = 0; i < modulo.indice; i++)
    {
        aux = strcmp( modulo.vetor[i].Nome, cliente.ID);
        if( (aux == 0) && (modulo.vetor[i].DataDeVenda.dia == data.dia) && (modulo.vetor[i].DataDeVenda.mes == data.mes) && (modulo.vetor[i].DataDeVenda.ano == data.ano))
        {
            ModuloNota->vetor[ModuloNota->indice] = modulo.vetor[i];
            ModuloNota->indice++;
            printf("\n==========NOTA FISCAL==========");
            ImprimirVendas(modulo.vetor[i]);
            printf("\nOBRIGADO PELA PREFERENCIA, VOLTE SEMPRE!");
        }
    }

}
