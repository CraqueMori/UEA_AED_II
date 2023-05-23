#include <stdio.h>
#include <stdlib.h>

void intercala(int* array, int start, int middle, int end) {
    int temp[end - start];

    int i = start;
    int j = middle;
    int k = 0;

    while (i < middle && j < end) {
        if (array[i] <= array[j]) {
            temp[k++] = array[i++];
        }
        else {
            temp[k++] = array[j++];
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
    
    return;
}

void mergeSort(int* array) {
    if (0 < sizeof(array) - 1) {
        int middle = (0 + sizeof(array)) / 2;
        mergeSortRecursive(array, 0, sizeof(array));
    }
    return;
}


void printArr(int* array) {
    int size = sizeof array;

    for (int i=0; i < size; i++) printf("%d ", array[i]);
    printf("\n");
    return;
}

int main() {
    int arrSize = 8;
    int array[] = {2, 8, 3, 4, 3, 7, 1, 9};

    printArr(array);

    printf("\n");
    mergeSort(array);

    for (int i = 0; i < arrSize; i++) {
        printf("%d ", *(array + i));
    }
    printf("\n");
    return 1;
}