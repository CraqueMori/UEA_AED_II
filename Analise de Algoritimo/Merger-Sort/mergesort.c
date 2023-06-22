#include <stdio.h>
#include <stdlib.h>

int comparisons = 0;
int swaps = 0;

void intercala(int* array, int start, int middle, int end) {
    int temp[end - start];

    int i = start;
    int j = middle;
    int k = 0;

    while (i < middle && j < end) {
        comparisons++;
        if (array[i] <= array[j]) {
            temp[k++] = array[i++];
        }
        else {
            temp[k++] = array[j++];
            swaps++;
        }
    }

    while (i < middle)
    {
        temp[k++] = array[i++];
    }
    
    while (j < end)
    {
        temp[k++] = array[j++];
    }

    for (i = start; i < end; i++) {
        array[i] = temp[i - start];
    }
}

void mergeSortRecursive(int* array, int start, int end){
    if (start < end - 1) {
        int middle = (start + end) / 2;
        mergeSortRecursive(array, start, middle);
        mergeSortRecursive(array, middle, end);
        intercala(array, start, middle, end);
    }
}

void mergeSort(int* array, int size) {
    if (size > 1) {
        mergeSortRecursive(array, 0, size);
    }
}

void printArr(int* array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void mergeSortDescending(int* array, int size) {
    mergeSort(array, size);
    // Inverte a ordem do array para obter a ordem decrescente
    for (int i = 0; i < size / 2; i++) {
        int temp = array[i];
        array[i] = array[size - i - 1];
        array[size - i - 1] = temp;
    }
}

int main() {
    int arrSize = 8;
    int array[] = {20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    printf("Array original:\n");
    printArr(array, arrSize);
    printf("\n");
    
    //troca para mergesort caso queira o normal
    //mergeSort()
    mergeSortDescending(array, arrSize);

    printf("Array ordenado em ordem decrescente:\n");
    printArr(array, arrSize);
    printf("Número total de comparações: %d\n", comparisons);
    printf("Número total de trocas: %d\n", swaps);

    return 0;
}
