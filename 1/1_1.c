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

int main()
{
    int size = rand() % 10;
    int maxValue = 100;
    int *arr = getRandArray(size, maxValue);
    print(arr);
    free(arr);
    return 0;
}