#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int **get_matrix(int n)
{
    int len = 0;
    int **matrix = malloc(sizeof(int *) * n);
    for (int i = 0; i < n; i++)
    {
        len = rand() % 10 + 1;
        matrix[i] = malloc(sizeof(int) * (len + 1));
        matrix[i][0] = len;
        for (int j = 1; j <= len; j++)
            matrix[i][j] = rand() % 100;
    }
    return matrix;
}

void print_matrix(int **matrix, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Number of elements in %d string = %d\n", i + 1, matrix[i][0]);
        for (int j = 1; j <= matrix[i][0]; j++)
        {
            printf("%d|", matrix[i][j]);
        }
        printf("\n");
    }
}

void free_matrix(int **matrix, int n)
{
    for (int i = 0; i < n; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
}

int main()
{
    srand(time(NULL));
    int n = 0;
    scanf("%d", &n);
    int **matrix = get_matrix(n);
    print_matrix(matrix, n);
    free_matrix(matrix, n);
    return 0;
}