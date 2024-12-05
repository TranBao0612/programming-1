#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// define your swap function here
// reverse array function
void swap(int *arr, int a, int b) {
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

void reverse_array(int *arr, int N)
{
    int attempt = floor(N/2);
    for(int i = 0; i < attempt; i++) {
        swap(arr, i, N-1-i);
    }

    // use your swap function
}

int main()
{
    int arr[] = {1, 4, 3, 7, 6};
    reverse_array(arr, 5);

    for(int i = 0; i<5; i++) {
        printf("%d ", arr[i]);
    }

    return 0; // set break point
}