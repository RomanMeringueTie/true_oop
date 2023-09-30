#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 5

int **get_matrix(int n)
{
    int **matrix = malloc(n * sizeof(void *));
    for (int i = 0; i < n; i++)
    {
        matrix[i] = malloc(n * sizeof(int));
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matrix[i][j] = rand() % 10;
        }
    }
    return matrix;
}

int *get_array(int n)
{
    int *array = malloc(n * sizeof(int));
    return array;
}

void print_matrix(int **matrix, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d|", matrix[i][j]);
        }
        printf("\n");
    }
}

void print_array(int *array, int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", array[i]);
    printf("\n");
}

void right_diagonals(int **matrix, int *array, int n)
{
    int index = 0;
    for (int c = 0; c < n; c++)
    {
        for (int i = n - 1, j = c; j < n && i >= 0; i--, j++)
        {
            array[index++] = matrix[j][i];
        }
    }
    for (int r = 0; r < n; r++)
    {
        for (int i = r, j = 0; j < n && i >= 0; i--, j++)
        {
            array[index++] = matrix[j][i];
        }
    }
}

void left_diagonals(int **matrix, int *array, int n)
{
    int index = 0;
    for (int c = 0; c < n; c++)
    {
        for (int i = n - 1, j = c; j < n && i >= 0; i--, j++)
        {
            array[index++] = matrix[j][n - i - 1];
        }
    }
    for (int r = 0; r < n; r++)
    {
        for (int i = r, j = 0; j < n && i >= 0; i--, j++)
        {
            array[index++] = matrix[j][n - i - 1];
        }
    }
}

void out_spiral(int **matrix, int *array, int n)
{
    int index = 0;
    int top = 0, bottom = n - 1, left = 0, right = n - 1;
    int dir = 1;
    while (top <= bottom && left <= right)
    {
        if (dir == 1)
        {
            for (int i = left; i <= right; ++i)
            {
                array[index++] = matrix[top][i];
            }
            ++top;
            dir = 2;
        }
        else if (dir == 2)
        {
            for (int i = top; i <= bottom; ++i)
            {
                array[index++] = matrix[i][right];
            }
            --right;
            dir = 3;
        }
        else if (dir == 3)
        {
            for (int i = right; i >= left; --i)
            {
                array[index++] = matrix[bottom][i];
            }
            --bottom;
            dir = 4;
        }
        else if (dir == 4)
        {
            for (int i = bottom; i >= top; --i)
            {
                array[index++] = matrix[i][left];
            }
            ++left;
            dir = 1;
        }
    }
}

void in_spiral(int **matrix, int *array, int n)
{
    int index = 0;
    int top = 0, bottom = n - 1, left = 0, right = n - 1;
    int dir = 1;
    while (top <= bottom && left <= right)
    {
        if (dir == 1)
        {
            for (int i = left; i <= right; ++i)
            {
                array[n*n - index++ - 1] = matrix[top][i];
            }
            ++top;
            dir = 2;
        }
        else if (dir == 2)
        {
            for (int i = top; i <= bottom; ++i)
            {
                array[n*n - index++ - 1] = matrix[i][right];
            }
            --right;
            dir = 3;
        }
        else if (dir == 3)
        {
            for (int i = right; i >= left; --i)
            {
                array[n*n - index++ - 1] = matrix[bottom][i];
            }
            --bottom;
            dir = 4;
        }
        else if (dir == 4)
        {
            for (int i = bottom; i >= top; --i)
            {
                array[n*n - index++ - 1] = matrix[i][left];
            }
            ++left;
            dir = 1;
        }
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
    int **matrix = get_matrix(N);
    print_matrix(matrix, N);
    int *array = get_array(N * N);
    // right_diagonals(matrix, array, N);
    // left_diagonals(matrix, array, N);
    // out_spiral(matrix, array, N);
    in_spiral(matrix, array, N);
    print_array(array, N * N);
    free_matrix(matrix, N);
    free(array);
    return 0;
}
