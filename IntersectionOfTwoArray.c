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
    int size1;
    printf("Enter the size of array:\n");
    scanf("%d",&size1);

    int *arr1=(int*)malloc(size1*sizeof(int));

    printf("Enter the array elements:\n");
    for (int i = 0; i < size1; i++){
       scanf("%d",&arr1[i]);
    }
    printf("The array elements are:\n");
    for (int i = 0; i < size1; i++){
       printf("%d\n",arr1[i]);
    }
    int size2;
    printf("Enter the size of array:\n");
    scanf("%d",&size2);

    int *arr2=(int*)malloc(size2*sizeof(int));

    printf("Enter the array elements:\n");
    for (int i = 0; i < size2; i++){
       scanf("%d",&arr2[i]);
    }
    printf("The array elements are:\n");
    for (int i = 0; i < size2; i++){
       printf("%d\n",arr2[i]);
    }    
    findIntersection(arr1,size1,arr2,size2);

    return 0;
}