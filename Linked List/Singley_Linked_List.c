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

struct Node* insertAt(int data, struct Node* head, int pos){
    struct Node* newNode = createNode(data);
    if(pos==1){
        newNode->next=head->next;
        head=newNode;
    }
    else{
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
        struct Node* p = head;
        head=head->next;
        free(p);
    }
    else{
        struct Node* temp = head;
        for(int i=1;i<pos-2;i++){
            temp=temp->next;
        }
        struct Node* p = temp->next;
        temp->next=temp->next->next;
        free(p);
    }
    return head;
}

void display(struct Node *temp){
    if(temp!=0){
        printf("%d ",temp->data);
        display(temp->next);
    }
}

int main(){
    struct Node *head1=0,*head2=0;
    int arr1[] = {2,7,3,4,10,6,8,13,70,23,49};
    int arr2[] = {6,9,10,67,83,56,91,3,0,5};
    int n1 = sizeof(arr1)/sizeof(int);
    for(int i=0;i<n1;i++){
        head1 = insertNode(arr1[i],head1);
    }
    head1=insertAt(100,head1,1);
    head1=insertAt(1000,head1,5);
    head1=deleteAt(head1,6);
    display(head1);


    printf("\n");


    int n2 = sizeof(arr2)/sizeof(int);
    for(int i=0;i<n2;i++){
        head2 = insertNode(arr2[i],head2);
    }
    head2=insertAt(100,head2,1);
    head2=insertAt(1000,head2,5);
    head2=deleteAt(head2,6);
    display(head2);
}