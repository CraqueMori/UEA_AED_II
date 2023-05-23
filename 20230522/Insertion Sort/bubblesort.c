// Bubble sort in C

#include <stdio.h>

// Função de BubbleSort
void bubbleSort(int array[], int size) {

  // Loop de Acesso 
  for (int step = 0; step < size - 1; ++step) {
      
    // Comparação dos Elementos
    for (int i = 0; i < size - step - 1; ++i) {
      
      // Comparação de Elementos Adjacentes
      if (array[i] > array[i + 1]) {
        
        // realiza a troca
        int temp = array[i];
        array[i] = array[i + 1];
        array[i + 1] = temp;
      }
    }
  }
}

// print array
void printArray(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d  ", array[i]);
  }
  printf("\n");
}

int main() {
  int data[] = {-2, 45, 0, 11, -9};
  
  // Tamanho do Array
  int size = sizeof(data) / sizeof(data[0]);

  bubbleSort(data, size);
  
  printf("Array Ordenado na ordem Crescente:\n");
  printArray(data, size);
}