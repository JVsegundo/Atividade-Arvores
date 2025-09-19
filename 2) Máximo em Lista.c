#include <stdio.h>

int maximo(int lista[], int inicio, int fim){
    if (inicio == fim){
        return lista[inicio];
    }
    int meio = (inicio + fim) / 2;
    int max_e = maximo(lista, inicio, meio);
    int max_d = maximo(lista, meio + 1, fim);

    return (max_e > max_d) ? max_e : max_d;
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

    printf("Maior elemento: %d\n", maximo(lista, 0, n - 1));
    return 0;
}
