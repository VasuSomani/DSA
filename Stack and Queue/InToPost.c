#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Stack{
    int size;
    int top;
    char s[100];
}st;

int isEmpty(){
    if(st.top==-1){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(){
    if(st.top==st.size-1){
        return 1;
    }
    else{
        return 0;
    }
}

void push(char ch){
    if(isFull()){
        printf("Stack Overflow");
        return;
    }
    st.top++;
    st.s[st.top]=ch;
}

char pop(){
    if(isEmpty()){
        printf("Stack Underflow");
        return -1;
    }
    char temp = st.s[st.top];
    st.top--;
    return temp;
}


int prec(char ch){
    if(ch=='-'||ch=='+'){
        return 1;
    }
    else if(ch=='/'||ch=='*'){
        return 2;
    }
    else if(ch=='^'){
        return 3;
    }
    return 0;
}


int isOperator(char ch){
    if(ch=='-'||ch=='+'||ch=='/'||ch=='*'||ch=='^'){
        return 1;
    }
    else{
        return 0;
    }
}


char* convert(char in[100]){
    char *post = (char*)malloc(sizeof(char)*100);
    int j=0;
    for(int i=0;in[i]!='\0';i++){
        if(in[i]=='('){
            push('(');
        }
        else if(in[i]==')'){
            while(st.s[st.top]!='('){
                post[j++]=pop();
            }
            pop();
        }
        else if(isOperator(in[i])){
            while(!isEmpty() && isOperator(st.s[st.top]) && prec(st.s[st.top])>=prec(in[i])){
                post[j++]=pop();
            }
            push(in[i]);
        
        }
        else{
            post[j++]=in[i];
        }
        
    }
    while (!isEmpty())
    {
        post[j++]=pop();
    }
    
    post[j++]='\0';
    return post;
}

int main(){
    st.size=10;
    st.top=-1;
    printf("%s\n",convert("K+L-M*N+(O^P)*W/U/V*T+Q"));
}