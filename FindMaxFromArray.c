// Assignment 1

#include <stdio.h>
#include <stdlib.h>

int Max(int arr[],int size){
    int max=arr[0];
    for(int i=1;i<size;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    return max;
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

    printf("The maximum element of the array is: %d\n",Max(arr,size));

    return 0;
}

