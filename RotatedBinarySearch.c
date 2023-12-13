//Assignment 10
#include <stdio.h>
#include <stdlib.h>

int searchInRotatedArray(int *arr,int size,int target){
    if(size<=0) return -1;

    int low=0;
    int high=size-1;
    
    while(low<=high){
        int mid=(low+high)/2;

        if(arr[mid]==target){
            return mid;
        }

        if(arr[low]<=arr[mid]){
            if(arr[low]<=target && target<arr[mid]){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }else{
            if(arr[mid]<target && target<=arr[high]){
                low=mid+1;
            }else{
                high=mid-1;
            }
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

    int target;
    printf("Enter the value you want to search:\n");
    scanf("%d",&target);

    int found=searchInRotatedArray(arr,size,target);
    if(found==-1){
        printf("Element not found\n");
    }else{
        printf("The target element %d is found at the index %d\n",target,found);
    }
    return 0;
}