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
    Node* LinkedList=NULL;
    LinkedList=insertNode(LinkedList,1);
    LinkedList=insertNode(LinkedList,2);
    LinkedList=insertNode(LinkedList,3);
    LinkedList=insertNode(LinkedList,4);
    displayList(LinkedList);
    LinkedList=reverseList(LinkedList);
    displayList(LinkedList);
    return 0;
}