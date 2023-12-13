// Assignment 18

#include <stdio.h>
#include <stdlib.h>

void merge(int *arr,int low,int mid,int high){
    int n1=mid-low+1;
    int n2=high-mid;

    int *arrLeft=(int*)malloc(n1*sizeof(int));
    int *arrRight=(int*)malloc(n2*sizeof(int));

    for(int i=0;i<n1;i++){
        arrLeft[i]=arr[low+i];
    }

    for(int j=0;j<n2;j++){
        arrRight[j]=arr[mid+1+j];
    }

    int leftIndex=0;
    int rightIndex=0;
    int mainIndex=low;

    while(leftIndex<n1 && rightIndex<n2){
        if(arrLeft[leftIndex] <= arrRight[rightIndex]){
            arr[mainIndex]=arrLeft[leftIndex];
            leftIndex++;
        }else{
            arr[mainIndex]=arrRight[rightIndex];
            rightIndex++;
        }
        mainIndex++;
    }

    while(leftIndex<n1){
        arr[mainIndex]=arrLeft[leftIndex];
        leftIndex++;
        mainIndex++;
    }

    while(rightIndex<n2){
        arr[mainIndex]=arrRight[rightIndex];
        rightIndex++;
        mainIndex++;
    }
}

void mergeSort(int *arr,int low,int high){
    if(low<high){
        int mid=low+(high-low)/2;

        mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,high);
        merge(arr,low,mid,high);
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

    mergeSort(arr, 0, size - 1);

    printf("Sorted array: ");
    printArray(arr, size);
    return 0;
}