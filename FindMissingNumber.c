// Assignment 5

#include <stdio.h>
#include <stdlib.h>

int findMissingNumber(int arr[],int size){
    for (int i = 0; i < size-1; i++)
    {
        if(arr[i+1]-arr[i]!=1){
            return arr[i]+1;
        }
    }
    return -1;
    
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

    int missing=findMissingNumber(arr,size);

    if(missing==-1){
        printf("No Missing\n");
    }else{
        printf("Missing: %d\n",missing);
    }
}