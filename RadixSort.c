// Assignment 22

#include <stdio.h>
#include <stdlib.h>

int getMaxElement(int *arr,int size){
    int max=0;
    for(int i=0;i<size;i++){
        if(arr[i]>arr[max]){
            max=i;
        }
    }
    return max;
}

int getNumberOfDigits(int number){
    int num=number;
    int digitCount=0;
    while(num>0){
        num=num/10;
        digitCount++;
    }
    return digitCount;
}

void countingSort(int *arr,int size,int exponent){
    int *output=(int*)malloc(size*sizeof(int));
    int count[10]={0};

    for(int i=0;i<size;i++){
        count[(arr[i]/exponent)%10]++;
    }

    for(int i=1;i<10;i++){
        count[i]+=count[i-1];
    }

    for(int i=size-1;i>=0;i--){
        output[count[(arr[i]/exponent)%10]-1]=arr[i];
        count[(arr[i]/exponent)%10]--;
    }

    for(int i=0;i<size;i++){
        arr[i]=output[i];
    }
}

void radixSort(int *arr,int size){
    int digitOfMaxNumber=getNumberOfDigits(arr[getMaxElement(arr,size)]);
    int exponent=1;

    for(int i=0;i<digitOfMaxNumber;i++){
        countingSort(arr,size,exponent);
        exponent*=10;
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

    radixSort(arr, size);

    printf("Sorted array: ");
    printArray(arr, size);
    return 0;
}