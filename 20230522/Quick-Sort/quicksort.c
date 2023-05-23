#include <stdio.h>
#include <stdlib.h>

int partition(int* array, int start, int end) {
    int temp;
    int pivot = array[end];
    int i = start - 1;

    // Leva os valores maiores que o pivô para depois de I
    for (int j = start; j <= end - 1; j++)
    {
        if (array[j] <= pivot)
        {
            i++;
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }

    // Retorna o novo pivô
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
    return;
}

void quickSort(int* array, int arraySize) {
    quickSortRecursion(array, 0, arraySize - 1);
    return;
}

void printArr(int* array, int size) {
    for (int i=0; i < size; i++) printf("%d ", array[i]);
    printf("\n");
    return;
}

int main() {
    int arraySize = 10;
    int array[] = {19, 8, 5, 10, 4, 18, 4, 6, 14, 2};
    printArr(array, arraySize);

    printf("\n");
    quickSort(array, arraySize);

    printArr(array, arraySize);
    printf("\n");
    return 1;
}