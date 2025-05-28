
#include <stdio.h>
#include <stdlib.h>
#define TAM 5



typedef struct SLista{
    int elementos[TAM];
    int fim;
}TLista;

int inserir (TLista *l, int e, int p)
{
    if (l->fim<TAM-1)
    {
        if ((p>=0) && (p<=(l->fim+1)))
        {
            l->fim=l->fim+1;
            for(int i=l->fim;i>p;i--)
                l->elementos[i]=l->elementos[i-1];
            l->elementos[p]=e;
            return 0;
        }
        else
            return 2;
    }
    return 1;
}

int remover (TLista *l, int p)
{
    if (l->fim>=0)
    {
        if((p>=0) && (p<=l->fim))
        {
            for(int i=p;i<l->fim;i++)
                l->elementos[i]=l->elementos[i+1];
            l->fim=l->fim-1;
            return 0;
        }
        return 2;
    }
    return 1;
}

void imprimir (TLista l)
{
    system("cls");
    printf("* * * *   L I S T A   * * * *\n\n");
    for (int i=0;i<=l.fim;i++)
        printf("%d\t",l.elementos[i]);
    printf("\n\n");
    system("pause");
}


int menu ()
{
    int op;
    system("cls");
    printf("* * * *   M E N U   * * * *\n\n");
    printf("\n1 - Inserir");
    printf("\n2 - Remover");
    printf("\n3 - Imprimir");
    printf("\n9 - Sair");
    printf("\n\nDigite a sua opcao: ");
    scanf("%d",&op);
    return op;
}



int main()
{
    TLista lista;
    int op, flag, elemento, posicao;
    lista.fim=-1;
    do
    {
        op=menu();

        switch(op)
        {
            case 1 : system("cls");
                     printf("\nDigite um elemento: ");
                     scanf("%d",&elemento);
                     printf("\nDigite a posicao entre [0] e [%d]: ",lista.fim+1);
                     scanf("%d",&posicao);
                     flag=inserir(&lista,elemento,posicao);
                     if(flag==0)
                        printf("\n\nElemento inserido com sucesso!!\n\n");
                     else
                        if (flag==2)
                           printf("\n\nImpossivel inserir, posicao invalida...\n\n");
                         else
                             printf("\n\nImpossivel inserir...\nLista cheia!\n\n");
                     system("pause");
                     break;
          case 2 :   system("cls");
                     printf("\n\nDigite a posicao [0] e [%d] :",lista.fim);
                     scanf("%d",&posicao);
                     flag=remover(&lista, posicao);
                     if(flag==0)
                        printf("\n\nElemento removido com sucesso!!\n\n");
                     else
                        if (flag==1)
                           printf("\n\nImpossivel remover...\nLista vazia!\n\n");
                        else
                           printf("\n\nImpossivel remover...\nPosicao invalida!\n\n");
                     system("pause");
                     break;

           case 3 :  imprimir(lista);
                     break;


        }


    }while(op!=9);



    return 0;
}
