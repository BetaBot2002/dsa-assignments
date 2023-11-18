// Assignment 14
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

Node* findNthNode(Node* head,int pos){
    if(pos<=0) return NULL;

    int length=0;
    Node* current=head;
    while(current!=NULL){
        current=current->next;
        length++;
    }

    if(pos>length) return NULL;

    int posFromFirst=length-pos+1;
    current=head;
    while(posFromFirst>1 && current!=NULL){
        current=current->next;
        posFromFirst--;
    }

    return current;
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
    int pos=4;
    Node* found=findNthNode(LinkedList,pos);
    if(found != NULL){
        printf("Found at position %d from last: %d\n",pos,found->data);
    }else{
        printf("Not Found\n");
    }
    return 0;
}