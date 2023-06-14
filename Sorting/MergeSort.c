#include<stdio.h>

void merging(int A[],int l,int h){
    int B[100];
    int mid = (l+h)/2;
    int i=l;
    int j=mid+1;
    int k=l;
    while(i<=mid && j<=h){ //
        if(A[i]<A[j]){
            B[k++]=A[i++];
        }
        else{
            B[k++]=A[j++];
        }
    }
    while(i<=mid){  //Emptying to A[i]
        B[k++]=A[i++];
    }
    while(j<=h){    //Emptying to A[j]
        B[k++]=A[j++];
    }
    for(int i=l;i<=h;i++){  //Copying elements to A
        A[i]=B[i];
    }
}

void mergeSort(int A[],int l,int h){
    if(l<h){
        int mid = (l+h)/2;
        mergeSort(A,l,mid);
        mergeSort(A,mid+1,h);
        merging(A,l,h);
    }
}

int main(){
    int arr[]={10,9,8,7,6,5,4,3,2,1,0,-1,-2,-3,-4};
    int n = sizeof(arr)/sizeof(int);
    mergeSort(arr,0,n-1);

    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}

// #include<stdio.h>
// #include<stdlib.h>
// #include<string.h>

// void merging(char **arr,int l,int mid, int h){
//     int i=l;
//     int j=mid+1;
//     char* B[100];
//     int k=l;
//     while(i<=mid && j<=h){
//         if(strcmp(arr[i],arr[j])>0){
//             B[k++]=arr[j++];
//         }
//         else {
//             B[k++]=arr[i++];
//         }
//     }
//     while(i<=mid){
//         B[k++]=arr[i++];
//     }
//     while(j<=h){
//         B[k++]=arr[j++];
//     }
//     for(i=l;i<=h;i++){
//         arr[i]=B[i];
//     }
// }

// void mergeSort(char **arr,int l,int h){
//     if(l<h){
//         int mid=(l+h)/2;
//         mergeSort(arr,l,mid);
//         mergeSort(arr,mid+1,h);
//         merging(arr,l,mid,h);
//     }
// }

// int main(){
//     char *arr[] = {"abcder","abc","Abc","ABC","RXY","zya"};
//     int n= sizeof(arr)/sizeof(char *);
//     mergeSort(arr,0,n-1);
//     for(int i=0;i<n;i++){
//         printf("%s ",arr[i]);
//     }

// }