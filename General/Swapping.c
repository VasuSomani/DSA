#include<stdio.h>

int main(){
    int n1,n2;
    scanf("%d %d",&n1,&n2);
    //Normal Method
    // n1=n1+n2;
    // n2=n1-n2;
    // n1=n1-n2;

    //Using bitwise XOR(1-1 and 0-0 ->0 rest 1)
    n1=n1^n2;
    n2=n1^n2;
    n1=n1^n2;
    printf("%d %d",n1,n2);
}