#include <stdio.h>
#include <stdlib.h>
#include "Menu.h"

void MenuPrincipal(TModuloProduto *ModuloP, TProdutos produto, TModuloCliente *ModuloC, TClientes Clientes, TModuloVendas *ModuloV, TVendas vendas )
{
    int opcao = 0;
    do
    {
        //system("cls");
        MSG_Principal();
        printf("\nDigite uma opcao:");
        fflush(stdin);
        scanf("%d", &opcao);
        switch(opcao)
        {
        case 1:
            SubMenuProduto(ModuloP, produto);
            break;
        case 2:
            SubMenuCliente(ModuloC, Clientes);
            break;
        case 3:
            SubMenuVenda(ModuloP, produto,ModuloC, Clientes, ModuloV, vendas);
            break;
        case 4:
            printf("\nSaindo do sistema!");
            system("PAUSE");
        default:
            printf("digite uma opcao valida!");
            break;
        }
    }while( opcao != 4 );
}

void SubMenuProduto(TModuloProduto* ModuloP, TProdutos produto)
{
     int opcao = 0;
     int i ;
    do
    {
        //system("cls");
        MSG_Produto();
        printf("\nDigite uma opcao:");
        fflush(stdin);
        scanf("%d", &opcao);
        switch(opcao)
        {
            //INSERIR
        case 1:
            LerProduto(&produto);
            InserirProduto(ModuloP, produto);
            break;
            //PESQUISAR
        case 2:
            printf("\nDigite o codigo do produto:");
            fflush(stdin);
            scanf("%d", &produto.CodigoProduto);
            PesquisarProduto(*ModuloP, produto);
            break;
        case 3:
            printf("\nDigite o codigo do produto:");
            fflush(stdin);
            scanf("%d", &produto.CodigoProduto);
            AlterarProduto(ModuloP, produto);
            break;
        case 4:
            printf("\nDigite o codigo do produto:");
            fflush(stdin);
            scanf("%d", &produto.CodigoProduto);
            ExcluirProduto(ModuloP, produto);
            break;
        case 5:
            printf("\nDigite o codigo do produto:");
            fflush(stdin);
            scanf("%d", &produto.CodigoProduto);
            i = PesquisarProduto(*ModuloP, produto);
            if( i != -1){
            ImprimirProduto(ModuloP->vetor[i]);
            }
            break;
        case 6:
            ImprimirGeral(*ModuloP, produto);
            break;
        case 7:
            printf("Retornando ao menu principal");
            system("PAUSE");
        default:
            printf("digite uma opcao valida!");
            break;
        }
    }while( opcao != 7 );
}

void SubMenuVenda(TModuloProduto* ModuloP, TProdutos produto, TModuloCliente* ModuloC, TClientes Clientes, TModuloVendas* ModuloV, TVendas vendas)
{
         int opcao = 0;
     int i ;
    do
    {
        //system("cls");
        MSG_Vendas();
        printf("\nDigite uma opcao:");
        fflush(stdin);
        scanf("%d", &opcao);
        switch(opcao)
        {
        case 1:
            LerVendas(&vendas);
            InserirVendas(ModuloV, vendas);
            break;
        case 2:
            printf("\nDigite o codigo da venda:");
            fflush(stdin);
            scanf("%d", &vendas.Codigo);
            printf("\nDigite o codigo do produto:");
            fflush(stdin);
            scanf("%d", &produto.CodigoProduto);
            printf("\nDigite o CPF/CNPJ do cliente:");
            fflush(stdin);
            scanf("%d", &Clientes.ID);
            PesquisarVendas(*ModuloV, vendas, *ModuloC, Clientes, *ModuloP, produto);
            break;
        case 3:
            printf("\nDigite o codigo da venda:");
            fflush(stdin);
            scanf("%d", &vendas.Codigo);
            printf("\nDigite o codigo do produto:");
            fflush(stdin);
            scanf("%d", &produto.CodigoProduto);
            printf("\nDigite o CPF/CNPJ do cliente:");
            fflush(stdin);
            scanf("%d", &Clientes.ID);
            AlterarVendas(ModuloV, vendas, *ModuloC, Clientes, *ModuloP, produto);
            break;
        case 4:
            printf("\nDigite o codigo da venda:");
            fflush(stdin);
            scanf("%d", &vendas.Codigo);
            printf("\nDigite o codigo do produto:");
            fflush(stdin);
            scanf("%d", &produto.CodigoProduto);
            printf("\nDigite o CPF/CNPJ do cliente:");
            fflush(stdin);
            scanf("%d", &Clientes.ID);
            ExcluirVendas(ModuloV, vendas, *ModuloC, Clientes, *ModuloP, produto);
            break;
        case 5:
            printf("\nDigite o codigo da venda:");
            fflush(stdin);
            scanf("%d", &vendas.Codigo);
            printf("\nDigite o codigo do produto:");
            fflush(stdin);
            scanf("%d", &produto.CodigoProduto);
            printf("\nDigite o CPF/CNPJ do cliente:");
            fflush(stdin);
            scanf("%d", &Clientes.ID);
            i = PesquisarVendas(*ModuloV, vendas, *ModuloC, Clientes, *ModuloP, produto);
            if( i != -1){
            ImprimirVendas(ModuloV->vetor[i]);
            }
            break;
        case 6:
            ImprimirGeralV(*ModuloV, vendas);
            break;
        case 7:
            printf("Retornando ao menu principal");
            system("PAUSE");
        default:
            printf("digite uma opcao valida!");
            break;
        }
    }while( opcao != 7 );
}

void SubMenuCliente(TModuloCliente* ModuloC, TClientes cliente)
{
     int opcao = 0;
     int i;
    do
    {
        //system("cls");
        MSG_Cliente();
        printf("\nDigite uma opcao:");
        fflush(stdin);
        scanf("%d", &opcao);
        switch(opcao)
        {
        case 1:
            LerCliente(&cliente);
            InserirCliente(ModuloC, cliente);
            break;
        case 2:
            printf("\nDigite o CPF/CNPJ do cliente:");
            fflush(stdin);
            scanf("%d", &cliente.ID);
            PesquisarCliente(*ModuloC, cliente);
            break;
        case 3:
            printf("\nDigite o CPF/CNPJ do cliente:");
            fflush(stdin);
            scanf("%d", &cliente.ID);
            AlterarCliente(ModuloC, cliente);
            break;
        case 4:
            printf("\nDigite o CPF/CNPJ do cliente:");
            fflush(stdin);
            scanf("%d", &cliente.ID);
            ExcluirCliente(ModuloC, cliente);
            break;
        case 5:
            printf("\nDigite o CPF/CNPJ do cliente:");
            fflush(stdin);
            scanf("%d", &cliente.ID);
            i = PesquisarCliente(*ModuloC, cliente);
            if( i != -1){
            ImprimirCliente(ModuloC->vetor[i]);
            }
            break;
        case 6:
            ImprimirGeralC(*ModuloC, cliente);
            break;
        case 7:
            printf("Retornando ao menu principal");
            system("PAUSE");
        default:
            printf("digite uma opcao valida!");
            break;
        }
    }while( opcao != 7 );
}

void MSG_Principal()
{
    printf("\n|======MENU======|");
    printf("\n| [1] PRODUTO    |");
    printf("\n| [2] CLIENTE    |");
    printf("\n| [3] VENDAS     |");
    printf("\n| [4] SAIR       |");
    printf("\n|================|");

}

void MSG_Cliente()
{
    printf("\n|====MODULO CLIENTE====|");
    printf("\n| [1] INSERIR          |");
    printf("\n| [2] PESQUISAR        |");
    printf("\n| [3] ALTERAR          |");
    printf("\n| [4] EXCLUIR          |");
    printf("\n| [5] IMPRIMIR         |");
    printf("\n| [6] IMPRIMIR GERAL   |");
    printf("\n| [7] VOLTAR           |");
    printf("\n|======================|");
}

void MSG_Produto()
{
    printf("\n|====MODULO PRODUTO====|");
    printf("\n| [1] INSERIR          |");
    printf("\n| [2] PESQUISAR        |");
    printf("\n| [3] ALTERAR          |");
    printf("\n| [4] EXCLUIR          |");
    printf("\n| [5] IMPRIMIR         |");
    printf("\n| [6] IMPRIMIR GERAL   |");
    printf("\n| [7] VOLTAR           |");
    printf("\n|======================|");
}

void MSG_Vendas()
{
    printf("\n|====MODULO VENDAS====|");
    printf("\n| [1] INSERIR         |");
    printf("\n| [2] PESQUISAR       |");
    printf("\n| [3] ALTERAR         |");
    printf("\n| [4] EXCLUIR         |");
    printf("\n| [5] IMPRIMIR        |");
    printf("\n| [6] IMPRIMIR GERAL  |");
    printf("\n| [7] VOLTAR          |");
    printf("\n|=====================|");
}
