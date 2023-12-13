// Assignment 12
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
} Node;

Node* createNode(int data){
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}

Node* insertNode(Node* head,int data){
    Node* newNode=createNode(data);
    if(head==NULL) return newNode;
    newNode->next=head;
    return newNode;
}

int checkCycle(Node* head){
    Node* slowPointer=head;
    Node* fastPointer=head;

    while(slowPointer!=NULL && fastPointer!=NULL && fastPointer->next!=NULL){
        slowPointer=slowPointer->next;
        fastPointer=fastPointer->next->next;

        if(slowPointer == fastPointer){
            return 1;
        }
    }
    return 0;
}

void displayList(Node* head){
    Node* current=head;
    while (current != NULL){
        current->next==NULL?printf("%d",current->data):printf("%d->",current->data);
        current=current->next;
    }
    printf("\n");
}


int main(){
    int size;
    printf("Enter the number of items:\n");
    scanf("%d",&size);
    
    Node* LinkedList=NULL;
    printf("Enter the list:\n");
    for (int i = 0; i < size; i++){
        int val;
        scanf("%d",&val);
        LinkedList=insertNode(LinkedList,val);
    }

    LinkedList->next->next=LinkedList;

    if(checkCycle(LinkedList)){
        printf("There is a cycle.\n");
    }else{
        printf("No Cycle.\n");
    }

    return 0;
}