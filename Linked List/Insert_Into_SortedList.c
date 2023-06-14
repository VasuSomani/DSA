#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node* createNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=0;
    return newNode;
}

struct Node* insertNode(int data,struct Node* head){    //Either return struct Node* or use double pointers concept in head because head is passed by value so it won't get updated when insertNode fucntion ends
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
    }
    return head;
}

void display(struct Node *temp){
    if(temp!=0){
        printf("%d ",temp->data);
        display(temp->next);
    }
}

struct Node* insertSorted(int data, struct Node* head){
    struct Node* newNode = createNode(data);
    struct Node *p=0,*q=head;
    while(q && q->data<data){ // Not (q->data<data && q) because if q is null then still it will check 1st condition, q->data<data which will give error since q is null
        p=q;
        q=q->next;
    }
    p->next=newNode;
    newNode->next=q;
    return head;
}

int main(){
    struct Node *head1=0,*head2=0;
    int arr1[] = {2,4,8,10,23,45,53,59,69,71,72,78};
    int n1 = sizeof(arr1)/sizeof(int);
    for(int i=0;i<n1;i++){
        head1 = insertNode(arr1[i],head1);
    }
    head1 = insertSorted(100,head1);
    display(head1);
}