#include <stdio.h>
#include <time.h>
#include <stdbool.h>

void testCase(int);

void shellSort(int*, int);

void shellSort(int* array, int size) {
    printf("Shellsort\n");
    clock_t start_time = clock(); // Captura o tempo de início da execução
    int comparisons = 0;
    int swaps = 0;

    int gap = size / 2 + 1;
    while (gap > 0)
    {
        for (size_t i = 0; i < size - gap; i++)
        {
            comparisons++;
            if (array[i] > array[i + gap])
            {
                swaps++;
                int temp = array[i];
                array[i] = array[i + gap];
                array[i + gap] = temp;
            }
            
        }
        gap /= 2;
    }

    clock_t end_time = clock(); // Captura o tempo de fim da execução

    double execution_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;    
    printSortStats(comparisons, swaps, execution_time, true, 3, true);
}

void gptshellSort(int* array, int size) {
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

            while (j >= gap && array[j - gap] > temp) {
                array[j] = array[j - gap];
                j -= gap;
            }
            
            array[j] = temp;
        }
        
        gap /= 2;
    }
    clock_t end_time = clock(); // Captura o tempo de fim da execução

    double execution_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;    
    printSortStats(comparisons, swaps, execution_time, true, 3, true);
}


void bubbleSort(int* array, int size) {
// Função de BubbleSort
    clock_t start_time = clock(); // Captura o tempo de início da execução

    int comparisons = 0;
    int swaps = 0;

    // Loop de Acesso
    for (int step = 0; step < size - 1; ++step) {

        // Comparação dos Elementos
        for (int i = 0; i < size - step - 1; ++i) {

        // Comparação de Elementos Adjacentes
        comparisons++;
            if (array[i] > array[i + 1]) {

                // Realiza a troca
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
                swaps++;
            }
        }
    }

    clock_t end_time = clock(); // Captura o tempo de fim da execução

    double execution_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("bubble Sort\n");
    printSortStats(comparisons, swaps, execution_time, true, 4, true);
}

void printArray(int array[], int size) {
// Print array
  for (int i = 0; i < size; ++i) {
    printf("%d  ", array[i]);
  }
  printf("\n");
}

int main() {
    int data[] = {20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

  // Tamanho do Array
    int size = sizeof(data) / sizeof(data[0]);

//   bubbleSort(data, size); <-- ignore this line 
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

