#include <stdio.h>

#include <stdlib.h>

#define TAM 10

// Definindo a estrutura da pilha

typedef struct 
{
    int vetor[TAM]; //Vetor para armazenar os valores da pilha
    int topo; //índice do topo da pilha
}pilha;

// Função push 
void push(pilha*p, int valor){
    if(p-> topo >= TAM - 1){
        printf("Pilha cheia!\n");
    }
    else {
        p -> topo ++;
        p -> vetor[p->topo] = valor;

        printf ("Elemento %d inserido com sucesso!!\n", valor);

    }
}

//Função pop
void pop (pilha*p){
    if (p-> topo == -1){
        printf("Pilha vazia!\n");
    }
    else{
        printf("Elemento %d removido com sucesso!!\n", p -> vetor[p->topo]);

        p -> topo --;
    }
}

//Função Imprimir
void imprimir(pilha*p){
    if (p-> topo == -1){
        printf("Pilha vazia!\n");
    }
    else{
        printf("Elementos da Pilha\n");
            for (int i = p ->topo; i >= 0; i--)
            {
                printf("%d\t", p->vetor[i]);
            }
        
    }
}

int main(){
    pilha pilha;
    pilha.topo = -1;
    int valor, opcao;

    do{        
        
        printf("\n--- Menu ---\n");
        printf("1 - Push (Inserir)\n");
        printf("2 - Pop (Remover)\n");
        printf("3 - Imprimir\n");
        printf("9 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
                system("cls");
                    printf("Informe um valor para inserir na pilha:\n");
                        scanf("%d", &valor);
                            push(&pilha,valor);
                                break;
        
        case 2:
                system("cls");
                    pop(&pilha);
                        break;
        case 3:
                system("cls");
                    imprimir(&pilha);
                        break;
        default:
            break;
        }
    }while (opcao != 9);

    return 0;
    
}