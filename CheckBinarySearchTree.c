#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode{
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

TreeNode* createNode(int data){
    TreeNode* newNode=(TreeNode*)malloc(sizeof(TreeNode));
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}

TreeNode* insertNode(TreeNode* root,int data){
    TreeNode* newNode=createNode(data);
    if(root==NULL) return newNode;
    if(data<root->data) root->left=insertNode(root->left,data);
    else if(data>root->data) root->right=insertNode(root->right,data);
    return root;
}

int checkInLeftSubTree(TreeNode* root,int key){
    if(root==NULL) return 1;
    if(root->data>key) return 0;
    TreeNode* current=root->left;
    while (current!=NULL){
        if(current->data>key) return 0;
        current=current->left;
    }

    current=root->right;
    while (current!=NULL){
        if(current->data>key) return 0;
        current=current->right;
    }

    return 1;
    
}

int checkInRightSubTree(TreeNode* root,int key){
    if(root==NULL) return 1;
    if(root->data<key) return 0;
    TreeNode* current=root->left;
    while (current!=NULL){
        if(current->data<key) return 0;
        current=current->left;
    }

    current=root->right;
    while (current!=NULL){
        if(current->data<key) return 0;
        current=current->right;
    }

    return 1;
}

int checkBinarySearchTree(TreeNode* root){
    if(root==NULL) return 1;
    // if(root->left==NULL && root->right!=NULL){
    //     if(root->data>root->right->data) return 0;
    //     return checkBinarySearchTree(root->right);
    // }
    // if(root->right==NULL && root->left!=NULL){
    //     if(root->data<root->left->data) return 0;
    //     return checkBinarySearchTree(root->left);
    // }
    int checkInSubTrees=checkInLeftSubTree(root->left,root->data) && checkInRightSubTree(root->right,root->data);
    if(!checkInSubTrees) return 0;
    return checkBinarySearchTree(root->left) && checkBinarySearchTree(root->right);
}

void inorderTraversal(TreeNode* root){
    if(root!=NULL){
        inorderTraversal(root->left);
        printf("%d\n",root->data);
        inorderTraversal(root->right);
    }
}

int main(){
    TreeNode* root1=NULL;

    root1=insertNode(root1,2);
    root1=insertNode(root1,1);
    root1=insertNode(root1,4);
    root1=insertNode(root1,33);
    root1=insertNode(root1,88);
    root1=insertNode(root1,31);
    root1=insertNode(root1,32);

    TreeNode* root2 = createNode(8);
    root2->left = createNode(3);
    root2->right = createNode(10);
    root2->left->left = createNode(1);
    root2->left->right = createNode(6);
    root2->right->right = createNode(14);
    root2->left->right->left = createNode(4);
    root2->left->right->right = createNode(7);
    root2->right->right->left = createNode(13);
    root2->left->right->right->right = createNode(9);

    printf("The In Order Traversal of the 1st Tree is:\n");
    inorderTraversal(root1);

    printf("The Tree is %sa Binary Search Tree\n",checkBinarySearchTree(root1)?"":"Not ");

    printf("The In Order Traversal of the 2nd Tree is:\n");
    inorderTraversal(root2);

    printf("The Tree is %sa Binary Search Tree\n",checkBinarySearchTree(root2)?"":"Not ");
    return 0;
}