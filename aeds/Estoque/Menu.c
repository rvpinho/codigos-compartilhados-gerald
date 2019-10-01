#include <stdio.h>
#include <stdlib.h>
#include "Menu.h"

void MenuPrincipal(TModuloProduto *ModuloP, TProdutos produto, TModuloCliente *ModuloC, TClientes Clientes, TModuloVendas *ModuloV, TVendas vendas, TModuloNotaFiscal *ModuloNota )
{
    int opcao = 0;
    do
    {
        system("cls");
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
            SubMenuProva(ModuloP, produto, ModuloC, Clientes, ModuloV, vendas, ModuloNota );
            break;
        case 5:
            printf("\nSaindo do sistema!\n");
            system("PAUSE");
        default:
            printf("digite uma opcao valida!");
            break;
        }
    }while( opcao != 5 );
}

void SubMenuProduto(TModuloProduto* ModuloP, TProdutos produto)
{
     int opcao = 0;
     int i ;
    do
    {

        system("cls");
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
            printf("\n");
            system("PAUSE");
            break;
            //PESQUISAR
        case 2:
            printf("\nDigite o codigo do produto:");
            fflush(stdin);
            scanf("%d", &produto.CodigoProduto);
            PesquisarProduto(*ModuloP, produto);
            printf("\n");
            system("PAUSE");
            break;
        case 3:
            printf("\nDigite o codigo do produto:");
            fflush(stdin);
            scanf("%d", &produto.CodigoProduto);
            AlterarProduto(ModuloP, produto);
            printf("\n");
            system("PAUSE");
            break;
        case 4:
            printf("\nDigite o codigo do produto:");
            fflush(stdin);
            scanf("%d", &produto.CodigoProduto);
            ExcluirProduto(ModuloP, produto);
            printf("\n");
            system("PAUSE");
            break;
        case 5:
            printf("\nDigite o codigo do produto:");
            fflush(stdin);
            scanf("%d", &produto.CodigoProduto);
            i = PesquisarProduto(*ModuloP, produto);
            if( i != -1){
            ImprimirProduto(ModuloP->vetor[i]);
            }
            printf("\n");
            system("PAUSE");
            break;
        case 6:
            ImprimirGeral(*ModuloP, produto);
            printf("\n");
            system("PAUSE");
            break;
        case 7:
            printf("Retornando ao menu principal");
            printf("\n");
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
        system("cls");
        MSG_Vendas();
        printf("\nDigite uma opcao:");
        fflush(stdin);
        scanf("%d", &opcao);
        switch(opcao)
        {
        case 1:
            LerVendas(&vendas);
            InserirVendas(ModuloV, vendas, ModuloP, *ModuloC);
            printf("\n");
            system("PAUSE");
            break;
        case 2:
            printf("\nDigite o codigo do produto:");
            fflush(stdin);
            scanf("%d", &produto.CodigoProduto);
            printf("\nDigite o CPF/CNPJ do cliente:");
            fflush(stdin);
            fgets(Clientes.ID, TAM, stdin);
            PesquisarVendas(*ModuloV, vendas, Clientes, produto);
            printf("\n");
            system("PAUSE");
            break;
        case 3:
            printf("\nDigite o codigo do produto:");
            fflush(stdin);
            scanf("%d", &produto.CodigoProduto);
            printf("\nDigite o CPF/CNPJ do cliente:");
            fflush(stdin);
            fgets(Clientes.ID, TAM, stdin);
            AlterarVendas(ModuloV, vendas, *ModuloC, Clientes, ModuloP, produto);
            printf("\n");
            system("PAUSE");
            break;
        case 4:
            printf("\nDigite o codigo do produto:");
            fflush(stdin);
            scanf("%d", &produto.CodigoProduto);
            printf("\nDigite o CPF/CNPJ do cliente:");
            fflush(stdin);
            fgets(Clientes.ID, TAM, stdin);

            ExcluirVendas(ModuloV, vendas, *ModuloC, Clientes, *ModuloP, produto);
            printf("\n");
            system("PAUSE");
            break;
        case 5:
            printf("\nDigite o codigo do produto:");
            fflush(stdin);
            scanf("%d", &produto.CodigoProduto);
            printf("\nDigite o CPF/CNPJ do cliente:");
            fflush(stdin);
            fgets(Clientes.ID, TAM, stdin);
            i = PesquisarVendas(*ModuloV, vendas, Clientes, produto);
            if( i != -1 ){
            ImprimirVendas(ModuloV->vetor[i]);
            }printf("\n");
            system("PAUSE");
            break;
        case 6:
            ImprimirGeralV(*ModuloV, vendas);
            printf("\n");
            system("PAUSE");
            break;
        case 7:
            printf("Retornando ao menu principal");
            printf("\n");
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
        system("cls");
        MSG_Cliente();
        printf("\nDigite uma opcao:");
        fflush(stdin);
        scanf("%d", &opcao);
        switch(opcao)
        {
        case 1:
            LerCliente(&cliente);
            InserirCliente(ModuloC, cliente);
            printf("\n");
            system("PAUSE");
            break;
        case 2:
            printf("\nDigite o CPF/CNPJ do cliente:");
            fflush(stdin);
            fgets(cliente.ID, TAM, stdin);
            PesquisarCliente(*ModuloC, cliente);
            printf("\n");
            system("PAUSE");
            break;
        case 3:
            printf("\nDigite o CPF/CNPJ do cliente:");
            fflush(stdin);
            fgets(cliente.ID, TAM, stdin);
            AlterarCliente(ModuloC, cliente);
            printf("\n");
            system("PAUSE");
            break;
        case 4:
            printf("\nDigite o CPF/CNPJ do cliente:");
            fflush(stdin);
            fgets(cliente.ID, TAM, stdin);
            ExcluirCliente(ModuloC, cliente);
            printf("\n");
            system("PAUSE");
            break;
        case 5:
            printf("\nDigite o CPF/CNPJ do cliente:");
            fflush(stdin);
            fgets(cliente.ID, TAM, stdin);
            i = PesquisarCliente(*ModuloC, cliente);
            if( i != -1){
            ImprimirCliente(ModuloC->vetor[i]);
            }
            printf("\n");
            system("PAUSE");
            break;
        case 6:
            ImprimirGeralC(*ModuloC, cliente);
            printf("\n");
            system("PAUSE");
            break;
        case 7:
            printf("Retornando ao menu principal");
            printf("\n");
            system("PAUSE");
        default:
            printf("digite uma opcao valida!");
            break;
        }
    }while( opcao != 7 );
}

void SubMenuProva(TModuloProduto* ModuloP, TProdutos produto, TModuloCliente* ModuloC, TClientes Clientes, TModuloVendas* ModuloV, TVendas vendas, TModuloNotaFiscal *ModuloNota)
{
    int opcao = 0;
    int i;
    TClientes cliente2;
    TData data;
    do
    {
        system("cls");
        MSG_Prova();
        printf("\nDigite uma opcao:");
        fflush(stdin);
        scanf("%d", &opcao);
        switch(opcao)
        {
        case 1:
            MaisVendido(*ModuloP);
            printf("\n");
            system("PAUSE");
            break;
        case 2:
            VendaVista(*ModuloV);
            printf("\n");
            system("PAUSE");
            break;
        case 3:
            printf("\nDigite o CPF/CNPJ do cliente:");
            fflush(stdin);
            fgets(Clientes.ID, TAM, stdin);
            i = PesquisarCliente(*ModuloC, Clientes);
            if( i != -1)
            {
            printf("\nDigite o CPF/CNPJ do cliente:");
            fflush(stdin);
            fgets(cliente2.ID, TAM, stdin);
            i = PesquisarCliente(*ModuloC, cliente2);
            if( i != -1)
                {
                    ComparaCliente(*ModuloV, Clientes, cliente2);
                }
            }
            printf("\n");
            system("PAUSE");
            break;
        case 4:
            printf("\nDigite o CPF/CNPJ do cliente:");
            fflush(stdin);
            fgets(Clientes.ID, TAM, stdin);
            i = PesquisarCliente(*ModuloC, Clientes);
            if( i != -1)
            {
                printf("\nDigite o dia: ");
                fflush(stdin);
                scanf("%d", &data.dia);
                printf("\nDigite o mes: ");
                fflush(stdin);
                scanf("%d", &data.mes);
                printf("\nDigite o ano: ");
                fflush(stdin);
                scanf("%d", &data.ano);
                NotaFiscal(*ModuloV, Clientes, data, ModuloNota);
            }
            printf("\n");
            system("PAUSE");
            break;
        case 5:
             printf("Retornando ao menu principal");
            printf("\n");
            system("PAUSE");
        default:
            printf("digite uma opcao valida!");
            break;
        }
        }while(opcao != 5);
        }

void MSG_Principal()
{
    printf("\n|======MENU======|");
    printf("\n| [1] PRODUTO    |");
    printf("\n| [2] CLIENTE    |");
    printf("\n| [3] VENDAS     |");
    printf("\n| [4] PROVA      |");
    printf("\n| [5] SAIR       |");
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

void MSG_Prova()
{
    printf("\n|========MENU PROVA========|");
    printf("\n| [1]PRODUTO MAIS VENDIDO  |");
    printf("\n| [2]VENDAS A VISTA        |");
    printf("\n| [3]COMPARAR CLIENTE      |");
    printf("\n| [4]NOTA FISCAL           |");
    printf("\n| [5]VOLTAR                |");
    printf("\n|==========================|");
}
