#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* createNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=0;
    return newNode;
}

struct Node* insertNode(int data, struct Node* head){
    struct Node* newNode = createNode(data);
    if(head==0){
        head=newNode;
    }
    else{
        struct Node* temp = head;
        while(temp->next!=0){
            temp=temp->next;
        }
        temp->next=newNode;
    }
    return head;
}

struct Node* reverseList(struct Node* head){
    struct Node *p=NULL,*q=NULL,*r=head;
    while(r!=NULL){
        //Sliding
        p=q;
        q=r;
        r=r->next;
        //reversing q
        q->next=p;
    }
    head=q;
    return head;
}

void display(struct Node* head){
    if(head!=0){
        printf("%d ",head->data);
        display(head->next);
    }
}

int main(){
    struct Node* head = 0;
    int arr[]={1,2,3,4,5,6,7,8,9,10,11,22};
    int n = sizeof(arr)/sizeof(int);
    for(int i=0;i<n;i++){
        head = insertNode(arr[i],head);
    }
    head=reverseList(head);
    display(head);
}