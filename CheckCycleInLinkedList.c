// Assignment 11
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
    if(head==NULL) return createNode(data);

    Node* temp=head;
    head=createNode(data);
    head->next=temp;
    
    return head;
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
    Node* LinkedList=NULL;
    LinkedList=insertNode(LinkedList,1);
    LinkedList=insertNode(LinkedList,2);
    LinkedList=insertNode(LinkedList,3);
    LinkedList=insertNode(LinkedList,4);

    LinkedList->next->next=LinkedList;

    // displayList(LinkedList);

    if(checkCycle(LinkedList)){
        printf("There is a cycle.\n");
    }else{
        printf("No Cycle.\n");
    }

    return 0;
}