// C program for implementation of selection sort
#include <stdio.h>

//Definição de Temp
void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void selectionSort(int arr[], int n)
{
	int i, j, min_idx;

	for (i = 0; i < n-1; i++)
	{
		// Encontre o elemento mínimo no array não ordenado
		min_idx = i;
		for (j = i+1; j < n; j++)
		if (arr[j] < arr[min_idx])
			min_idx = j;

		// Troque o elemento mínimo encontrado com o primeiro elemento
		if(min_idx != i)
			swap(&arr[min_idx], &arr[i]);
	}
}

//Função de Impressão de Array
void printArray(int arr[], int size)
{
	int i;
	for (i=0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

int main()
{
    //Array
	int arr[] = {64, 25, 12, 22, 11};
    // Tamanho do Array
	int n = sizeof(arr)/sizeof(arr[0]);

    //Chama a Função
	selectionSort(arr, n);

	printf("Array Ordenado: \n");
	printArray(arr, n);
	return 0;
}
