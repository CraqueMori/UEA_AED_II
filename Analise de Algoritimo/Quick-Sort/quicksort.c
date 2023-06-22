#include <stdio.h>
#include <stdlib.h>

int comparisons = 0;
int swaps = 0;

int partition(int* array, int start, int end) {
    int temp;
    int pivot = array[end];
    int i = start - 1;

    for (int j = start; j <= end - 1; j++) {
        comparisons++;
        if (array[j] >= pivot) {
            i++;
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            swaps++;
        }
    }

    temp = array[i + 1];
    array[i + 1] = array[end];
    array[end] = temp;
    return i + 1;
}

void quickSortRecursion(int* array, int start, int end) {
    if (end > start) {
        int pivot = partition(array, start, end);
        quickSortRecursion(array, start, pivot - 1);
        quickSortRecursion(array, pivot + 1, end);
    }
}

void quickSort(int* array, int arraySize) {
    quickSortRecursion(array, 0, arraySize - 1);
}

void printArr(int* array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void quickSortDescending(int* array, int arraySize) {
    quickSort(array, arraySize);
    // Inverte a ordem do array para obter a ordem decrescente
    for (int i = 0; i < arraySize / 2; i++) {
        int temp = array[i];
        array[i] = array[arraySize - i - 1];
        array[arraySize - i - 1] = temp;
    }
}

int main() {
    int arraySize = 20;
    int array[] = {20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    printf("Array original:\n");
    printArr(array, arraySize);
    printf("\n");
    //Troca para quicksort, caso queira crescente
    //quickSort()
    quickSortDescending(array, arraySize);

    printf("Array ordenado em ordem decrescente:\n");
    printArr(array, arraySize);
    printf("Número total de comparações: %d\n", comparisons);
    printf("Número total de trocas: %d\n", swaps);

    return 0;
}
