#include<stdio.h>
#include<stdlib.h>

struct Node{
    struct Node* prev;
    int data;
    struct Node* next;
};

struct Node* createNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=newNode->prev=NULL;
    return newNode;
}

struct Node* insertNode(int data, struct Node* head){
    struct Node* newNode = createNode(data);
    if(head==0){
        head=newNode;
    }
    else{
        struct Node* temp=head;
        while(temp->next!=0){
            temp=temp->next;
        }
        temp->next=newNode;
        newNode->prev=temp;
    }
    return head;
}

struct Node* insertAt(int data, struct Node* head, int pos){
    struct Node* newNode = createNode(data);
    if(pos==1){
        newNode->next=head;
        head->prev=newNode;
        head=newNode;
    }
    else{
        struct Node* temp = head;
        for(int i=1;i<pos-1;i++){
            temp=temp->next;
        }
        newNode->next=temp->next;
        newNode->prev=temp;
        if(temp->next){
            temp->next->prev=newNode;
        }
        temp->next=newNode;
    }
    return head;
}

struct Node* deleteAt(struct Node* head, int pos){
    if(pos==1){
        if(head->next){
            head->next->prev=0;
        }
        struct Node* p = head;
        head=head->next;
        free(p);
    }
    else{
        struct Node* temp = head;
        for(int i=1;i<pos;i++){
            temp=temp->next;
        }
        if(temp->prev){
            temp->prev->next=temp->next;
        }
        if(temp->next){
            temp->next->prev=temp->prev;
        }
        free(temp);
    }
    return head;
}

void display(struct Node* head){
    if(head){
        printf("%d ",head->data);
        display(head->next);
    }
}

int main(){
    struct Node* head=NULL;
    int arr[] = {1,62,13,24,5,39,6,78,56,121};
    int n = sizeof(arr)/sizeof(int);
    for(int i=0;i<n;i++){
        head=insertNode(arr[i],head);
    }
    display(head);
    printf("\n");
    head=insertAt(1000,head,5);
    display(head);
    printf("\n");
    head = deleteAt(head,n+1);
    display(head);
}