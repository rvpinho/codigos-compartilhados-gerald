#include <stdio.h>
#include <stdlib.h>
#include "Menu.h"

void MenuPrinci(TModuloProduto *ModuloP, TProdutos Produto, TModuloCliente *ModuloC, TClientes Clientes, TModuloVendas *ModuloV, TVendas Vendas )
{
    int opcao = 0;
    do
    {
        system("cls");
        MensagemPrincipal();
        printf("\nESCOLHA UMA OPCAO:");
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
            printf("\nSAINDO DO PROGRAMA!");
            system("PAUSE");
        default:
            printf("OPCAO INVALIDA: ESCOLHA NOVAMENTE!");
            break;
        }
    }
    while( opcao != 4 );
}

void SubMenuProduto(TModuloProduto* ModuloP, TProdutos Produto)
{
    int opcao = 0;
    int i ;
    do
    {

        system("cls");
        MensagemProdutos();
        printf("\nESCOLHA UMA OPCAO:");
        fflush(stdin);
        scanf("%d", &opcao);
        switch(opcao)
        {

        case 1:
            LerProduto(&Produto);
            InserirProduto(ModuloP, Produto);
            printf("\n");
            system("PAUSE");
            break;


        case 2:
            printf("\nINSIRA O CODIGO DO PRODUTO:");
            fflush(stdin);
            scanf("%d", &Produto.CodigoProduto);
            PesquisarProduto(*ModuloP, Produto);
            printf("\n");
            system("PAUSE");
            break;

        case 3:
            printf("\nINSIRA O CODIGO DO PRODUTO:");
            fflush(stdin);
            scanf("%d", &Produto.CodigoProduto);
            AlterarProduto(ModuloP, Produto);
            printf("\n");
            system("PAUSE");
            break;

        case 4:
            printf("\nINSIRA O CODIGO DO PRODUTO:");
            fflush(stdin);
            scanf("%d", &Produto.CodigoProduto);
            ExcluirProduto(ModuloP, Produto);
            printf("\n");
            system("PAUSE");
            break;

        case 5:
            printf("\nINSIRA O CODIGO DO PRODUTO:");
            fflush(stdin);
            scanf("%d", &Produto.CodigoProduto);
            i = PesquisarProduto(*ModuloP, Produto);
            if( i != -1)
            {
                ImprimirProduto(ModuloP->vetor[i]);
            }
            printf("\n");
            system("PAUSE");
            break;

        case 6:
            ImprimirGeral(*ModuloP, Produto);
            printf("\n");
            system("PAUSE");
            break;

        case 7:
            printf("DE VOLTA AO MENU PRINCIPAL");
            printf("\n");
            system("PAUSE");

        default:
            printf("OPCAO INVALIDA: DIGITE UMA OPCAO VALIDA!");
            break;
        }
    }
    while( opcao != 7 );
}

void SubMenuVenda(TModuloProduto* ModuloP, TProdutos Produto, TModuloCliente* ModuloC, TClientes Clientes, TModuloVendas* ModuloV, TVendas Vendas)
{
    int opcao = 0;
    int i ;

    do
    {
        system("cls");
        MensagemVendas();
        printf("\nINSIRA UMA OPCAO:");
        fflush(stdin);
        scanf("%d", &opcao);
        switch(opcao)
        {
        case 1:
            LerVendas(&Vendas);
            InserirVendas(ModuloV, Vendas, ModuloP, *ModuloC);
            printf("\n");
            system("PAUSE");
            break;

        case 2:
            printf("\nINSIRA O CODIGO D PRODUTO:");
            fflush(stdin);
            scanf("%d", &Produto.CodigoProduto);
            printf("\nINSIRA O CPF OU CNPJ DO CLIENTE:");
            fflush(stdin);
            fgets(Clientes.ID, TAM, stdin);
            PesquisarVendas(*ModuloV, Vendas, Clientes, Produto);
            printf("\n");
            system("PAUSE");
            break;

        case 3:
            printf("\nINSIRA O CODIGO D PRODUTO:");
            fflush(stdin);
            scanf("%d", &Produto.CodigoProduto);
            printf("\nINSIRA O CPF OU CNPJ DO CLIENTE:");
            fflush(stdin);
            fgets(Clientes.ID, TAM, stdin);
            AlterarVendas(ModuloV, Vendas, *ModuloC, Clientes, ModuloP, Produto);
            printf("\n");
            system("PAUSE");
            break;

        case 4:
            printf("\nINSIRA O CODIGO D PRODUTO:");
            fflush(stdin);
            scanf("%d", &Produto.CodigoProduto);
            printf("\nINSIRA O CPF OU CNPJ DO CLIENTE:");
            fflush(stdin);
            fgets(Clientes.ID, TAM, stdin);

            ExcluirVendas(ModuloV, Vendas, *ModuloC, Clientes, *ModuloP, Produto);
            printf("\n");
            system("PAUSE");
            break;

        case 5:
            printf("\nINSIRA O CODIGO D PRODUTO:");
            fflush(stdin);
            scanf("%d", &Produto.CodigoProduto);
            printf("\nINSIRA O CPF OU CNPJ DO CLIENTE:");
            fflush(stdin);
            fgets(Clientes.ID, TAM, stdin);
            i = PesquisarVendas(*ModuloV, Vendas, Clientes, Produto);
            if( i != -1 )
            {
                ImprimirVendas(ModuloV->vetor[i]);
            }
            printf("\n");
            system("PAUSE");
            break;

        case 6:
            ImprimirGeralV(*ModuloV, Vendas);
            printf("\n");
            system("PAUSE");
            break;

        case 7:
            printf("DE VOLTA AO MENU PRINCIPAL");
            printf("\n");
            system("PAUSE");

        default:
            printf("OPCAO INVALIDA: INSIRA UMA OPCAO VALIDA!");
            break;
        }
    }
    while( opcao != 7 );
}

void SubMenuCliente(TModuloCliente* ModuloC, TClientes Cliente)
{
    int opcao = 0;
    int i;
    do
    {
        system("cls");
        MensagemClientes();
        printf("\nINSIRA UMA OPCAO:");
        fflush(stdin);
        scanf("%d", &opcao);
        switch(opcao)
        {
        case 1:
            LerCliente(&cliente);
            InserirCliente(ModuloC, Cliente);
            printf("\n");
            system("PAUSE");
            break;

        case 2:
            printf("\n");
            fflush(stdin);
            fgets(cliente.ID, TAM, stdin);
            PesquisarCliente(*ModuloC, Cliente);
            printf("\n");
            system("PAUSE");
            break;

        case 3:
            printf("\nINSIRA O CPF OU CNPJ DO CLIENTE:");
            fflush(stdin);
            fgets(cliente.ID, TAM, stdin);
            AlterarCliente(ModuloC, Cliente);
            printf("\n");
            system("PAUSE");
            break;

        case 4:
            printf("\nINSIRA O CPF OU CNPJ DO CLIENTE:");
            fflush(stdin);
            fgets(cliente.ID, TAM, stdin);
            ExcluirCliente(ModuloC, Cliente);
            printf("\n");
            system("PAUSE");
            break;

        case 5:
            printf("\nINSIRA O CPF OU CNPJ DO CLIENTE:");
            fflush(stdin);
            fgets(Cliente.ID, TAM, stdin);
i = PesquisaINSIRA O CPF OU CNPJ DO CLIENTE:
                Cliente(*ModuloC, Cliente);
            if( i != -1)
            {
                ImprimirCliente(ModuloC->vetor[i]);
            }
            printf("\n");
            system("PAUSE");
            break;

        case 6:
            ImprimirGeralCliente(*ModuloC, Cliente);
            printf("\n");
            system("PAUSE");
            break;

        case 7:
            printf("DE VOLTA AO MENU PRINCIPAL");
            printf("\n");
            system("PAUSE");

        default:
            printf("OPCAO INVALIDA: INSIRA UMA OPCAO VALIDA!");
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
