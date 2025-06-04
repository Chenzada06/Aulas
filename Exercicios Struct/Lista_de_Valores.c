#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#define TAM 3

//struct para agrupar info referente a pessoa (valor e nome)
typedef struct Spessoa
{
    char nome[50];
    float valor;    
}TPessoa;

//struct com vetor para agrupar o n de pessoas e determinar o fim 
typedef struct Slista
{
    TPessoa elementos[TAM];
    int fim;

}Tlista;

int cadastrar (Tlista *l, int p, char n[], float v){
    if (l->fim < TAM -1){ //verificando se a lista esta cheia

        if ((p>= 0) && (p<= (l->fim +1))){ //verificando se a posiçao escolhida é valida ou nao

            l->fim = l->fim + 1; //acrescentando 1 ao valor apontador por l

            for (int i = l -> fim; i > p; i--)
            {
                strcpy(l->elementos[i].nome, l->elementos[i-1].nome); //copia a string da esquerda para a direita
                l -> elementos[i].valor = l -> elementos [i-1].valor; //copia o valor da esquerda para a direita

            }
            strcpy (l-> elementos[p].nome,n); //copia a string armazenada em n para o a posição selecionada 
            l-> elementos[p].valor = v; // copia o valor de v para a posição selecionada
            return 0;
        }
        else
            return 2;
    }
    else 
        return 1;

}

int remover (Tlista *l, int p){

    if (l->fim >=0){ //verifica se a listra esta ou nao vazia

        if ((p>=0) && (p<=(l->fim))) //verificando se a posicao escolhida é valida ou nao
        {
            for (int i = p; i <= (l-> fim); i++)
            {
                strcpy(l->elementos[i].nome, l-> elementos[i+1].nome); //
                l->elementos[i].valor, l-> elementos[i+1].valor;
            }

            l->fim = l->fim -1;

                return 0;
    }
    else 
        return 2;
    }
    else 
        return 1;
}

void imprimir (Tlista l){

    system("cls");
    printf("\n\n* *  LISTA  * *\n\n");
    if (l.fim < 0){
        printf("\n\n ****  LISTA VAZIA  ****\n\n");
    }
    else
    for (int i = 0; i < l.fim; i++)
    {
        printf("\n\nNome    : %s ", l.elementos[i].nome);
        printf("\nValor     : %.2f", l.elementos[i].valor);
    }
    
    printf("\n\n\n");
    
}

int main(){

    int opcao;
    TLista lista;
    char nome[50];
    float valor;
    int op, flag, posicao;
    lista.fim=-1;

do{
    system("cls");
    printf("* * * *  MENU  * * * *\n\n");
    printf("\n1 - Cadastro");
    printf("\n2 - Atender");
    printf("\n3 - Imprimir");
    printf("\n9 - Sair");
    printf("\n\nDigite a sua opcao: ");
    scanf("%d", &opcao);

    switch (opcao)
    {
    case 1:  
    system("cls");
        printf("* *   C A D A S T R A R   * *\n\n");
        printf("\nDigite o nome: ");
        fflush(stdin);
        gets(nome);
        printf("\nDigite o valor a restituir: ");
        scanf("%f",&valor);
        printf("\nDigite uma posicao entre [0] e [%d]: ",lista.fim+1);
        scanf("%d",&posicao);
        flag = cadastrar(&lista,posicao,nome,valor);
    if (flag==0)
      printf("\n\nElemento cadastrado com sucesso!!\n\n");
    else
    if (flag==1)
      printf("\nImpossivel cadastrar...\nLista cheia!\n\n");
    else
      printf("\nImpossivel cadastrar...\nposicao invalida!\n\n");
        system("pause");
    break;

    case 2:  system("cls");
        printf("* *   R E M O V E R   * *\n\n");
        printf("Digite a posicao do elemento a ser removido entre [0] e [%d]: ",lista.fim);
        scanf("%d",&posicao);
        flag = remover(&lista,posicao);
        if (flag==0)
           printf("\n\nElemento removido com sucesso!!\n\n");
              else
                 if (flag==1)
                   printf("\nImpossivel remover...\nLista vazia!\n\n");
              else
                   printf("\nImpossivel remover...\nposicao invalida!\n\n");

                    system("pause");
                    break;

           case 3:  imprimir(lista);
                    break;
       }

    
}while (opcao!=9);

    return 0;

}
