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

struct Node* reverseList(struct Node* head) {
    struct Node* p = head;
    while (p) {
        struct Node* temp = p->next; //Swapping p->next and p->prev
        p->next = p->prev;
        p->prev = temp;

        p = p->prev; //since p->next is p->prev to move forward we will do p=p->prev
        if (p!=NULL && p->next==NULL) {
        head = p;
        }   
    }
    // head =p;
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
    head = reverseList(head);
    display(head);
}