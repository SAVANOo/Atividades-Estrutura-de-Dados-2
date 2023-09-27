#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
    int originalIndex; // Para rastrear a posição original
} Element;

void swap(Element *a, Element *b) {
    Element temp = *a;
    *a = *b;
    *b = temp;
}

void stableSelectionSort(Element *array, int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (array[j].value < array[minIndex].value) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            // Realiza troca apenas se necessário
            if (array[minIndex].value != array[i].value) {
                swap(&array[i], &array[minIndex]);
            }
        }
    }
}

int main() {
    int size;

    printf("Digite o tamanho da matriz: ");
    scanf("%d", &size);

    Element *array = (Element *)malloc(size * sizeof(Element));

    if (array == NULL) {
        printf("Erro na alocacao de memoria\n");
        return 1;
    }

    printf("Digite os elementos da matriz:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &array[i].value);
        array[i].originalIndex = i; // Rastreamento da posição original
    }

    stableSelectionSort(array, size);

    printf("Matriz ordenada:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i].value);
    }
    printf("\n");

    printf("Posicoes originais:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i].originalIndex);
    }
    printf("\n");

    free(array);

    return 0;
}