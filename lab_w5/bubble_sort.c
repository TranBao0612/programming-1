#include <stdlib.h>
#include <stdio.h>
// Sort ascending

// copy your swap function from reverse_array.c
void swap(int *arr, int a, int b) {
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}


void bubble_sort(int *arr, int N)
{
    for(int i = 1; i<N; i++) {
        if (arr[i-1] > arr[i]) {
            swap(arr, i-1, i);
        } 
    }
}

int main()
{
    int arr[] = {1, 4, 3, 7, 6};
    bubble_sort(arr, 5);

    for(int i = 0; i<5; i++) {
        printf("%d ", arr[i]);
    }

    return 0; // set break point
}