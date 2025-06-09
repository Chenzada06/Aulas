#include <stdio.h>

#include <stdlib.h>

#define TAM 5

void push(int *fim, int fila[], int valor)
{

    if (*fim == TAM - 1)
    {
        printf("Fila esta cheia\n");
    }
    else
    {

        *fim = *fim + 1;

        fila[*fim] = valor;

        printf("Elemento %d inserido com sucesso", fila[*fim]);
    }
}

void pop(int *fim, int fila[])
{

    if (*fim == -1)
    {
        printf("Fila esta vazia");
    }
    else
    {

        for (int i = 0; i <= *fim; i++)
        {
            fila[i] = fila[i + 1];
        }

        *fim = *fim - 1;

        printf("Elemento removido com sucesso");
    }
}

void imprimir(int fim, int fila[])
{

    if (fim == -1)
    {
        printf("Fila esta vazia");
    }
    else
    {
        for (int i = 0; i <= fim; i++)
        {
            printf("%d\t", fila[i]);
        }
    }
}

void somatoria(int fim, int fila[])
{

    int somatoria = 0;

    for (int i = 0; i <= fim; i++)
    {
        somatoria += fila[i];
    }

    printf("Somatoria %d", somatoria);
}

int main()
{

    int opcao, valor, fim;
    fim = -1;
    int fila[TAM];

    do
    {
        printf("\n1 - Push");
        printf("\n2 - Pop");
        printf("\n3 - Imprimir");
        printf("\n4 - Somatorio");
        printf("\n9 - Sair\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            system("cls");
            printf("Informe o valor para ser inserido:");
            scanf("%d", &valor);

            push(&fim, fila, valor);
            break;

        case 2:
            system("cls");
            pop(&fim, fila);
            break;

        case 3:
            system("cls");

            imprimir(fim, fila);

            break;
        case 4:
            system("cls");

            somatoria(fim, fila);

            break;
            
        }

    } while (opcao != 9);
}