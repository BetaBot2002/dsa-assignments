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
    int size;
    printf("Enter the size of array:\n");
    scanf("%d",&size);

    int *arr=(int*)malloc(size*sizeof(int));

    printf("Enter the array elements:\n");
    for (int i = 0; i < size; i++){
       scanf("%d",&arr[i]);
    }

    printf("The array elements are:\n");
    for (int i = 0; i < size; i++){
       printf("%d\n",arr[i]);
    }

    int rotation;
    printf("Enter the times of rotation:\n");
    scanf("%d",&rotation);

    rotateArray(arr, size,rotation);

    printf("The array elements after rotation:\n");
    for (int i = 0; i < size; i++){
        printf("%d\n", arr[i]);
    }


    return 0;
}