#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *esquerda;
    struct no *direita;
} No;

No* criarNo(int valor){
    No* novoNo = (No*)malloc(sizeof(No));
    if (novoNo == NULL){
        printf("Erro ao alocar memoria\n");
        exit(1);
    }
    novoNo->valor = valor;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}

No* inserir(No* raiz, int valor){
    if (raiz == NULL){
        return criarNo(valor);
    }
    if (valor < raiz->valor){
        raiz->esquerda = inserir(raiz->esquerda, valor);
    } else if (valor > raiz->valor){
        raiz->direita = inserir(raiz->direita, valor);
    }
    return raiz;
}

void imprimirPreOrdem(No* raiz){
    if (raiz != NULL) {
        printf("%d ", raiz->valor);
        imprimirPreOrdem(raiz->esquerda);
        imprimirPreOrdem(raiz->direita);
    }
}

int main(){

    No *raiz = NULL;
    int valor;

    printf("Digite os valores para inserir na arvore:\n");
    printf("(Para finalizar, digite um numero negativo)\n");

    while(1){
        printf("Digite um valor: ");

        if(scanf("%d", &valor) != 1){
            printf("Entrada invalida, digite um numero\n");
            while(getchar() != '\n');
            continue;
        }
        if(valor < 0){
            break;
        }
        raiz = inserir(raiz, valor);
    }

    printf("\n");

    if(raiz == NULL){
        printf("A arvore esta vazia\n");
    }else{
        printf("Elementos em pre ordem: ");
        imprimirPreOrdem(raiz);
        printf("\n");
    }
    return 0;
}
