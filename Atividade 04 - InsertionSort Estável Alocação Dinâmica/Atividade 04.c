#include <stdio.h>
#include <stdlib.h>

void insertionSort(int *arr, int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        
        // Move os elementos maiores que a chave para a direita
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        
        // Insere a chave na posição correta
        arr[j + 1] = key;
    }
}

int main() {
    int size;
    printf("Digite o tamanho do array: ");
    scanf("%d", &size);
    
    int *arr = (int *)malloc(size * sizeof(int));
    
    if (arr == NULL) {
        printf("Falha na alocacao de memoria.\n");
        return 1;
    }
    
    printf("Digite os elementos do array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    
    insertionSort(arr, size);
    
    printf("Array ordenado:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    free(arr); // Liberar a memória alocada
    
    return 0;
}




