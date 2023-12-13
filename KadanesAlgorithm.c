// Assignment 9
#include <stdio.h>
#include <stdlib.h>

int maxSubArraySum(int *arr,int size){
    int currentMax=arr[0];
    int max=currentMax;

    for (int i = 1; i < size; i++){
        currentMax=currentMax+arr[i]>arr[i]?currentMax+arr[i]:arr[i];
        max=max>currentMax?max:currentMax;
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

    int largestSubarraySum=maxSubArraySum(arr,size);

    printf("The Largest Subarray Sum is: %d\n",largestSubarraySum);
    return 0;
}