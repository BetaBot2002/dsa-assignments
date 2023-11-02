// Assignment 6

#include <stdio.h>
#include <stdlib.h>

void sortArray(int* arr,int size){
    //Sorting Logic
}

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
            // for (int j = 0; j < *size; j++){
                // printf("Try:%d\n", arr[j]);
            // }
            // printf("end %d\n",*size);
            // printf("i: %d\n",i);
            i=-1;
            // printf("i: %d\n",i);
        }
    }
    return arr;

}

int main(){
    int arr[5];
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Enter the array elements:\n");
    for (int i = 0; i < size; i++){
        scanf("%d", &arr[i]);
    }

    int* newArr=removeDuplicate(arr,&size);

    printf("The array elements after duplicate removal:\n");
    for (int i = 0; i < size; i++){
        printf("%d\n", newArr[i]);
    }
    return 0;
}