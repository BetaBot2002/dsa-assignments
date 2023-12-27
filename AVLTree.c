#include<stdio.h>
#include<stdlib.h>

typedef struct AVLNode{
    int data;
    struct AVLNode* left;
    struct AVLNode* right;
    int height;
} AVLNode;

AVLNode* createNode(int data){
    AVLNode* newNode=(AVLNode*)malloc(sizeof(AVLNode));
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;
    newNode->height=1;
    return newNode;
}

int getHeight(AVLNode* root){
    if(root==NULL) return 0;
    return root->height;
}

int getBalance(AVLNode* root){
    if(root==NULL) return 0;
    return getHeight(root->left)-getHeight(root->right);
}

int maxOf(int a,int b){
    return a>b?a:b;
}

AVLNode* leftRotate(AVLNode* root){
    AVLNode* current=root->right;
    AVLNode* temp=current->left;

    current->left=root;
    root->right=temp;

    root->height=1+maxOf(getHeight(root->left),getHeight(root->right));
    current->height=1+maxOf(getHeight(current->left),getHeight(current->right));

    return current;
}

AVLNode* rightRotate(AVLNode* root){
    AVLNode* current=root->left;
    AVLNode* temp=current->right;

    current->right=root;
    root->left=temp;

    root->height=1+maxOf(getHeight(root->left),getHeight(root->right));
    current->height=1+maxOf(getHeight(current->left),getHeight(current->right));

    return current;
}

AVLNode* insertNode(AVLNode* root,int data){
    if (root==NULL) return createNode(data);
    if(data<root->data) root->left=insertNode(root->left,data);
    else if(data>root->data) root->right=insertNode(root->right,data);

    root->height=1+maxOf(getHeight(root->left),getHeight(root->right));

    int balance=getBalance(root);

    if(balance>1 && data<root->left->data) return rightRotate(root);
    if(balance<-1 && data>root->right->data) return leftRotate(root);
    if(balance>1 && data>root->left->data){
        root->left=leftRotate(root->left);
        return rightRotate(root);
    }
    if(balance<-1 && data<root->right->data){
        root->right=rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
    
}

void inorderTraversal(AVLNode* root){
    if(root!=NULL){
        inorderTraversal(root->left);
        printf("%d\n",root->data);
        inorderTraversal(root->right);
    }
}

void printTree(AVLNode* root) {
    if (root == NULL) return;

    printf("Node: %d, ", root->data);
    printf("Left Child: ");
    if (root->left != NULL) {
        printf("%d", root->left->data);
    } else {
        printf("NULL");
    }

    printf(", Right Child: ");
    if (root->right != NULL) {
        printf("%d", root->right->data);
    } else {
        printf("NULL");
    }
    
    printf(", Balance Factor: %d\n", getBalance(root));
    printTree(root->left);
    printTree(root->right);
}

int main(){
    AVLNode* root=NULL;

    root=insertNode(root,2);
    root=insertNode(root,1);
    root=insertNode(root,4);
    root=insertNode(root,33);
    root=insertNode(root,88);
    root=insertNode(root,31);
    root=insertNode(root,32);

    printf("The In Order Traversal of the Tree is:\n");
    inorderTraversal(root);

    printf("The Visualization of the Tree:\n");
    printTree(root);


    return 0;
}