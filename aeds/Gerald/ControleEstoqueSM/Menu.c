#include <stdio.h>
#include <stdlib.h>
#include "Menu.h"

void MenuPrincipal (TModuloProduto *ModuloP, TProdutos Produto, TModuloCliente *ModuloC, TClientes Clientes, TModuloVendas *ModuloV, TVendas Vendas )
{
    int opcao = 0;
    do
    {
        MensagemPrincipal()

        printf("\nDIGITE UMA OPCAO VALIDA");
        fflush(stdin);
        scanf("%d", &opcao);
        switch(opcao)
        {
        case 1:
            SubMenuProduto(ModuloP, Produto);
            break;

        case 2:
            SubMenuCliente(ModuloC, Clientes);
            break;

        case 3:
            SubMenuVenda(ModuloP, Produto, ModuloC, Clientes, ModuloV, Vendas);
            break;

        case 4:
            printf("\n SISTEMA ENCERRADO");
            system("PAUSE");
        default:
            printf("INSIRA UMA OPCAO VALIDA!");
            break;
        }
    }
    while( opcao != 4 );

}
void SubMenuProdutos(TModuloProduto *moduloP, TProdutos produto)
{
    int opcao=0;
    int i;
    do
    {
        MensagemProdutos();
        printf("DIGITE A OPCAO DESEJADA");
        scanf("%d", &opcao);

        switch(opcao)
        {
        case 1:
            LerProduto(&produto);
            InserirProduto(moduloP, produto);
            break;
        case 2:
            printf("DIGITE O CODIGO DO PRODUTO");
            fflush(stdin);
            scanf("%d", &produto.CodigoProduto);
            PesquisarProduto(*moduloP, produto);
            break;
        case 3:
            printf("DIGITE O CODIGO DO PRODUTO");
            fflush(stdin);
            scanf("%d", &produto.CodigoProduto);
            AlterarProduto(moduloP, produto);
        case 4:
            printf("DIGITE O CODIGO DO PRODUTO");
            fflush(stdin);
            scanf("%d", &produto.CodigoProduto);
            ExcluirProduto(moduloP, produto);
        case 5:
            printf("\nDIGITE O CODIGO DO PRODUTO:");
            fflush(stdin);
            scanf("%d", &produto.CodigoProduto);
            i = PesquisarProduto(moduloP, produto);
            if( i != -1)
            {
                ImprimirProduto(moduloP->vetor[i]);
            }
            break;
        case 6:
            ImprimirGeral(moduloP, produto);
            break;
        case 7:
            printf("RETORNO AO MENU PRINCIPAL");
            system("PAUSE");
        default:
            printf("OPCAO INVALIDA: DIGITE UMA OPCAO VALIDA!");
            break;

        }
    }
    while (opcao=!7);
}
void SubMenuVenda(TModuloProduto* ModuloP, TProdutos Produto, TModuloCliente* ModuloC, TClientes Clientes, TModuloVendas* ModuloV, TVendas Vendas)
{
    int opcao = 0;
    int i ;
    do
    {
        MensagemVendas();

        printf("\nINSIRA UMA OPCAO");
        fflush(stdin);
        scanf("%d", &opcao);

        switch(opcao)
        {
        case 1:
            LerVendas(&Vendas);
            InserirVendas(ModuloV, Vendas);
            break;

        case 2:
            printf("\nDIGITE O CODIGO DA VENDA:");
            fflush(stdin);
            scanf("%d", &Vendas.Codigo);
            printf("\nDIGITE O CODIGO DO PRODUTO");
            fflush(stdin);
            scanf("%d", &Produto.CodigoProduto);
            printf("\nDIGITE O CNPJ OU CPF DO CLIENTE");
            fflush(stdin);
            scanf("%d", &Clientes.ID);

            PesquisarVendas(*ModuloV, Vendas, *ModuloC, Clientes, *ModuloP, Produto);
            break;

        case 3:
            printf("\nDIGITE O CODIGO DA VENDA");
            fflush(stdin);
            scanf("%d", &Vendas.Codigo);
            printf("\nDIGITE O CODIGO DO PRODUTO:");
            fflush(stdin);
            scanf("%d", &Produto.CodigoProduto);
            printf("\nDIGITE O CNPJ OU CPF DO CLIENTE");
            fflush(stdin);
            scanf("%d", &Clientes.ID);

            AlterarVendas(ModuloV, Vendas, *ModuloC, Clientes, *ModuloP, Produto);
            break;

        case 4:
            printf("\nDIGITE O CODIGO DA VENDA:");
            fflush(stdin);
            scanf("%d", &Vendas.Codigo);
            printf("\nDIGITE O CODIGO DO PRODUTO:");
            fflush(stdin);
            scanf("%d", &Produto.CodigoProduto);
            printf("\nDIGITE O CNPJ OU CPF DO CLIENTE:");
            fflush(stdin);
            scanf("%d", &Clientes.ID);

            ExcluirVendas(ModuloV, Vendas, *ModuloC, Clientes, *ModuloP, Produto);
            break;

        case 5:
            printf("\nDIGITE O CODIGO DA VENDA:");
            fflush(stdin);
            scanf("%d", &Vendas.Codigo);
            printf("\nDIGITE O CODIGO DO PRODUTO:");
            fflush(stdin);
            scanf("%d", &Produto.CodigoProduto);
            printf("\nDIGITE O CNPJ OU CPF DO CLIENTE:");
            fflush(stdin);
            scanf("%d", &Clientes.ID);

            i = PesquisarVendas(*ModuloV, Vendas, *ModuloC, Clientes, *ModuloP, Produto);
            if( i != -1)
            {
                ImprimirVendas(ModuloV->vetor[i]);
            }
            break;

        case 6:
            ImprimirGeralV(*ModuloV, Vendas);
            break;

        case 7:
            printf("RETORNANDO AO MENU PRINCIPAL");
            system("PAUSE");

        default:
            printf("OPCAO INVALIDA: DIGITE UMA OPCAO VALIDA");
            break;
        }
    }
    while( opcao != 7 );
}
void SubMenuClientes (TModuloCliente* ModuloC, TClientes Cliente)
{
    int opcao = 0;
    int i;
    do
    {
        MensagemClientes();

        printf("\nDIGITE O CODIGO DO PRODUTO");
        fflush(stdin);
        scanf("%d", &opcao);
        switch(opcao)
        {
        case 1:
            LerCliente(&cliente);
            InserirCliente(ModuloC, Cliente);
            break;

        case 2:
            printf("\nDIGITE O CNPJ OU CPF DO CLIENTE:");
            fflush(stdin);
            scanf("%d", &cliente.ID);
            PesquisarCliente(*ModuloC, Cliente);
            break;

        case 3:
            printf("\nDIGITE O CNPJ OU CPF DO CLIENTE:");
            fflush(stdin);
            scanf("%d", &Cliente.ID);
            AlterarCliente(ModuloC, Cliente);
            break;

        case 4:
            printf("\nDIGITE O CNPJ OU CPF DO CLIENTE:");
            fflush(stdin);
            scanf("%d", &Cliente.ID);
            ExcluirCliente(ModuloC, Cliente);
            break;

        case 5:
            printf("\nDIGITE O CNPJ OU CPF DO CLIENTE:");
            fflush(stdin);
            scanf("%d", &Cliente.ID);
            i = PesquisarCliente(*ModuloC, Cliente);
            if( i != -1)
            {
                ImprimirCliente(ModuloC->vetor[i]);
            }
            break;

        case 6:
            ImprimirGeralCliente(*ModuloC, Cliente);
            break;

        case 7:
            printf("RETORNANDO AO MENU PRINCIPAL");
            system("PAUSE");

        default:
            printf("OPCAO INVALIDA: DIGITE UMA OPCAO VALIDA!");
            break;
        }
    }
    while( opcao != 7 );
}
void MensagemPrincipal()
{
    printf("========== MENU PRINCIPAL ==========");
    printf("\n|(1) PRODUTOS       |");
    printf("\n|(2) CLIENTES       |");
    printf("\n|(3) VENDAS         |");
    printf("\n|(4) SAIR           |");
    printf("____________________");
}
void MensagemClientes()
{
    printf("========== MODULO DE CLIENTES ==========");
    printf("\n|(1) INSERIR       |");
    printf("\n|(2) PESQUISAR     |");
    printf("\n|(3) ALTERAR       |");
    printf("\n|(4) EXCLUIR       |");
    printf("\n|(5) IMPRIMIR      |");
    printf("\n|(6) IMPRIMIR GERAL|");
    printf("\n|(7) VOLTAR        |");
    printf("____________________");
}
void MensagemProdutos()
{
    printf("========== MODULO DE PRODUTOS ==========");
    printf("\n|(1) INSERIR       |");
    printf("\n|(2) PESQUISAR     |");
    printf("\n|(3) ALTERAR       |");
    int opcao = 0;

}
void MensagemVendas()
{
    printf("========== MODULO DE VENDAS ==========");
    printf("\n|(1) INSERIR       |");
    printf("\n|(2) PESQUISAR     |");
    printf("\n|(3) ALTERAR       |");
    printf("\n|(4) EXCLUIR       |");
    printf("\n|(5) IMPRIMIR      |");
    printf("\n|(6) IMPRIMIR GERAL|");
    printf("\n|(7) VOLTAR        |");
    printf("____________________");
}
