#include <stdio.h>
#include <time.h>
#include <stdbool.h>

// Declaração de funções
void shellSort(int*, int);
void printArray(int*, int);
void printSortStats(int, int, double, bool, int, bool);


void shellSort(int* array, int size) {
    printf("Shellsort\n");
    clock_t start_time = clock(); // Captura o tempo de início da execução
    int comparisons = 0;
    int swaps = 0;
    
    int gap = size / 2;
    int i, j, temp;

    while (gap > 0) {
        for (i = gap; i < size; i++) {
            temp = array[i];
            j = i;

            comparisons++;
            //verifica em intervalos de tamanho gap, se há um número maior que temp;
            while (j >= gap && array[j - gap] > temp) {
                if (j != i) comparisons++;
                swaps++;
                array[j] = array[j - gap];
                j -= gap;
            }
            
            array[j] = temp;
        }
        
        gap /= 2;
    }
    clock_t end_time = clock(); // Captura o tempo de fim da execução

    double execution_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;    
    printSortStats(comparisons, swaps, execution_time, false, 3, true);
}

void printArray(int* array, int size) {
// Print array
  for (int i = 0; i < size; ++i) {
    printf("%d  ", array[i]);
  }
  printf("\n");
}

int main() {
    int data[] = {38, 53, 57, 59, 91, 77, 11, 38, 60, 54, 80, 2, 5, 30, 9, 63, 70, 19, 34, 93, 45, 65, 57, 31, 45, 3, 57, 64, 63, 57, 91, 43, 60, 53, 13, 18, 17, 36, 56, 71, 82, 21, 41, 59, 2, 98, 22, 43, 27, 59, 75, 39, 86, 85, 87, 81, 6, 1, 37, 1, 94, 55, 27, 42, 12, 52, 92, 81, 52, 18, 87, 66, 83, 96, 57, 42, 32, 42, 2, 62, 61, 48, 76, 11, 33, 81, 17, 52, 67, 87, 48, 66, 65, 100, 14, 97, 90, 85, 44, 74};

    // Tamanho do Array
    int size = sizeof(data) / sizeof(data[0]);

    //bubbleSort(data, size); <-- ignore this line 
    shellSort(data, size);
    printArray(data, size);

    return 0;
}

void printSortStats(int comparisons, int swaps, double time, bool stable, int timeComplexity, bool inPlace) {
    printf("==================================================\n");
    printf("O algoritmo realizou %d comparações.\n", comparisons);
    printf("O algoritmo realizou %d trocas.\n", swaps);
    printf("O tempo de execução do algoritmo foi de %f segundos.\n" , time);
    if (stable == true) {
        printf("O algoritmo é estável.\n");
    }
    else {
        printf("O algoritmo não é estável.\n");
    }
    
    printf("O algoritmo possui complexidade ");
    switch (timeComplexity) {
        case 0:
            printf("O(1).\n");
            break;

        case 1:
            printf("O(log(n)).\n");
            break;

        case 2:
            printf("O(n).\n");
            break;

        case 3:
            printf("O(nlog(n)).\n");
            break;

        case 4:
            printf("O(n2).\n");
            break;

        case 5:
            printf("O(nx).\n");
            break;

        case 6:
            printf("O(2^n).\n");
            break;
    }

    if (inPlace == true) {
        printf("O algoritmo é in place\n");
    }
    else {
        printf("O algoritmo não é in place");
    }
    printf("==================================================\n");
}
