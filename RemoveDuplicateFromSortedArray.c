// Assignment 6

#include <stdio.h>
#include <stdlib.h>

int* deleteElement(int* arr,int size,int index){
    int* newArray=(int*)malloc(size*sizeof(int));
    int j=0;
    for(int i=0;i<=size;i++){
        if(i!=index){
            newArray[j]=arr[i];
            j++;
        }
    }
    return newArray;
}

int* removeDuplicate(int* arr,int *size){

    for (int i = 0; i < *size-1; i++)
    {
        if(arr[i]-arr[i+1]==0){
            arr=deleteElement(arr,--*size,i+1);
            i=-1;
        }
    }
    return arr;

}

int main(){
    int size;
    printf("Enter the size of array:\n");
    scanf("%d",&size);

    int *arr=(int*)malloc(size*sizeof(int));

    printf("Enter the array elements in ascending order:\n");
    for (int i = 0; i < size; i++){
       scanf("%d",&arr[i]);
    }

    int* newArr=removeDuplicate(arr,&size);

    printf("The array elements after duplicate removal:\n");
    for (int i = 0; i < size; i++){
        printf("%d\n", newArr[i]);
    }
    return 0;
}