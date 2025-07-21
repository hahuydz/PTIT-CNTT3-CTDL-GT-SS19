#include<stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
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

void postorder(Node*root) {
    if(root!=NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
        printf("\n");
    }
}
int main() {
    Node*root=createNode();
    root->left=createNode();
    root->right=createNode();
    postorder(root);
    printf("\n");
    return 0;
}
