#include<stdio.h>
#include <stdlib.h>
#include<stdbool.h>
typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
}Node;
Node*createNode() {
    int data;
    printf("Enter data : ");
    scanf("%d",&data);
    Node*newNode=(Node*)malloc(sizeof(Node));
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}
void preorder(Node* root) {
    if(root!=NULL) {
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

int main() {
    Node*root=createNode();
    root->left=createNode();
    root->right=createNode();
    preorder(root);
    printf("\n");
    return 0;
}
