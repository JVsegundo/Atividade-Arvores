#include <stdio.h>

int soma(int lista[], int n){
    if (n == 0){
        return 0;
    }
    return lista[n - 1] + soma(lista, n - 1);
}

int main(){
    int n;

    printf("Digite o tamanho da lista:\n");
    scanf("%d", &n);

    int lista[n];
    printf("Digite os %d numeros da lista:\n");
    for(int i = 0; i < n; i++){
        scanf("%d", &lista[i]);
    }

    printf("Soma dos elementos: %d\n", soma(lista, n));
    return 0;
}

