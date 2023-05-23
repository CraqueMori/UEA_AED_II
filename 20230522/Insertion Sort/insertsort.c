// C program for insertion sort
#include <math.h>
#include <stdio.h>
 
/* Function to sort an array using insertion sort*/
void insertionSort(int arr[], int n)
{
    // Declaração das Variaveis
    int i, chave, j;
    
    //Declaração For para organizar os elementos de posição
    for (i = 1; i < n; i++) {
        chave = arr[i];
        j = i - 1;
        
        /* Movendo os elementos I que são maior que chave,
           para sua posição*/
        while (j >= 0 && arr[j] > chave) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = chave;
    }
}
 
// Função Generica para imprimir Arrays
void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
 
// Rodando o Algortimo
int main()
{
    //Declaração Array
    int arr[] = { 12, 11, 13, 5, 6 };
    //Calcula Tamanho do Array
    int n = sizeof(arr) / sizeof(arr[0]);
    
    //Chama as Funções
    insertionSort(arr, n);
    printArray(arr, n);
 
    return 0;
}