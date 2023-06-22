#include <stdio.h>
#include <stdlib.h>

void countingSortAscending(int* array, int size) {
    // Encontra o valor máximo no array
    int max = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }

    // Cria um array de contagem com tamanho baseado no valor máximo
    int countSize = max + 1;
    int* count = (int*)calloc(countSize, sizeof(int));

    // Conta a ocorrência de cada elemento no array original
    for (int i = 0; i < size; i++) {
        count[array[i]]++;
    }

    // Atualiza o array original com os elementos ordenados
    int index = 0;
    for (int i = 0; i < countSize; i++) {
        while (count[i] > 0) {
            array[index++] = i;
            count[i]--;
        }
    }

    free(count);
}

void countingSortDescending(int* array, int size) {
    // Encontra o valor máximo no array
    int max = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }

    // Cria um array de contagem com tamanho baseado no valor máximo
    int countSize = max + 1;
    int* count = (int*)calloc(countSize, sizeof(int));

    // Conta a ocorrência de cada elemento no array original
    for (int i = 0; i < size; i++) {
        count[array[i]]++;
    }

    // Atualiza o array original com os elementos ordenados em ordem decrescente
    int index = size - 1;
    for (int i = countSize - 1; i >= 0; i--) {
        while (count[i] > 0) {
            array[index--] = i;
            count[i]--;
        }
    }

    free(count);
}

void printArr(int* array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int arraySize = 20;
    int array[] = {20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    printf("Array original:\n");
    printArr(array, arraySize);
    printf("\n");

    countingSortAscending(array, arraySize);

    printf("Array ordenado em ordem crescente:\n");
    printArr(array, arraySize);

    countingSortDescending(array, arraySize);

    printf("Array ordenado em ordem decrescente:\n");
    printArr(array, arraySize);

    return 0;
}
