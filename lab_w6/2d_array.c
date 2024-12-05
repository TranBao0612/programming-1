#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <assert.h>


int max(int a, int b)
{
    return (a >= b) ? a : b;
}

int min(int a, int b)
{
    return (a < b) ? a : b;
}

int sum(int a, int b)
{
    return a + b;
}

/**
 * Write reduce function where func is one of "max", "min", "sum"
 * Return func(array)
*/
int reduce(int** arr, int N, int M, const char* func)
{
    assert(N > 0 && M > 0);
    
    int ans = arr[0][0];
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(i==0 && j==0) continue;
            
            if (strcmp(func, "max") == 0) ans = max(ans, arr[i][j]);
            else if (strcmp(func, "min") == 0) ans = min(ans, arr[i][j]);
            else if (strcmp(func, "sum") == 0) ans = sum(ans, arr[i][j]);
            else {
                printf("Wrong operation code!");
                exit(1);
            }
        }
    }
    
    return ans;
    
    // your code here
}




/**
 * Write reduce function by axis where func is one of "max", "min", "sum"
 * The return value should be 1-dimensional array
 * Return func(array, axis)
*/

int* reduce_with_axis(int** arr, int N, int M, const char* func, int axis)
{
    assert(N > 0 && M > 0);

    int* out;
    if(axis == 0) {
        out = malloc(N * sizeof(int));
        if (out == NULL) {
            printf("Memory allocation failed!\n");
            exit(1);
        }
        for(int i = 0; i < N; i++) {
            int ans = arr[i][0];
            for(int j = 1; j < M; j ++) {
                if (strcmp(func, "max") == 0) ans = max(ans, arr[i][j]);
                else if (strcmp(func, "min") == 0) ans = min(ans, arr[i][j]);
                else if (strcmp(func, "sum") == 0) ans = sum(ans, arr[i][j]);
                else {
                    printf("Wrong operation code!");
                    exit(1);
                }
            }
            out[i] = ans;
            printf("%d ", out[i]);
        }
    } else if (axis == 1) {
        out = malloc(M * sizeof(int));
        if (out == NULL) {
            printf("Memory allocation failed!\n");
            exit(1);
        }
        
        for(int j = 0; j < M; j++) {
            int ans = arr[0][j];
            for(int i = 1; i < N; i++) {
                if (strcmp(func, "max") == 0) ans = max(ans, arr[i][j]);
                else if (strcmp(func, "min") == 0) ans = min(ans, arr[i][j]);
                else if (strcmp(func, "sum") == 0) ans = sum(ans, arr[i][j]);
                else {
                    printf("Wrong operation code!");
                    exit(1);
                }
            }
            out[j] = ans;
            printf("%d ", out[j]);
        }
    } else {
        printf("Axis not exist.");
        exit(1);
    }
    // allocate 1d array

    // return the reduced array
    return out;
}





/**
 * Write transpose function to transpose NxM array -> MxN array
*/
int** transpose(int** two_array, int N, int M)
{
    int** trans = malloc(M * sizeof(int*)); 
    if (trans == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    
    for (int i = 0; i < M; i++)
    {
        trans[i] = malloc(N * sizeof(int));
        if (trans[i] == NULL) {
            printf("Memory allocation failed!\n");
            exit(1);
        }
    }
    
    // allocate MxN array
    
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            trans[i][j] = two_array[j][i];
        }
    }
    // return the transposed array
    
    return trans;
}


int main()
{
    // set random seed to current time
    srand(time(NULL));

    int N = 3, M = 4;
    // allocate NxM array
    int** two_array = malloc(N * sizeof(int*)); // allocate N x (int *)
    for (int i = 0; i < N; i++)
    {
        two_array[i] = malloc(M * sizeof(int)); // allocate M x (int)

        // set random value (0->9) for each element of array
        for (int j = 0; j < M; j++)
        {
            two_array[i][j] = rand() % 10;
            // printf("array[%d][%d] = %d\n", i, j, two_array[i][j]);
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            printf("%d ", two_array[i][j]);
        }
        printf("\n");
    }

    printf("There are %d rows and %d columns.\n", N, M);
    
    
    int reduced = reduce(two_array, N, M, "max");
    printf("%d \n", reduced);
    
    
    int* reduced_axis = reduce_with_axis(two_array, N, M, "max", 0);
    printf("\n\n");

    int** transposed_array = transpose(two_array, N, M);
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            printf("%d ", transposed_array[i][j]);
        }
        printf("\n");
    }
    

    return 0;
}