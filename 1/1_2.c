#include <stdio.h>
#include <stdlib.h>

int *getRandArray(int size, int maxValue)
{
    int *array = malloc((size + 1) * sizeof(int));
    array[0] = size;
    for (int i = 1; i <= size; i++)
        array[i] = rand() % maxValue;
    return array;
}

void print(int *arr)
{
    printf("%d: ", arr[0]);
    for (int i = 1; i <= arr[0]; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int **getRandMatrix(int size, int maxValue)
{
    int **array = malloc(8 * size);
    for (int i = 0; i < size; i++)
        array[i] = getRandArray(rand() % 10, maxValue);
    return array;
}

void printMatrix(int **matrix, int size)
{
    printf("%d:\n", size);
    for (int i = 0; i < size; i++)
        print(matrix[i]);
}

int main()
{
    int size = rand() % 10;
    int maxValue = 100;
    int **matrix = getRandMatrix(size, maxValue);
    printMatrix(matrix, size);
    for (int i = 0; i < size; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
    return 0;
}
