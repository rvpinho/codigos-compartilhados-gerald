#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Cliente.h"

void IniciarModuloCliente(TModuloCliente *modulo)
{
    modulo->indice = 0;
}

//Função para ler os clientes
void LerCliente(TClientes *cliente)
{
    printf("\n=================CADASTRO DE CLIENTE=================");
    printf("\nTipo (digite 0 para pessoa fisica ou 1 para juridica): ");
    fflush(stdin);
    scanf("%d", &cliente->Tipo);

    if(cliente->Tipo == 0)
    {
        printf("\nDigite o CPF: ");
        fflush(stdin);
        fgets(cliente->ID, TAM, stdin);
    }
    else
    {
        printf("\nDigite o CNPJ: ");
        fflush(stdin);
        fgets(cliente->ID, TAM, stdin);
    }

    printf("\nNome: ");
    fflush(stdin);
    fgets(cliente->Nome, TAM, stdin);

    printf("\nIdentidade:");
    fflush(stdin);
    scanf("%d", &cliente->Identidade);

    printf("\nDia de nascimento: ");
    fflush(stdin);
    scanf("%d", &cliente->DataCompleta.dia);

    printf("\nMes de nascimento: ");
    fflush(stdin);
    scanf("%d", &cliente->DataCompleta.mes);

    printf("\nAno de nascimento: ");
    fflush(stdin);
    scanf("%d", &cliente->DataCompleta.ano);

    printf("\nDigite o nome da rua: ");
    fflush(stdin);
    fgets(cliente->EnderecoCompleto.logadouro, TAM, stdin);

    printf("\nDigite o numero: ");
    fflush(stdin);
    scanf("%d", &cliente->EnderecoCompleto.numero);

    printf("\nDigite o bairro: ");
    fflush(stdin);
    fgets(cliente->EnderecoCompleto.bairro, TAM, stdin);

    printf("\nDigite a cidade: ");
    fflush(stdin);
    fgets(cliente->EnderecoCompleto.cidade, TAM, stdin);

    printf("\nDigite o CEP: ");
    fflush(stdin);
    scanf("%d", &cliente->EnderecoCompleto.CEP);

    printf("\nDigite o complemento: ");
    fflush(stdin);
    fgets(cliente->EnderecoCompleto.complemento, TAM, stdin);
}

//Função para imprimir cliente
void ImprimirCliente(TClientes ICliente)
{
    printf("\n==========CLIENTE==========");
    printf("\nNome: %s", ICliente.Nome);

    if(ICliente.Tipo == 0)
    {
        printf("Tipo: Fisico");
        printf("\nCPF: %s", ICliente.ID);
    }
    else
    {
        printf("Tipo: Juridico");
        printf("\nCNPJ: %s",ICliente.ID);
    }

    printf("Identidade: %d",ICliente.Identidade);
    printf("\nData de nascimento: %d/%d/%d", ICliente.DataCompleta.dia,ICliente.DataCompleta.mes,ICliente.DataCompleta.ano);
    printf("\nEndereco: %s", ICliente.EnderecoCompleto.logadouro);
    printf("Numero: %d", ICliente.EnderecoCompleto.numero);
    printf("\nBairro: %s", ICliente.EnderecoCompleto.bairro);
    printf("Cidade: %s", ICliente.EnderecoCompleto.cidade);
    printf("CEP: %d", ICliente.EnderecoCompleto.CEP);
    printf("\nComplemento: %s", ICliente.EnderecoCompleto.complemento);
}

void InserirCliente(TModuloCliente *modulo, TClientes cliente)
{
    if(modulo->indice < TAM)
    {
        modulo->vetor[modulo->indice] = cliente;
        modulo->indice++;
        printf("\nCliente cadastrado com sucesso!!");
    }
    else
    {
        printf("\nNao e possivel cadastrar, memoria cheia!!");
    }
}

int PesquisarCliente(TModuloCliente modulo, TClientes cliente)
{
    int i, j;
    for( i = 0; i < modulo.indice; i++)
    {
        j = strcmp(cliente.ID, modulo.vetor[i].ID);
        if( j == 0 )
        {
            printf("\nCliente encontrado!");
            return i;
        }
    }
    printf("\nNao foi possivel encontrar o cliente!");
    return -1;
}

void ImprimirGeralC(TModuloCliente modulo, TClientes cliente)
{
     int i;
    for( i = 0; i < modulo.indice; i++)
    {
        ImprimirCliente(modulo.vetor[i]);
    }
}

void AlterarCliente(TModuloCliente *modulo, TClientes cliente)
{
    int i;
    i = PesquisarCliente(*modulo, cliente);
    if( i != -1)
    {
        LerCliente(&cliente);
        modulo->vetor[i] = cliente;
        ImprimirCliente(modulo->vetor[i]);
        printf("\nCliente alterado com sucesso!!");
    }

}

void ExcluirCliente(TModuloCliente *modulo, TClientes cliente)
{
    int i, n;
    i = PesquisarCliente(*modulo, cliente);
    if( i != -1)
    {
        for( n = i ; n < modulo->indice - 1; n++)
        {
            modulo->vetor[n] = modulo->vetor[n+1];
        }
        modulo->indice = modulo->indice -1;
        printf("\nCliente excluido com sucesso!!");
    }

}


