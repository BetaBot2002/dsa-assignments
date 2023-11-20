// Assignment 16
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

Node* insertNode(Node* head,Node* node){
    if(head==NULL) return node;
    node->next=head;
    return node;
}

Node* checkIntersection(Node* head1,Node* head2){
    Node* current1=head1;
    Node* current2=head2;

    while(current1!=NULL){
        while (current2 !=NULL){
            if(current1 == current2){
                return current1;
            }
            current2=current2->next;
        }
        current1=current1->next;
        current2=head2;
    }
    return NULL;
}

void displayList(Node* head){
    Node* current=head;
    while (current != NULL){
        printf("%d%s", current->data, current->next ? "->" : "");
        current=current->next;
    }
    printf("\n");
}


int main(){
    Node* LinkedList1=NULL;
    Node* LinkedList2=NULL;

    Node* node1=createNode(1);
    Node* node2=createNode(2);
    Node* node3=createNode(3);
    Node* node4=createNode(4);

    LinkedList1=insertNode(LinkedList1,node1);
    LinkedList1=insertNode(LinkedList1,node2);
    LinkedList1=insertNode(LinkedList1,node3);
    printf("List 1: "); displayList(LinkedList1);

    LinkedList2=insertNode(LinkedList2,node4);
    LinkedList2=insertNode(LinkedList2,node3);
    printf("List 2: "); displayList(LinkedList2);


    Node* intersection=checkIntersection(LinkedList1,LinkedList2);
    printf("Intersection Node data: %d\n",intersection->data);

    return 0;
}