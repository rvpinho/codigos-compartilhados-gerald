#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "TVendas.h"

void IniciarModuloVendas(TModuloVendas *modulo)
{
    modulo ->indice = 0;

}

void LerVendas(TVendas *vendaa)
{
    printf("\nINSIRA O CODIGO DO PRODUTO: ");
    fflush(stdin);
    scanf("%d", &vendaa->Codigo);

    printf("\nINSIRA O NOME DO PRODUTO: ");
    fflush(stdin);
    fgets(vendaa->Nome, TAM, stdin);

    printf("\nDATA VENDA - DIA: ");
    fflush(stdin);
    scanf("%d", &vendaa->DataDeVenda.dia);

    printf("\nDATA VENDA - MES: ");
    fflush(stdin);
    scanf("%d", &vendaa->DataDeVenda.mes);

    printf("\nDATA VENDA - ANO: ");
    fflush(stdin);
    scanf("%d", &vendaa->DataDeVenda.ano);

    printf("\nDIGITE 0 PARA PAGAMENTO A VISTA E 1 PARA PAGAMENTO NO CREDITO: ");
    fflush(stdin);
    scanf("%d",&vendaa->tipo);

    printf("\nDATA PAGAMENTO - DIA: ");
    fflush(stdin);
    scanf("%d", &vendaa->DataDoPagamento.dia);

    printf("\nDATA PAGAMENTO - MES: ");
    fflush(stdin);
    scanf("%d", &vendaa->DataDoPagamento.mes);

    printf("\nDATA PAGAMENTO - ANO: ");
    fflush(stdin);
    scanf("%d", &vendaa->DataDoPagamento.ano);

}
void ImprimirVendas(TVendas impvendas)
{
    printf("\n\nRESUMO DE VENDA:");
    printf("\nCODIGO: %d  -  NOME DO PRODUTO: %s", impvendas.Codigo, impvendas.Nome);
    if(impvendas.tipo == 0)
    {
        printf("\nTIPO DE PAGAMENTO: A VISTA");
    }

    else if(impvendas.tipo == 1)
    {
        printf("\nTIPO DE PAGAMENTO: CREDITO");
    }

    else
    {
        printf("\nTIPO DE PAGAMENTO INVALIDO");
    }
    printf("\nDATA DA VENDA: %d/%d/%d  -  DATA DE PAGAMENTO: %d/%d/%d",impvendas.DataDeVenda.dia, impvendas.DataDeVenda.mes, impvendas.DataDeVenda.ano, impvendas.DataDoPagamento.dia, impvendas.DataDoPagamento.mes, impvendas.DataDoPagamento.ano);

}
int PesquisarVendas(TModuloVendas modulo, TVendas venda, TModuloCliente moduloC, TClientes cliente, TModuloProduto moduloP, TProdutos produto)
{
    int i;
    for(i=0; i<modulo.indice; i++)
    {

        if(modulo.vetor[i].Codigo==venda.Codigo)
        {
            return i;
        }
    }

    return -1;
}

void InserirVendas(TModuloVendas *modulo, TVendas vendas)
{
    if(modulo->indice < TAM)  //SE O PONTEIRO INDICE DE MODULO FOR MENOR QUE O TAMANHO
    {
        modulo->vetor[modulo->indice] = vendas;    //PONTEIRO VETOR DE MODULO NA POSIÇÃO INDICE DE MODULO RECEBE VENDAS
        modulo->indice++;       //E AUMENTA O VALOR DO INDICE
        printf("\nSEU CLIENTE FOI CADASTRADO COM SUCESSO");       //E EXIBE UMA MENSAGGEM DE SUCESSO
    }
    else
    {
        printf("\nMEMORIA CHEIA: NAO E POSSIVEL CADASTRAR A VENDA");      //CASO NAO ATENDA AS CIRCUNSTANCIAS EXIBE MENSAGEM DE FALHA DE MEMORIA
    }
}
void ImprimirGeralVendas(TModuloVendas modulo)
{
    for(int i = 0; i < modulo.indice; i++)
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
        printf("\nVENDA ALTERADA COM SUCESSO");
    }

    else
    {
        printf("CODIGO INVALIDO: A ALTERACAO NAO PODE SER FEITA");
    }
}
void ExcluirVenda(TModuloVendas *modulo, TVendas Venda)
{
    for(int i=0; i<modulo->indice; i++)
    {
        if (Venda.Codigo == modulo->vetor[i].Codigo)
        {
            for(int j=i; j<modulo->indice; j++)
            {
                modulo->vetor[j].Codigo = modulo->vetor[j+1].Codigo;
            }
            printf("VENDA EXCLUIDA COM SUCESSO");
        }

        else
        {
            printf("NAO E POSSIVEL EXCLUIR A VENDA");
        }
    }

}

void VendasAVista(TModuloVendas modulo)
{

    float ValorTotal;
    int Contador, i;
    ValorTotal = 0;
    Contador = 0;

    for(i=0; i<modulo.indice; i++)
    {
        if(modulo.vetor[i].tipo == 0)
        {

            ValorTotal +=modulo.vetor[i].Preco;
            Contador++;
        }
    }

    printf("FORAM VENDIDAS %d UNIDADE E ", Contador);
    printf("O VALOR TOTAL VENDIDO FOI DE: R$%.2f", ValorTotal);

}


void CompraComum(TModuloVendas modulo, TClientes Cliente1, TClientes Cliente2)
{

    int i, j, auxi, auxii;

    for(i=0; i<modulo.indice; i++)
    {

        auxi=strcmp(modulo.vetor[i].Nome, Cliente1.ID);

        if(auxi == 0)
        {
            for(j=0; j<modulo.indice; j++)
            {

                auxii=strcmp(modulo.vetor[j].Nome, Cliente2.ID);

                if(auxii == 0)
                {

                    if(modulo.vetor[i].Codigo == modulo.vetor[j].Codigo)
                    {
                        printf("O CODIGO DO PRODUTO SOLICITADO E: %d", modulo.vetor.Codigo);
                    }
                }
            }
        }
    }
}


void GerarNotaFiscal(TModuloVendas modulo, TClientes Cliente, TData data, TModuloNotaFiscal *Nfiscal)
    {

        int i, aux;

        for (i=0; i < modulo.indice; i++)
        {

            aux = strcmp(modulo.vetor[i].Nome, Cliente.ID);

            if( (aux==0) && (modulo.vetor[i].DataDeVenda.dia == data.dia) && (modulo.vetor[i].DataDeVenda.mes == data.mes) && (modulo.vetor[i].DataDeVenda.ano == data.ano) )
            {

                Nfiscal->vetor[Nfiscal->indice] = modulo.vetor[i];
                Nfiscal->indice++;

                printf("\n ----------> NOTA FISCAL <---------");
                printf("\nVENDAS:");
                ImprimirVendas(modulo.vetor[i]);
            }

        }
    }
