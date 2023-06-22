#include <stdio.h>

// Função para trocar os valores de dois elementos
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Função para imprimir uma permutação do vetor
void printPermutation(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Função para gerar permutações recursivamente
void generatePermutations(int arr[], int start, int end, int size) {
    if (start == size - 1) {
        printPermutation(arr, size);
        return;
    }

    for (int i = start; i < end; i++) {
        swap(&arr[start], &arr[i]);
        generatePermutations(arr, start + 1, end, size);
        swap(&arr[start], &arr[i]); // Revertendo a troca para manter o vetor original
    }
}

// Função para imprimir todas as permutações de um vetor de inteiros
void printAllPermutations(int arr[], int size) {
    generatePermutations(arr, 0, size, size);
}

// Exemplo de uso
int main() {
    int arr[] = {1, 2, 3};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Permutações do vetor: \n");
    printAllPermutations(arr, size);

    return 0;
}