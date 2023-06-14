#include<stdio.h>
#include<stdlib.h>

typedef struct queue{
    int size;
    int front;
    int rear;
    char *arr;
}Queue;

int isEmpty(Queue* q){
    if(q->front==q->rear){
        return 1;
    }
    return 0;
}

int isFull(Queue* q){
    if(q->rear==(q->size-1)%q->size){
        return 1;
    }
    return 0;
}

void enQueue(Queue* q,char data){
    if(isFull(q)){
        printf("Oueue Overflow");
    }
    else{
        q->rear = (q->rear+1)%q->size;
        q->arr[q->rear]=data;
    }
}

char deQueue(Queue* q){
    if(isEmpty(q)){
        printf("Queue Underflow");
        return ' ';
    }
    else{
        q->front = (q->front+1)%q->size;
        char x = q->arr[q->front];
        return x;
    }
}

void display(Queue* q){
    for(int i=(q->front+1)%q->size; i<=q->rear ;i=(i+1)%q->size){
        printf("%c ",q->arr[i]);
    }
}

int main(){
    Queue q;
    q.arr = (char*)malloc(sizeof(char)*q.size);
    q.size=20;
    q.front=q.rear=-1;

    enQueue(&q,'A');
    enQueue(&q,'B');
    enQueue(&q,'C');
    enQueue(&q,'D');
    deQueue(&q);
    display(&q);
}