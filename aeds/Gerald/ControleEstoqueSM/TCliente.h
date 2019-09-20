#ifndef TCLIENTE_H_INCLUDED
#define TCLIENTE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#define TAM 50

typedef struct data
{
    int dia;
    int mes;
    int ano;
} TData;

typedef struct endereco
{
    char logadouro [TAM];
    char cidade [TAM];
    char bairro[TAM];
    int CEP;
    int numero;
    char complemento[TAM];
} TEndereco;

typedef struct Clientes
{
    int ID;
    int Tipo;
    TEndereco EnderecoCompleto;
    TData DataCompleta;
    char Nome [TAM];
    int Identidade;
} TClientes;

typedef struct moduloCliente
{
    TClientes vetor [TAM];
    int indice;
} TModuloCliente;

void LerCliente(TClientes *cliente1);
void ImprimirCliente (TClientes impcliente);
int PesquisarCliente(TModuloCliente modulo, TClientes Cliente);
void IniciarModuloCliente(TModuloCliente *modulo);
void InserirCliente(TModuloCliente *modulo, TClientes clientes);
void ImprimirGeralCliente(TModuloCliente *modulo);
void AlterarCliente(TModuloCliente *modulo, TClientes Cliente);
void ExcluirCliente(TModuloCliente *modulo, TClientes Cliente);

#endif // TCLIENTE_H_INCLUDED
