#include <stdio.h>

void shellSortAscending(int* array, int size) {
    for (int gap = size / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < size; i++) {
            int temp = array[i];
            int j;

            for (j = i; j >= gap && array[j - gap] > temp; j -= gap) {
                array[j] = array[j - gap];
            }

            array[j] = temp;
        }
    }
}

void shellSortDescending(int* array, int size) {
    for (int gap = size / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < size; i++) {
            int temp = array[i];
            int j;

            for (j = i; j >= gap && array[j - gap] < temp; j -= gap) {
                array[j] = array[j - gap];
            }

            array[j] = temp;
        }
    }
}

void printArray(int* array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int arraySize = 20;
    int array[] = {20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    printf("Array original:\n");
    printArray(array, arraySize);
    printf("\n");
    //Apague o comentário para utilizar a função
    //shellSortAscending(array, arraySize);

    printf("Array ordenado em ordem crescente:\n");
    printArray(array, arraySize);
    
    //Apague o comentário para utilizar a função
    //shellSortDescending(array, arraySize);

    printf("Array ordenado em ordem decrescente:\n");
    printArray(array, arraySize);

    return 0;
}
