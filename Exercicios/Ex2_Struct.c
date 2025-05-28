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
    system("cls");
    for (int i = 0; i < TAM; i++)
    {
        printf("\n\nNome    : %s ", p[i].nome);
        printf("\nValor     : %.2f", p[i].valor);
    }
    printf("\n\nElementos cadastrados com sucesso!!\n\n");

}

int main(){

    TPessoa pessoas [TAM];
    int opcao;

    printf("* * * MENU * * *\n\n");
    printf("\n1 - Cadastro");
    printf("\n2 - Atender");
    printf("\n3 - Imprimir");
    printf("\n9 - Sair");
    printf("\nDigite a sua opcao:");
    scanf("%d", &opcao);

    do
    {
        switch (opcao)
        {
        case 1:
            cadastrar(pessoas);
            break;
        
        case 2:
            for (int i = 0; i < TAM; i++)
            {
                strcpy(pessoas[i].nome, "");
                pessoas[i].valor=0;
            }
            printf("\n\nAtendimento concluido...\n\n");

        break;
            
        case 3:  imprimir(pessoas);
        break;
        }

    } while (opcao != 9);
    
    
    return 0;
    
}