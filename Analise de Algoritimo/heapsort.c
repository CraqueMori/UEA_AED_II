#include <stdio.h>

void heapify(int* array, int size, int root, int (*compare)(int, int)) {
    int largest = root;
    int left = 2 * root + 1;
    int right = 2 * root + 2;

    if (left < size && compare(array[left], array[largest]))
        largest = left;

    if (right < size && compare(array[right], array[largest]))
        largest = right;

    if (largest != root) {
        int temp = array[root];
        array[root] = array[largest];
        array[largest] = temp;

        heapify(array, size, largest, compare);
    }
}

void heapSort(int* array, int size, int (*compare)(int, int)) {
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(array, size, i, compare);

    for (int i = size - 1; i > 0; i--) {
        int temp = array[0];
        array[0] = array[i];
        array[i] = temp;

        heapify(array, i, 0, compare);
    }
}

int ascendingCompare(int a, int b) {
    return a < b;
}

int descendingCompare(int a, int b) {
    return a > b;
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

    heapSort(array, arraySize, ascendingCompare);

    printf("Array ordenado em ordem crescente:\n");
    printArray(array, arraySize);

    heapSort(array, arraySize, descendingCompare);

    printf("Array ordenado em ordem decrescente:\n");
    printArray(array, arraySize);

    return 0;
}
