#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    struct Node* left;
    char data;
    struct Node* right;
}Tree;

struct Stack{
    int size;
    int top;
    Tree **s;
}st;


int isEmpty(){
    if(st.top==-1){
        return 1;
    }
    return 0;
}

int isFull(){
    if(st.top==st.size-1){
        return 1;
    }
    return 0;
}

void push(Tree *ch){
    st.s[++st.top] = ch;
}

Tree* pop(){
    return st.s[st.top--];
}

int isOperator(char ch){
    if(ch=='+' || ch=='-' || ch=='*' || ch=='/'){
        return 1;
    }
    return 0;
}

void preOrder(Tree *p){
    if(p){
        printf("%c ",p->data);
        preOrder(p->left);
        preOrder(p->right);
    }
}

void ExpTree(char *post){
    int i=0;
    while(post[i]!='\0'){
        Tree *t = (Tree*)malloc(sizeof(Tree)*st.size);
        t->data=post[i];
        if(!isOperator(post[i])){
            push(t);
        }
        else{
            Tree* r = pop();
            Tree* l = pop();
            t->left=l;
            t->right=r;
            push(t);
        }
        i++;
    }
    preOrder(pop());
}

int main(){
    st.top=-1;
    st.s = (Tree**)malloc(sizeof(Tree*));
    st.size=100;
    char *post = "AB+CD-*";
    ExpTree(post);
}