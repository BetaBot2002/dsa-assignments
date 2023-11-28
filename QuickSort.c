// Assignment 19

#include <stdio.h>
#include <stdlib.h>

void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

int partition(int *arr,int low,int high){
    int pivotElement=arr[high];
    int mainIndex=low-1;

    for(int i=low;i<high;i++){
        if(arr[i]<=pivotElement){
            mainIndex++;
            swap(&arr[mainIndex],&arr[i]);
        }
    }
    swap(&arr[mainIndex+1],&arr[high]);
    return mainIndex+1;
}

void quickSort(int *arr,int low,int high){
    if(low<high){
        int pivotIndex=partition(arr,low,high);
        quickSort(arr,low,pivotIndex-1);
        quickSort(arr,pivotIndex+1,high);
    }
}

void printArray(int arr[], int size) {
  for (int i = 0; i < size; printf("%d ", arr[i++]));
  printf("\n");
}

int main(){
    int arr[] = {6, 5, 12, 10, 9, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("Unsorted Array: ");
    printArray(arr, size);

    quickSort(arr, 0, size - 1);

    printf("Sorted array: ");
    printArray(arr, size);
    return 0;
}