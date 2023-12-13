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

int findHeight(TreeNode* root){
    if(root==NULL) return -1;
    int leftHeight=findHeight(root->left);
    int rightHeight=findHeight(root->right);
    return (leftHeight>rightHeight?leftHeight:rightHeight)+1;
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

    printf("The Height of the tree is: %d\n",findHeight(root));

    return 0;
}