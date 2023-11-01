// Assignment 2

#include <stdio.h>
#include <stdlib.h>

void reverse(int *arr, int size){
    int start = 0;
    int end = size - 1;

    while (start < end){
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

int main(){
    int arr[5];
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Enter the array elements:\n");
    for (int i = 0; i < size; i++){
        scanf("%d", &arr[i]);
    }
    reverse(arr, size);

    printf("The array elements:\n");
    for (int i = 0; i < size; i++){
        printf("%d\n", arr[i]);
    }

    return 0;
}