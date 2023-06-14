#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
}*Head=0;

struct Node* createNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=0;
    return newNode;
}

struct Node* insertNode(int data,struct Node* head){//Either return struct Node* or use double pointers concept in head because head is passed by value so it won't get updated when insertNode fucntion ends
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

void merge(struct Node* head1, struct Node* head2){ //Using 3 pointers p,q,temp
    struct Node *p=head1,*q=head2;
    struct Node *temp;
    if(p->data < q->data){
        Head=temp=p;
        p=p->next;
    }
    else{
        Head=temp=q;
        q=q->next;
    }

    while(p && q){
        if(p->data<q->data){
            temp->next=p;
            temp=p;
            p=p->next;
        }
        else{
            temp->next=q;
            temp=q;
            q=q->next;
        }
    }

    if(p){
        temp->next=p;
    }
    if(q){
        temp->next=q;
    }

}

int main(){
    struct Node *head1=0,*head2=0;
    int arr1[] = {1,3,5,7,9,11,13};
    int arr2[] = {0,2,4,6,8,10,12,14,15,16,17,18};
    int n1 = sizeof(arr1)/sizeof(int);
    for(int i=0;i<n1;i++){
        head1 = insertNode(arr1[i],head1);
    }
    display(head1);


    printf("\n");


    int n2 = sizeof(arr2)/sizeof(int);
    for(int i=0;i<n2;i++){
        head2 = insertNode(arr2[i],head2);
    }
    display(head2);

    printf("\n");

    merge(head1,head2);
    display(Head);
}