#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#define TAM 5

typedef struct SPessoa
{
    char nome[50];
    float valor;
}TPessoa;

typedef struct SLista
{
    TPessoa elementos[TAM];
    int fim;
}TLista;

void cadastro (TLista *l, int posicao, int valor, char n[]){

    if(l->fim < TAM-1){
        printf("Lista cheia");
    }
    if((posicao >= 0) && (posicao <=(l->fim+1))){

            l->fim = l->fim +1;

            for (int i = l-> fim; i > posicao; i--)
            {
                strcpy(l->elementos[i].nome, l->elementos[i-1].nome);
                l->elementos[i].valor = l->elementos[i-1].valor;
            
            }
            strcpy(l->elementos[l->fim].nome,n);
            l->elementos[l->fim].valor = valor;

            printf("Cadastro Concluido");
        }
    else{
        printf("Posicao invalida");
    }

}

void remover(TLista *l, int posicao){

    if (l-> fim == -1){
        printf("Lista vazia");
    }
    if (((posicao >= 0) && (posicao <=(l->fim)))){

     for (int i = posicao; i <= (l-> fim); i++)
     {
        strcpy(l->elementos[i].nome, l->elementos[i+1].nome);
        l->elementos[i].valor = l->elementos[i+1].valor;
     }
     
     l->fim = l->fim -1;
     printf("Atendimento concluido");
    }
     else{
        printf("Posicao invalida");
     }
}

void imprimir (TLista l){
    if (l.fim == -1){
        printf("Lista vazia");
    }
    else{
    
    for (int i = 0; i < l.fim; i++)
    {
        printf("Nome:   %s",l.elementos[i].nome);
        printf("Valor:  %f", l.elementos[i].valor);
        printf("\n\n");
    }
    }
}
