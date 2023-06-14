#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* createNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}

struct Node* insertNode(int data,struct Node* head){
    struct Node* newNode = createNode(data);
    if(head==0){
        head=newNode;
        newNode->next=newNode;
    }
    else{
        struct Node* temp = head;
        while(temp->next!=head){
            temp=temp->next;
        }
        temp->next = newNode;
        newNode->next=head;
    }
    return head;
}

struct Node* insertAt(int data,struct Node* head, int pos){
    struct Node* newNode = createNode(data);
    if(pos==1){
        struct Node* temp = head;
        while(temp->next!=head){
            temp=temp->next;
        }
        temp->next = newNode;
        newNode->next=head;
        head=newNode;
    }
    else{ //Will work for insert at end also
        struct Node* temp = head;
        for(int i=1;i<pos-1;i++){
            temp=temp->next;
        }
        newNode->next=temp->next;
        temp->next=newNode;
    }
    return head;
}

struct Node* deleteAt(struct Node* head,int pos){
    if(pos==1){
        struct Node* temp = head;
        while(temp->next!=head){
            temp=temp->next;
        }
        temp->next = head->next;
        free(head);
        head=temp->next;
    }
    else{ //Will work for delete at end also
        struct Node* temp = head;
        for(int i=1;i<pos-1;i++){
            temp=temp->next;
        }
        struct Node* p = temp->next;
        temp->next=p->next;
        free(p);
    }
    return head;
}

void display(struct Node* head){
    struct Node* temp = head;
    do{
        printf("%d ",temp->data);
        temp=temp->next;
    }
    while(temp!=head);
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
    head = insertAt(1000,head,1);
    display(head);
    printf("\n");
    head = deleteAt(head,n+1);
    display(head);
}