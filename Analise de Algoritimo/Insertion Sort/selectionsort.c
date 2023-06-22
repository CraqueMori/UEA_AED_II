#include <stdio.h>

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSortAscending(int arr[], int n)
{
    int i, j, min_idx;
    int comparisons = 0;
    int swaps = 0;

    for (i = 0; i < n - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < n; j++)
        {
            comparisons++;
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }

        if (min_idx != i)
        {
            swap(&arr[min_idx], &arr[i]);
            swaps++;
        }
    }

    printf("Número total de comparações (Ordem Crescente): %d\n", comparisons);
    printf("Número total de trocas (Ordem Crescente): %d\n", swaps);
}

void selectionSortDescending(int arr[], int n)
{
    int i, j, max_idx;
    int comparisons = 0;
    int swaps = 0;

    for (i = 0; i < n - 1; i++)
    {
        max_idx = i;
        for (j = i + 1; j < n; j++)
        {
            comparisons++;
            if (arr[j] > arr[max_idx])
                max_idx = j;
        }

        if (max_idx != i)
        {
            swap(&arr[max_idx], &arr[i]);
            swaps++;
        }
    }

    printf("Número total de comparações (Ordem Decrescente): %d\n", comparisons);
    printf("Número total de trocas (Ordem Decrescente): %d\n", swaps);
}

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int arr[] = {20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};
    int arr2[] = {20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};

    int n = sizeof(arr) / sizeof(arr[0]);
    int n2 = sizeof(arr2) / sizeof(ar2r[0]);

    // Ordenação Crescente
    selectionSortAscending(arr, n);
    printf("Array Ordenado em ordem Crescente:\n");
    printArray(arr, n);

    // Ordenação Decrescente
    selectionSortDescending(arr2, n2);
    printf("Array Ordenado em ordem Decrescente:\n");
    printArray(arr2, n2);

    return 0;
}
