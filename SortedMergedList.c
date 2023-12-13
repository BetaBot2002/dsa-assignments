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

Node* MergeNodes(Node* head1, Node* head2){
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;

    Node* result = (head1->data >= head2->data) ? head1 : head2;

    if (head1->data >= head2->data)
        result->next = MergeNodes(head1->next, head2);
    else
        result->next = MergeNodes(head1, head2->next);
    
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
    // Node *LinkedList1 = NULL, *LinkedList2 = NULL, *result=NULL;

    Node* LinkedList1 = insertNode(insertNode(insertNode(NULL, 1), 2), 34);
    printf("List 1 : "); displayList(LinkedList1);

    Node* LinkedList2 = insertNode(insertNode(NULL, 5), 9);
    printf("List 2 : "); displayList(LinkedList2);

    Node* result = MergeNodes(LinkedList1, LinkedList2);
    printf("Result : "); displayList(result);

    return 0; 
}