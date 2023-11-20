// Assignment 13
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

Node* MergeNodes(Node* head1,Node* head2){
    Node* current1=head1;
    Node* current2=head2;

    if(current1 == NULL) return current2;
    if(current2 == NULL) return current1;

    Node* result=NULL;

    if(current1->data>=current2->data){
        result=current1;
        result->next=MergeNodes(current1->next,current2);
    }else{
        result=current2;
        result->next=MergeNodes(current1,current2->next);
    }
    
    return result;
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
    Node *LinkedList1 = NULL, *LinkedList2 = NULL, *result=NULL;

    LinkedList1 = insertNode(insertNode(insertNode(NULL, 1), 2), 3);
    printf("List 1 : "); displayList(LinkedList1);

    LinkedList2 = insertNode(insertNode(NULL, 5), 9);
    printf("List 2 : "); displayList(LinkedList2);

    result = MergeNodes(LinkedList1, LinkedList2);
    printf("Result : "); displayList(result);

    return 0;
}