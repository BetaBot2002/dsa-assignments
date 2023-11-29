// Assignment 20

#include <stdio.h>
#include <stdlib.h>

void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void heapify(int *arr,int size,int rootIndex){
    int left=2*rootIndex+1;
    int right=2*rootIndex+2;
    int largest=rootIndex;

    if(left < size && arr[left]>arr[largest])
        largest=left;
    
    if(right < size && arr[right]>arr[largest])
        largest=right;

    if(largest != rootIndex){
        swap(&arr[rootIndex],&arr[largest]);
        heapify(arr,size,largest);
    }
}

void heapSort(int *arr,int size){
    for(int i=size/2-1;i>=0;i--){
        heapify(arr,size,i);
    }

    for(int i=size-1;i>=0;i--){
        swap(&arr[0],&arr[i]);
        heapify(arr,i,0);
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

    heapSort(arr, size);

    printf("Sorted array: ");
    printArray(arr, size);
    return 0;
}