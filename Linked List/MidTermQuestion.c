#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}Node;

Node* createNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data=data;
    newNode->next=0;
    return newNode;
}

Node* insertNode(int data,Node* head){
    Node* newNode = createNode(data);
    if(head==0){
        head=newNode;
    }
    else{
        Node* temp = head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newNode;
    }
    return head;
}

void display(Node* head){
    if(head){
        printf("%d ",head->data);
        display(head->next);
    }
}

Node* desiredOutput(int m,int n,Node* head1,Node* head2,Node* Head){
    Node *p,*q,*temp;
    if(m<=n){
        p=head1;
        q=head2;
    }
    else{
        p=head2;
        q=head1;
    }
    Head=p;
    while(p && q){
        temp=p;
        p=p->next;
        temp->next=q;
        temp=q;
        q=q->next;
        temp->next=p;
    }
    if(q){
        temp->next=q;
    }
    if(p){
        temp->next=p;
    }
    return Head;
}

int main(){
    Node *head1=0;
    Node *head2=0;
    Node *Head=0;
    int arr1[]={1,3,5,7,9};
    int n1 = sizeof(arr1)/sizeof(int);
    for(int i=0;i<n1;i++){
        head1=insertNode(arr1[i],head1);
    }
    display(head1);
    printf("\n");
    int arr2[]={2,4,6};
    int n2 = sizeof(arr2)/sizeof(int);
    for(int i=0;i<n2;i++){
        head2=insertNode(arr2[i],head2);
    }
    display(head2);
    printf("\n");
    display(desiredOutput(n1,n2,head1,head2,Head));

}