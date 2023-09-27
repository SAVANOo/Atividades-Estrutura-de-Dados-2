#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int *array, int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (array[j] < array[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(&array[i], &array[minIndex]);
        }
    }
}

int main() {
    int size;
    
    printf("Digite o tamanho da matriz: ");
    scanf("%d", &size);

    int *array = (int *)malloc(size * sizeof(int));

    if (array == NULL) {
        printf("Erro na alocacao de memoria\n");
        return 1;
    }

    printf("Digite os elementos da matriz:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }

    selectionSort(array, size);

    printf("Matriz ordenada:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    free(array);

    return 0;
}
