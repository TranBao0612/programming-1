#include <math.h>
#include <stdlib.h>
#include <stdio.h>

int* toBinary(int n, int* returnSize)
{
    // allocate integer array for output
    int size;

    if (n<0) {
        printf("Negative integer not supported.");
        return NULL;
    }
    else if(n == 0) {
        size = 1;
    }
    else {
        size = (int)floor(log2(n)) + 1;
    }

    int* out = malloc(size * sizeof(int));
    *returnSize = size;

    // your implementation: convert to binary (assign result -> out)
    // for loop
    for(int i=size-1; i>=0; i--) {
        out[i] = n % 2;
        n /= 2;
    }

    /* While and do while
    int i = size -1;
    // While
    while(i>=0) {
        out[i] = n % 2;
        n /= 2;
        i--;
    }
    // Do while
    do {
        out[i] = n % 2;
        n /= 2;
        i--;
    } while (i>=0);
    */

    return out;
}


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* evenOddBit(int n, int* returnSize) {
    if (n<0) {
        printf("Negative integer not supported.");
        return NULL;
    }

    int* out = malloc(2 * sizeof(int));

    int binSize;
    int* bin = toBinary(n, &binSize);

    // your implementation
    int countOdd = 0;

    for(int i = 0; i < binSize; i++) {
        if (bin[i] == 1) countOdd ++;
    }

    out[0] = countOdd;
    out[1] = binSize - countOdd;


    free(bin);
    return out;
}

int main()
{   
    /* Test replace '17' in line 72 w/ 'a'
    int a;
    printf("Enter a number: ");
    scanf("%i", &a);
    */

    int retSize;
    int* ret = evenOddBit(17, &retSize);

    printf("Odd: %d, Even: %d.", ret[0], ret[1]);

    free(ret);
    return 0;
}