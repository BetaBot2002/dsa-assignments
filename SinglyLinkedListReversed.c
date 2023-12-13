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
    Node* newNode=createNode(data);
    if(head==NULL) return newNode;
    newNode->next=head;
    return newNode;
}

Node* reverseList(Node* head){
    Node* prev=NULL;
    Node* current=head;
    Node* next=NULL;
    while (current !=NULL){
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    head=prev;
    return head;
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
    printf("The List is:\n");
    displayList(LinkedList);
    
    LinkedList=reverseList(LinkedList);
    printf("The List after revrsal is:\n");
    displayList(LinkedList);
    return 0;
}