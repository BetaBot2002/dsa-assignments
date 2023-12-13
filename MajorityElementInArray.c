// Assignment 7

#include <stdio.h>
#include <stdlib.h>

int countElement(int* arr,int size, int element){
    int count=0;
    for(int i=0;i<size;i++){
        if(arr[i]==element){
            count++;
        }
    }
    return count;
}

int* majorityElement(int* arr,int size){
    int majorityElementPos=0;
    int majorityElementCount=0;

    for(int i=0;i<size;i++){
        int count=countElement(arr,size,arr[i]);
        if(count>=majorityElementCount){
            majorityElementCount=count;
            majorityElementPos=i;
        }
    }

    static int majority[2];
    majority[0]=arr[majorityElementPos];
    majority[1]=majorityElementCount;

    return majority;
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

    int* majority=majorityElement(arr,size);

    printf("Majority Element: %d, Count: %d\n",majority[0],majority[1]);

    return 0;
}