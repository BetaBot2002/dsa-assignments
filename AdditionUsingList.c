// Assignment 17
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

Node* ListAddition(Node* head1,Node* head2,Node* result){
    int carry=0;
    int sum=0;
    Node* current1=head1;
    Node* current2=head2;

    while (current1 !=NULL && current2 !=NULL){
        sum=carry+current1->data+current2->data;
        carry=sum>=10?1:0;
        sum=sum>=10?10-sum:sum;
        result=insertNode(result,createNode(sum));
        current1=current1->next;
        current2=current2->next;
    }

    while (current1 !=NULL){
        sum=carry+current1->data;
        carry=sum>=10?1:0;
        sum=sum>=10?10-sum:sum;
        result=insertNode(result,createNode(sum));
        current1=current1->next;
    }

    while (current2 !=NULL){
        sum=carry+current2->data;
        carry=sum>=10?1:0;
        sum=sum>=10?10-sum:sum;
        result=insertNode(result,createNode(sum));
        current2=current2->next;
    }
    return result;
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
    Node* LinkedList1=NULL;
    Node* LinkedList2=NULL;

    Node* node1=createNode(3);
    Node* node2=createNode(4);
    Node* node3=createNode(2);
    Node* node4=createNode(4);
    Node* node5=createNode(6);
    // Node* node6=createNode(5);

    LinkedList1=insertNode(LinkedList1,node1);
    LinkedList1=insertNode(LinkedList1,node2);
    LinkedList1=insertNode(LinkedList1,node3);

    displayList(LinkedList1);

    LinkedList2=insertNode(LinkedList2,node4);
    LinkedList2=insertNode(LinkedList2,node5);
    // LinkedList2=insertNode(LinkedList2,node6);

    displayList(LinkedList2);

    Node* result=NULL;
    result=ListAddition(LinkedList1,LinkedList2,result);
    displayList(result);

    return 0;
}