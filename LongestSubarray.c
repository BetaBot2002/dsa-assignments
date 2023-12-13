// Assignment 8
#include <stdio.h>
#include <stdlib.h>

int* LongestSubarray(int* arr,int size,int target){
    int currentLength=0;
    int maxLength=0;
    int start=0;
    int end=0;
    int sum=0;

    for(int i=0;i<size;i++){
        for(int j=i;j<size;j++){
            currentLength=j-i;
            sum+=arr[j];
            if(sum<=target && currentLength>=maxLength){
                start=i;
                end=j;
                maxLength=currentLength;
            }else if(sum > target) break;
        }
        sum=0;
        currentLength=0;
    }

    static int longestSubarray[3];
    longestSubarray[0]=start;
    longestSubarray[1]=end;
    longestSubarray[2]=maxLength+1;

    return longestSubarray;
    
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
    printf("Enter the sum:\n");
    scanf("%d",&target);

    int* longestSubarray=LongestSubarray(arr,size,target);
    printf("The length of the longest subarray: %d\n",longestSubarray[2]);
    printf("The longest subarray:\n");
    for (int i = longestSubarray[0]; i <= longestSubarray[1]; i++){
        printf("%d\n",arr[i]);
    }
    
    return 0;
}
