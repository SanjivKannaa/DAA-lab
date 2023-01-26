// construct a binary tree using pre and in order traversals

/*
ALGORITHM
    1. start with the first element of preorder traversal. create a new tree node with the data as the first element of preorder
    2. find the element in the inorder trversal that matches the data of the root node created in step 1
    3. the elements before the matching element in inorder traversal are recursively added to the left subtree of the root node and elements after the matching element are recursively added
    4. repeat the steps 2 and 3 till all the elemnts are added
*/


#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

int search(int in[], int start, int end, int value) {
    int i;
    for (i = start; i <= end; i++) {
        if (in[i] == value) {
            return i;
        }
    }
    return -1;
}

struct node *newnode(int data){
    struct Node *node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct Node* buildTree(int in[], int pre[], int start, int end){
    int preIndex = 0;
    if(start>end){
        return NULL;
    }
    struct Node *root = newnode(pre[preIndex++]);
    if(start==end){
        return root;
    }
    int inIndex = search(in, start, end, root->data);
    root->left = buildTree(in, pre, start, inIndex-1);
    root->right = buildTree(in, pre, inIndex+1, end);
    return root;
}

void main(){
    int length;
    printf("enter the no of nodes: ");
    scanf("%d", &length);
    int in[20], pre[20];
    printf("enter the inorder traversal: ");
    for(int i=0;i<length;i++){
        scanf("%d", &in[i]);
    }
    printf("enter the preorder traversal: ");
    for(int i=0;i<length;i++){
        scanf("%d", &length);
    }
    struct Node *root = buildTree(in, pre, 0, length);
    postorder(root);
}