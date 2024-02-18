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
    Node* resultPtr=result;

    while (current1 !=NULL || current2 !=NULL){
        sum=0+carry;
        if (current1 !=NULL){
            sum+=current1->data;
            current1=current1->next;
        }

        if (current2 !=NULL){
            sum+=current2->data;
            current2=current2->next;
        }

        carry=sum/10;
        sum=sum%10;
        resultPtr->next=createNode(sum);
        resultPtr=resultPtr->next;
    }

    if(carry>0){
		resultPtr->next=createNode(carry);
		resultPtr=resultPtr->next;
	}

    return result->next;
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
    Node *LinkedList1 = NULL, *LinkedList2 = NULL, *result;

    LinkedList1 = insertNode(insertNode(insertNode(NULL, createNode(3)), createNode(4)), createNode(2));
    printf("Number 1 (from LSB->...->MSB): "); displayList(LinkedList1);

    LinkedList2 = insertNode(insertNode(insertNode(NULL, createNode(4)), createNode(6)), createNode(5));
    printf("Number 2 (from LSB->...->MSB): "); displayList(LinkedList2);

    result = createNode(0);
    result = ListAddition(LinkedList1, LinkedList2, result);
    printf("Result (from LSB->...->MSB): "); displayList(result);

    return 0;
}
