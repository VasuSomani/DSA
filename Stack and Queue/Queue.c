#include<stdio.h>
#include<stdlib.h>

typedef struct stack{
    int top;
    int size;
    char *arr;
}Stack;

int isEmpty(Stack* st){
    if(st->top==-1){
        return 1;
    }
    return 0;
}

int isFull(Stack* st){
    if(st->top==st->size-1){
        return 1;
    }
    return 0;
}

void push(Stack* st,char data){
    if(isFull(st)){
        printf("Stack Overflow");
    }
    else{
        st->arr[++(st->top)]=data;
    }
}

char pop(Stack* st){
    if(isEmpty(st)){
        printf("Stack Underflow");
    }
    else{
        char x = st->arr[st->top--];
        return x;
    }
    return ' ';
}

void display(Stack* st){
    int temp = st->top;
    while(temp>=0){
        printf("%c ",st->arr[temp--]);
    }
}

int main(){
    Stack st;
    st.top=-1;
    st.size=20;
    st.arr = (char *)malloc(sizeof(char)*st.size);

    push(&st,'A');
    push(&st,'B');
    push(&st,'C');
    pop(&st);
    display(&st);

}