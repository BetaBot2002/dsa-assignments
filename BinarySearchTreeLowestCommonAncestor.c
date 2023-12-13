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

TreeNode* findLowestCommonAncestor(TreeNode* root,int data1,int data2){
    if(root==NULL) return NULL;
    if(root->data>data1 && root->data>data2) findLowestCommonAncestor(root->left,data1,data2);
    else if(root->data<data1 && root->data<data2) findLowestCommonAncestor(root->right,data1,data2);
    else return root;
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

    TreeNode* LCA=findLowestCommonAncestor(root,1,4);
    printf("The LCA of the Binary Search Tree is: %d\n",LCA->data);
    return 0;
}