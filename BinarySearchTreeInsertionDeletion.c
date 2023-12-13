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

TreeNode* findMinimumNode(TreeNode* root){
    while (root->left!=NULL) root=root->left;
    return root;
}

TreeNode* deleteNode(TreeNode* root,int data){
    if(root==NULL) return root;
    else if(data<root->data) root->left=deleteNode(root->left,data);
    else if(data>root->data) root->right=deleteNode(root->right,data);
    else{
        if(root->left ==NULL){
            TreeNode* temp=root->right;
            free(root);
            return temp;
        }else if(root->right == NULL){
            TreeNode* temp=root->left;
            free(root);
            return temp;
        }
        TreeNode* temp=findMinimumNode(root->right);
        root->data=temp->data;
        root->right=deleteNode(root->right,temp->data);
    }
    return root;
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
    root=insertNode(root,2);

    printf("The In Order Traversal of the Tree is:\n");
    inorderTraversal(root);

    root=deleteNode(root,81);
    root=deleteNode(root,4);
    root=deleteNode(root,2);

    printf("The In Order Traversal of the Tree after Deletion is:\n");
    inorderTraversal(root);
    return 0;
}