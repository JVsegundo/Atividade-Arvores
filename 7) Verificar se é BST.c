#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct no{
    int valor;
    struct no *esquerda;
    struct no *direita;
} No;

No* criarNo(int valor){
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->valor = valor;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}

No* inserirNo(No* raiz, int valor, char posicao){
    if(raiz == NULL){
        return criarNo(valor);
    }

    if(posicao == 'e' || posicao == 'E'){
        raiz->esquerda = inserirNo(raiz->esquerda, valor, posicao);
    }else if (posicao == 'd' || posicao == 'D'){
        raiz->direita = inserirNo(raiz->direita, valor, posicao);
    }

    return raiz;
}

int ehBSTUtil(No* raiz, int min, int max){
    if (raiz == NULL) return 1;

    if (raiz->valor <= min || raiz->valor >= max) return 0;

    return ehBSTUtil(raiz->esquerda, min, raiz->valor) &&
           ehBSTUtil(raiz->direita, raiz->valor, max);
}

int ehBST(No* raiz){
    return ehBSTUtil(raiz, INT_MIN, INT_MAX);
}

void imprimirEmOrdem(No* raiz){
    if (raiz != NULL){
        imprimirEmOrdem(raiz->esquerda);
        printf("%d ", raiz->valor);
        imprimirEmOrdem(raiz->direita);
    }
}

int main(){
    No* raiz = NULL;
    int opcao, valor;
    char posicao;

    printf("Construa sua arvore:\n");
    printf("1. Inserir raiz\n");
    printf("2. Inserir no esquerdo\n");
    printf("3. Inserir no direito\n");
    printf("4. Verificar se eh BST\n");
    printf("5. Sair\n");

    do{
        printf("\nEscolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                printf("Digite o valor para a raiz: ");
                scanf("%d", &valor);
                raiz = criarNo(valor);
                break;

            case 2:
                if (raiz == NULL){
                    printf("Crie a raiz primeiro\n");
                } else {
                    printf("Digite o valor para o no esquerdo: ");
                    scanf("%d", &valor);
                    raiz = inserirNo(raiz, valor, 'e');
                }
                break;

            case 3:
                if (raiz == NULL){
                    printf("Crie a raiz primeiro\n");
                }else{
                    printf("Digite o valor para o no direito: ");
                    scanf("%d", &valor);
                    raiz = inserirNo(raiz, valor, 'd');
                }
                break;

            case 4:
                if (raiz == NULL){
                    printf("Arvore vazia\n");
                }else{
                    printf("Arvore em ordem: ");
                    imprimirEmOrdem(raiz);
                    printf("\n");

                    if (ehBST(raiz)){
                        printf("A arvore e uma BST\n");
                    }else{
                        printf("A arvore nao e uma BST\n");
                    }
                }
                break;

            case 5:
                printf("Saindo\n");
                break;

            default:
                printf("Opcao invalida\n");
        }
    }while (opcao != 5);

    return 0;
}
