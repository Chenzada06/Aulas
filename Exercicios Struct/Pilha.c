#include <stdio.h>

#include <stdlib.h>

#define TAM 5

void inserir_pilha(int p[], int *topo, int valor)
{

    if (*topo == TAM - 1)
    {
        printf("Pilha cheia");
    }
    else
    {
        *topo = *topo + 1;

        p[*topo] = valor;

        printf("Elemento inserido com sucesso");
    }
}

void inserir_fila(int p[], int *fim, int valor)
{

    if (*fim == TAM - 1)
    {
        printf("Fila cheia");
    }
    else
    {
        *fim = *fim + 1;

        p[*fim] = valor;

        printf("Elemento inserido com sucesso");
    }
}

void remover_pilha(int p[], int *topo)
{
    if (*topo == -1)
    {
        printf("Pilha vazia");
    }
    else
    {
        *topo = *topo - 1;
    }
}

void remover_fila(int f[], int *fim)
{
    if (*fim == -1)
    {
        printf("Fila vazia");
    }

    else
    {
        for (int i = 0; i <= *fim; i++)
        {
            f[i] = f[i + 1];
        }
        *fim = *fim - 1;
    }
}

void imprimir_pilha(int topo, int p[]){
    if (topo == -1){
        printf("Pilha vazia");
    }
    else
    {
        for (int i = topo; i >=0; i--){
        
            printf("%d\t", p[i]);
        }
    }
}
void imprimir_fila(int fim, int f[]){
    if (fim == -1){
        printf("Fila vazia");
    }
    else
    {
        for (int i = 0; i <= fim; i++){
        
            printf("%d\t", f[i]);
        }
    }
}

