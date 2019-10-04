#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TCliente.h"

void IniciarModuloCliente(TModuloCliente *modulo)
{
    modulo ->indice = 0;

}

void LerCliente(TClientes *cliente1) //FUNÇÃO PARA LER O CLIENTE
{
    printf("\nSELECIONE 0 PARA PESSOA FISICA OU 1 PARA PESSOA JURIDICA: ");
    fflush(stdin);
    scanf("%d", &cliente1->Tipo);

    if(cliente1->Tipo == 0)
    {
        printf("\nINSIRA O NUMERO DE REGISTRO CPF: ");
        fflush(stdin);
        scanf("%d", &cliente1->ID);
    }
    else
    {
        printf("\nINSIRA O NUMERO DE REGISTRO CNPJ: ");
        fflush(stdin);
        scanf("%d", &cliente1->ID);
    }

    printf("\nNOME: ");
    fflush(stdin);
    fgets(cliente1->Nome, TAM, stdin);

    printf("\nID: ");
    fflush(stdin);
    scanf("%d", &cliente1->Identidade);

    printf("\nNASCIMENTO - DIA: ");
    fflush(stdin);
    scanf("%d", &cliente1->DataCompleta.dia);

    printf("\nNASCIMENTO - MES: ");
    fflush(stdin);
    scanf("%d", &cliente1->DataCompleta.mes);

    printf("\nNASCIMENTO - ANO: ");
    fflush(stdin);
    scanf("%d", &cliente1->DataCompleta.ano);

    printf("\nENDERECO - RUA: ");
    fflush(stdin);
    fgets(cliente1->EnderecoCompleto.logadouro, TAM, stdin);

    printf("\nENDERECO - NUMERO ");
    fflush(stdin);
    scanf("%d", &cliente1->EnderecoCompleto.numero);

    printf("\nENDERECO - COMPLEMENTO: ");
    fflush(stdin);
    fgets(cliente1->EnderecoCompleto.complemento, TAM, stdin);

    printf("\nENDERECO - BAIRRO: ");
    fflush(stdin);
    fgets(cliente1->EnderecoCompleto.bairro, TAM, stdin);

    printf("\nENDERECO - CIDADE: ");
    fflush(stdin);
    fgets(cliente1->EnderecoCompleto.cidade, TAM, stdin);

    printf("\nENDERECO - CEP: ");
    fflush(stdin);
    scanf("%d", &cliente1->EnderecoCompleto.CEP);
}
void ImprimirCliente (TClientes impcliente)
{
    printf("\nCLIENTE:");
    if(impcliente.Tipo==0)
    {
        printf("\nCPF: %d  -  NOME: %s", impcliente.ID, impcliente.Nome);
    }
    else if(impcliente.Tipo == 1)
    {
        printf("\nCNPJ: %d  -  NOME: %s", impcliente.ID, impcliente.Nome);
    }
    else
    {
        printf("TIPO INVALIDO");
    }
    printf("\nENDERECO: ");
    printf("\nRUA: %s", impcliente.EnderecoCompleto.logadouro);
    printf("N: %d",impcliente.EnderecoCompleto.numero);
    printf("\nBAIRRO: %s", impcliente.EnderecoCompleto.bairro);
    printf("CIDADE: %s", impcliente.EnderecoCompleto.cidade);
    printf("CEP: %d", impcliente.EnderecoCompleto.CEP);
}
int PesquisarCliente(TModuloCliente modulo, TClientes Cliente)
{
    int i, j;
    for( i = 0; i < modulo.indice; i++)
    {
        j = strcmp(Cliente.ID, modulo.vetor[i].ID);
        if( j == 0 )
        {
            printf("\nCLIENTE ENCONTRADO");
            return i;
        }
    }
    printf("\nCLIENTE NAO ENCONTRADO");
    return -1;
}


void InserirCliente(TModuloCliente *modulo, TClientes clientes)
{

    if(modulo->indice < TAM)  //SE O PONTEIRO INDICE DE MODULO FOR MENOR QUE O TAMANHO
    {
        modulo->vetor[modulo->indice] = clientes;    //PONTEIRO VETOR DE MODULO NA POSIÇÃO INDICE DE MODULO RECEBE CLIENTE
        modulo->indice++;       //E AUMENTA O VALOR DO INDICE
        printf("\nSEU CLIENTE FOI CADASTRADO COM SUCESSO");       //E EXIBE UMA MENSAGGEM DE SUCESSO
    }
    else
    {
        printf("\nMEMORIA CHEIA: NAO E POSSIVEL CADASTRAR O CLIENTE");      //CASO NAO ATENDA AS CIRCUNSTANCIAS EXIBE MENSAGEM DE FALHA DE MEMORIA
    }
}
void ImprimirGeralCliente(TModuloCliente modulo, TClientes Cliente)
{
    int i;
    for( i = 0; i < modulo.indice; i++)
    {
        ImprimirCliente(modulo.vetor[i]);
    }
}

void AlterarCliente(TModuloCliente *modulo, TClientes Cliente)
{
    int i;
    i = PesquisarCliente(*modulo, Cliente);

    if (i!=-1)
    {
        LerCliente(&Cliente);
        modulo->vetor[i]=Cliente;
        ImprimirCliente(modulo->vetor[i]);
        printf("CLIENTE ALTERADO COM SUCESSO!");
    }

    else
    {
        printf("CODIGO INVALIDO: A ALTERACAO NAO PODE SER FEITA");
    }
}
void ExcluirCliente(TModuloCliente *modulo, TClientes Cliente)
{
    for(int i=0; i<modulo->indice; i++)
    {
        if (Cliente.ID == modulo->vetor[i].ID)
        {
            for(int j=i; j<modulo->indice; j++)
            {
                modulo->vetor[j].ID = modulo->vetor[j+1].ID;
            }
            printf("CLIENTE EXCLUIDO COM SUCESSO");
        }


        else
        {
            printf("NAO E POSSIVEL EXCLUIR O CLIENTE");
        }
    }
}
