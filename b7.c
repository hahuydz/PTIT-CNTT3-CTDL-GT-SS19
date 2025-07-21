#include<stdio.h>
#include <stdlib.h>
#include<stdbool.h>
#define MAX_QUEUE 100
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
typedef struct {
    Node*data[MAX_QUEUE];
    int front;
    int rear;
}Queue;
void initQueue(Queue *q) {
    q->front = 0;
    q->rear = 0;
}
bool isQueueEmpty(Queue *q) {
    return q->front == q->rear;
}
bool enqueue(Queue *q,Node*node) {
    if ((q->rear+1) % MAX_QUEUE == q->front) {
        printf("Queue is full\n");
        return;
    }
    q->data[q->rear] = node;
    q->rear =(q->rear+1)%MAX_QUEUE;
}
Node* dequeue(Queue *q) {
    if (isQueueEmpty(q)) {
        return NULL;
    }
    Node*temp = q->data[q->front];
    q->front = (q->front+1)%MAX_QUEUE;
    return temp;
}
bool searchBFS(Node*root,int target) {
    if (root == NULL) {
        return false;
    }
    Queue q;
    initQueue(&q);
    enqueue(&q,root);
    while (!isQueueEmpty(&q)) {
        Node*current=dequeue(&q);
        if (current->data == target) {
            return true;
        }
        if (current->left != NULL) {
            enqueue(&q,current->left);
        }
        if (current->right != NULL) {
            enqueue(&q,current->right);
        }
    }
    return false;
}
int main() {
    Node*root=createNode();
    root->left=createNode();
    root->right=createNode();
    preorder(root);
    printf("\n");
    int key;
    printf("Moi ban nhap gia tri can tim: ");
    scanf("%d",&key);

if (searchBFS(root,key)) {
    printf("Gia tri %d duoc thi thay",key);
}else {
    printf("Khong tim thay gia tri");
}
    return 0;
}
