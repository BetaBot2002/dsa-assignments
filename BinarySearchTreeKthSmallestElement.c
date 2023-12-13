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

int countNodes(TreeNode* root){
    if(root==NULL) return 0;
    return 1+countNodes(root->left)+countNodes(root->right);
}

TreeNode* findKthSmallest(TreeNode* root,int index){
    int leftCount=countNodes(root->left);

    if(index<=leftCount) return findKthSmallest(root->left,index);
    else if(index>leftCount+1) return findKthSmallest(root->right,index-1-leftCount);

    //leftCount+1 th element is the root

    return root;
}

/*Alternative Approach: Not Efficient*/

// TreeNode** inOrderListFromTree(TreeNode* root,TreeNode** stack,int *top){
//     if(root!=NULL){
//         stack=inOrderListFromTree(root->left,stack,top);
//         stack[++*top]=root;
//         stack=inOrderListFromTree(root->right,stack,top);
//     }
//     return stack;
// }
// TreeNode* findKthSmallest(TreeNode* root,int index){
//     if(root==NULL) return NULL;
//     int maxNumberOfNodes=pow(2,findHeight(root)+1)-1;
//     TreeNode** stack=(TreeNode**)malloc(maxNumberOfNodes*sizeof(TreeNode));
//     int top=-1;
//     stack=inOrderListFromTree(root,stack,&top);
//     int pos=index==0?0:index-1>top?top:index-1;
//     return stack[pos];
// }


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

    printf("The Kth smallest element: %d\n",findKthSmallest(root,3)->data);
    return 0;
}