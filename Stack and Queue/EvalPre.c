#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

struct Stack{
    int size;
    int top;
    int *s;
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

void push(int ch){
    if(isFull()){
        printf("Stack Overflow");
        return;
    }
    st.top++;
    st.s[st.top]=ch;
}

int pop(){
    if(isEmpty()){
        printf("Stack Underflow");
        return -1;
    }
    int temp = st.s[st.top];
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


int evaluate(char pre[100]){
    int i=0,x1,x2,r=0;
    while(pre[i]!='\0'){
        if(!isOperator(pre[i])){
            push(pre[i]-'0');
        }
        else{
            x1=pop();
            x2=pop();
            switch(pre[i]){
                case '+': r = x1+x2;
                break;
                case '-': r = x1-x2;
                break;
                case '*': r = x1*x2;
                break;
                case '/': r = x1/x2;
                break;
                case '^': r = (int)pow(x1,x2);
                break;
            }
            push(r);
        }
        i++;
    }
    return pop();
}

char* reverse(char* s) {
    int length = strlen(s) + 1;
    char* reversedString = (char*)malloc(length * sizeof(char));
    int i;
    for (i = 0; i < length - 1; i++) {
        reversedString[i] = s[length - i - 2];
    }
    reversedString[i] = '\0';
    return reversedString;
}



int main() {
    st.size = 20;
    st.top = -1;
    st.s = (int*)malloc(st.size * sizeof(int));   
    char* input = reverse("-+8/632"); 
    printf("%d",evaluate(input));
    free(st.s);
    return 0;
}