#include <stdio.h>

// Função de BubbleSort
void bubbleSort(int array[], int size) {
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
#include <stdio.h>

// Função de BubbleSort para ordenação crescente
void bubbleSortAscending(int array[], int size) {
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

  printf("Número total de comparações: %d\n", comparisons);
  printf("Número total de trocas: %d\n", swaps);
}

// Função de BubbleSort para ordenação decrescente
void bubbleSortDescending(int array[], int size) {
  int comparisons = 0;
  int swaps = 0;

  // Loop de Acesso 
  for (int step = 0; step < size - 1; ++step) {
      
    // Comparação dos Elementos
    for (int i = 0; i < size - step - 1; ++i) {
      
      // Comparação de Elementos Adjacentes
      comparisons++;
      if (array[i] < array[i + 1]) {
        
        // Realiza a troca
        int temp = array[i];
        array[i] = array[i + 1];
        array[i + 1] = temp;
        swaps++;
      }
    }
  }

  printf("Número total de comparações: %d\n", comparisons);
  printf("Número total de trocas: %d\n", swaps);
}

// Print array
void printArray(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d  ", array[i]);
  }
  printf("\n");
}

int main() {
  int data[] = {20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};
  
  // Tamanho do Array
  int size = sizeof(data) / sizeof(data[0]);

  // Ordenação Crescente
  bubbleSortAscending(data, size);
  
  printf("Array Ordenado em ordem Crescente:\n");
  printArray(data, size);

  // Ordenação Decrescente
  bubbleSortDescending(data, size);

  printf("Array Ordenado em ordem Decrescente:\n");
  printArray(data, size);
  
  return 0;
}

  printf("Número total de comparações: %d\n", comparisons);
  printf("Número total de trocas: %d\n", swaps);
}

// Print array
void printArray(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d  ", array[i]);
  }
  printf("\n");
}

int main() {
  int data[] = {20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};
  
  // Tamanho do Array
  int size = sizeof(data) / sizeof(data[0]);

  bubbleSort(data, size);
  
  printf("Array Ordenado na ordem Crescente:\n");
  printArray(data, size);
  
  return 0;
}
