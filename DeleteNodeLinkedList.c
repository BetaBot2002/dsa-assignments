// Assignment 15
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

Node* deleteNode(Node* head,int data){
    Node* temp=head;
    while(temp->next->data!=data){
        temp=temp->next;
        if(temp->next == NULL) return NULL;
    }
    Node* deleted=temp->next;
    temp->next=deleted->next;
    return deleted;
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

    Node* deleted=deleteNode(LinkedList,2);

    if(deleted!=NULL){
        printf("Deleted: %d\n",deleted->data);
        printf("The Linked List after deltetion:\n");
        displayList(LinkedList);
    }else{
        printf("Node Not Found\n");
    }

    return 0;
}