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
    int arr[5];
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Enter the array elements:\n");
    for (int i = 0; i < size; i++){
        scanf("%d", &arr[i]);
    }

    int missing=findMissingNumber(arr,size);

    if(missing==-1){
        printf("No Missing\n");
    }else{
        printf("Missing: %d\n",missing);
    }
}