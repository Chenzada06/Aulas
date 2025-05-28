#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#define TAM 10

typedef struct SPessoa
{
    char nome[50];
    float valor
}TPessoa;

void cadastrar (TPessoa p[]){
    printf("\nCadastro de Pessoa");

    for (int i = 0; i < TAM; i++)
    {
        printf("\nDigite o nome: ");
        fflush(stdin);
        gets(p[i].nome);
        printf("\nDigite o valor a restituir: ");
        scanf("%f", &p[i].valor);
    }
    
}

void imprimir (TPessoa p[]){
    
}