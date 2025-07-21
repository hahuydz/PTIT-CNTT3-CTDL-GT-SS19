#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
}Node;
Node* createNode() {
    int data;
    printf("Enter data : ");
    scanf("%d", &data);
    Node*newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
int main() {
    Node*root=createNode();
    root->left=NULL;
    root->right=NULL;
    inorder(root);
    printf("\n");
    return 0;
}
