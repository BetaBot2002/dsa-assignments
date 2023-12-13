#include<stdio.h>
#include<stdlib.h>
#include<math.h>

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
    if(root==NULL) return;
    int maxNumberOfNodes=pow(2,findHeight(root)+1)-1;
    TreeNode** stack=(TreeNode**)malloc(maxNumberOfNodes*sizeof(TreeNode));
    int top=-1;

    TreeNode* current=root;

    while(current!=NULL || top!=-1){
        while(current!=NULL){
            stack[++top]=current;
            current=current->left;
        }

        current=stack[top--];
        printf("%d\n",current->data);
        current=current->right;
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

    return 0;
}