#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    struct node *left;
    int data;
    struct node* right;
}Node;

Node* createNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data=data;
    newNode->left=newNode->right=NULL;
    return newNode;
}

Node* insertNode(int data,Node* root){
    if(root==NULL){
        root=createNode(data);
    }
    else{
        if(data<root->data){
            root->left = insertNode(data,root->left);
        }
        else if(data>root->data){
            root->right = insertNode(data,root->right);
        }
    }
    return root;
}

Node* searchNode(int data,Node* root){
    if(root==NULL){
        return NULL;
    }
    else if(data==root->data){
        return root;
    }
    else if(data<root->data){
        return searchNode(data,root->left);
    }
    else if(data>root->data){
        return searchNode(data,root->right);
    }
    return NULL;
}

 //TODO : Complete BST deletion code;
// Node* delete(int key,Node *root){
//     if(key>root->data){
//         root->right = delete(key,root->right);
//     }
//     else if(key<root->data){
//         root->left = delete(key,root->left);
//     }
//     else if(key==root->data){
//         if(root->left==0){
//             Node* temp = root->right;
//             free(root);
//             return temp;
//         }
//         else if(root->right==0){
//             BST* temp = root->left;
//             free(root);
//             return temp;
//         }
//         else{
//             int inPRE = inPre(root->data);
//             delete(inPRE,root);
//             root->data = inPRE;
//         }
//     }
// }

void preOrder(Node* root){
    if(root){
        printf("%d ",root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main(){
    Node* root=NULL;
    int arr[] = {45,56,32,14,27,18,12,50,66,49,61,7,10,76};
    int n = sizeof(arr)/sizeof(int);
    for(int i=0;i<n;i++){
        root = insertNode(arr[i],root);
    }
    preOrder(root);
    if(searchNode(19,root)!=NULL){
        printf("FOUND");
    }
    else{
        printf("NOT FOUND");
    }
}