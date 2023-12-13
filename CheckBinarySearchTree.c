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

int checkBinarySearchTree(TreeNode* root){
    if(root==NULL) return 1;
    if(root->left==NULL && root->right!=NULL){
        if(root->data>root->right->data) return 0;
        return checkBinarySearchTree(root->right);
    }
    if(root->right==NULL && root->left!=NULL){
        if(root->data<root->left->data) return 0;
        return checkBinarySearchTree(root->left);
    }
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
    TreeNode* root=NULL;

    root=insertNode(root,2);
    root=insertNode(root,1);
    root=insertNode(root,4);
    root=insertNode(root,33);
    root=insertNode(root,88);
    root=insertNode(root,31);
    root=insertNode(root,32);

    printf("The In Order Traversal of the Tree is:\n");
    inorderTraversal(root);

    printf("The Tree is %sa Binary Search Tree\n",checkBinarySearchTree(root)?"":"Not ");
    return 0;
}