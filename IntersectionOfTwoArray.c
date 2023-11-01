// Assignment 3
#include <stdio.h>
#include <stdlib.h>

void findIntersection(int* arr1,int size1, int* arr2,int size2){
    printf("Intersection of Array1 and Array2\n");
    for (int i = 0; i < size1; i++)
    {
        for (int j = 0; j < size2; j++)
        {
            if(arr1[i]==arr2[j]){
                printf("%d\n",arr1[i]);
                break;
            }
        }
        
    }

}

int main(){
    int arr[5];
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Enter the array elements:\n");
    for (int i = 0; i < size; i++){
        scanf("%d", &arr[i]);
    }

    int arr2[5];
    int size2 = sizeof(arr) / sizeof(arr[0]);

    printf("Enter the array2 elements:\n");
    for (int i = 0; i < size2; i++){
        scanf("%d", &arr2[i]);
    }

    findIntersection(arr,size,arr2,size2);

    return 0;
}