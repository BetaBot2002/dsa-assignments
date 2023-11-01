// Assignment 4

#include <stdio.h>
#include <stdlib.h>

void rotateArray(int* arr,int size,int pos){
    int key;
    while (pos>0)
    {
        key=arr[size-1];
        for (int i = size-1; i>0; i--)
        {
            // printf("%d\n", arr[i]);
            // printf("%d\n", arr[i-1]);
            arr[i]=arr[i-1];
        }
        arr[0]=key;
        pos--;  
    }
}

int main(){
    int arr[5];
    int size=sizeof(arr)/sizeof(arr[0]);

    printf("Enter the array elements:\n");
    for (int i = 0; i < size; i++){
       scanf("%d",&arr[i]);
    }

    rotateArray(arr, size,2);

    printf("The array elements:\n");
    for (int i = 0; i < size; i++){
        printf("%d\n", arr[i]);
    }


    return 0;
}