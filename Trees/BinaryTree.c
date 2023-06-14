#include<stdio.h>
#include<stdlib.h>

struct Tree{
    struct Tree *left;
    int data;
    struct Tree *right;
};

struct queue{
    int size;
    int front;
    int rear;
    struct Tree **q;
}Queue;

int isEmpty(){
    if(Queue.front==Queue.rear){
        return 1;
    }
    return 0;
}

int isFull(){
    if(Queue.rear==Queue.size-1){
        return 1;
    }
    return 0;
}

void enQueue(struct Tree *data){
    if(isFull()){
        printf("Queue Overflow");
    }
    else{
        Queue.rear++;
        Queue.q[Queue.rear] = data;
    }
}

struct Tree* deQueue(){
    if(isEmpty()){
        printf("Queue Underflow");
        return NULL;
    }
    else{
        struct Tree* temp = Queue.q[++Queue.front];
        return temp;
    }
}

void preOrder(struct Tree *p){
    if(p){
        printf("%d ",p->data);
        preOrder(p->left);
        preOrder(p->right);
    }
}

struct Tree* createNode(int data){
    struct Tree* newNode = (struct Tree*)malloc(sizeof(struct Tree));
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}

void constructBT(){
    int data;
    struct Tree *root;
    printf("Enter root node: ");
    scanf("%d ",&data);
    root = createNode(data);
    enQueue(root);

    while(!isEmpty()){
        struct Tree *p = deQueue();
        //Left Child
        printf("Left Child : ");
        scanf("%d",&data);
        if(data!=-1){
            p->left=createNode(data);
            enQueue(p->left);
        }
        //Right Child
        printf("Right Child : ");
        scanf("%d",&data);
        if(data!=-1){
            p->right=createNode(data);
            enQueue(p->right);
        }
    }
    preOrder(root);
}

int main(){
    Queue.size=20;
    Queue.front=Queue.rear=-1;
    Queue.q = (struct Tree**)malloc(sizeof(struct Tree*)*Queue.size);
    constructBT();
}