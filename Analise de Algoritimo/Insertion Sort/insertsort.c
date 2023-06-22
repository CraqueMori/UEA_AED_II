#include <stdio.h>

void insertionSortAscending(int* array, int size) {
    for (int i = 1; i < size; i++) {
        int key = array[i];
        int j = i - 1;

        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j--;
        }

        array[j + 1] = key;
    }
}

void insertionSortDescending(int* array, int size) {
    for (int i = 1; i < size; i++) {
        int key = array[i];
        int j = i - 1;

        while (j >= 0 && array[j] < key) {
            array[j + 1] = array[j];
            j--;
        }

        array[j + 1] = key;
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

    insertionSortAscending(array, arraySize);

    printf("Array ordenado em ordem crescente:\n");
    printArray(array, arraySize);

    insertionSortDescending(array, arraySize);

    printf("Array ordenado em ordem decrescente:\n");
    printArray(array, arraySize);

    return 0;
}
