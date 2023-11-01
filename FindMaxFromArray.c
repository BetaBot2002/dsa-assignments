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

    int arr[5];
    int size=sizeof(arr)/sizeof(arr[0]);

    printf("Enter the array elements:\n");
    for (int i = 0; i < size; i++){
       scanf("%d",&arr[i]);
    }

    printf("%d\n",Max(arr,size));

    return 0;
}

