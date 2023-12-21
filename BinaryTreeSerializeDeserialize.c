#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

#define NULL_VALUE -9999

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

int* serializeBinaryTree(TreeNode* root,int numberOfNodes){
    TreeNode* current=root;

    TreeNode* stack[100];
    int top=-1;

    // printf("%d\n",numberOfNodes);
    stack[++top]=current;

    int* serialized=(int*)malloc(numberOfNodes*sizeof(int));
    for(int i=0;i<numberOfNodes;i++){
        serialized[i]=NULL_VALUE;
    }
    serialized[0]=current->data;
    
    int i=0;
    while(i<numberOfNodes){
        // printf("%d\n",i);
        serialized[2*i+1]=current->left==NULL?NULL_VALUE:current->left->data;
        serialized[2*i+2]=current->right==NULL?NULL_VALUE:current->right->data;

        if(current->left!=NULL){
            stack[++top]=current;
            i=2*i+1;
            current=current->left;
        }else if(current->right!=NULL){
            stack[++top]=current;
            i=2*i+2;
            current=current->right;
        }else{
            i++;
            current=stack[--top]->right;
        }

    }
    return serialized;
}

TreeNode* deserializeBinaryTree(int* serialized,int numberOfNodes){
    TreeNode* result=NULL;
    result=insertNode(result,serialized[0]);

    TreeNode* current=result;

    TreeNode* stack[100];
    int top=-1;

    // printf("%d\n",numberOfNodes);
    stack[++top]=current;
    
    int i=0;
    while(i<numberOfNodes){
        printf("%d\n",current->data);
        // serialized[2*i+1]=current->left==NULL?NULL_VALUE:current->left->data;
        // serialized[2*i+2]=current->right==NULL?NULL_VALUE:current->right->data;
        current->left=(2 * i + 1)>=numberOfNodes?NULL:serialized[2*i+1]!=NULL_VALUE?insertNode(current->left,serialized[2*i+1]):NULL;
        current->right=(2 * i + 2)>=numberOfNodes?NULL:serialized[2*i+2]!=NULL_VALUE?insertNode(current->right,serialized[2*i+2]):NULL;
        // printf("%d\n",i);

        if(current->left!=NULL){
            stack[++top]=current;
            i=2*i+1;
            current=current->left;
        }else if(current->right!=NULL){
            stack[++top]=current;
            i=2*i+2;
            current=current->right;
        }else{
            i++;
            current=stack[top--]->right;
        }

    }
    return result;
}

// TreeNode* deserializeBinaryTree(int* serialized, int numberOfNodes) {
//     TreeNode* result = NULL;
//     result = insertNode(result, serialized[0]);

//     TreeNode* current = result;

//     TreeNode* stack[100];
//     int top = -1;

//     stack[++top] = current;

//     int i = 0;
//     while (i < numberOfNodes) {
//         printf("Current data: %d\n", current->data);

//         current->left = (2 * i + 1)>=numberOfNodes?NULL:serialized[2 * i + 1] != NULL_VALUE ? insertNode(current->left, serialized[2 * i + 1]) : NULL;
//         current->right =(2 * i + 2)>=numberOfNodes?NULL: serialized[2 * i + 2] != NULL_VALUE ? insertNode(current->right, serialized[2 * i + 2]) : NULL;

//         printf("Left data: %d, Right data: %d\n", current->left ? current->left->data : -1, current->right ? current->right->data : -1);

//         if (current->left != NULL) {
//             stack[++top] = current;
//             i = 2 * i + 1;
//             current = current->left;
//         } else if (current->right != NULL) {
//             stack[++top] = current;
//             i = 2 * i + 2;
//             current = current->right;
//         } else {
//             i++;
//             if (top >= 0) {
//                 current = stack[top--]->right;
//             } else {
//                 break;
//             }
//         }
//     }
//     return result;
// }


void inorderTraversal(TreeNode* root){
    if(root!=NULL){
        inorderTraversal(root->left);
        printf("%d\n",root->data);
        inorderTraversal(root->right);
    }
}

void printArray(int arr[], int size) {
  for (int i = 0; i < size; printf("%d ", arr[i++]));
  printf("\n");
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

    int numberOfNodes=pow(2,findHeight(root)+1)-1;


    printf("The In Order Traversal of the Tree is:\n");
    inorderTraversal(root);

    int* serialized=serializeBinaryTree(root,numberOfNodes);
    printArray(serialized,numberOfNodes);

    inorderTraversal(deserializeBinaryTree(serialized,numberOfNodes));

}