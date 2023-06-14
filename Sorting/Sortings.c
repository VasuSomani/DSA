#include<stdio.h>

//Optimised Bubble Sort
void bubbleSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int flag=0;
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;

                flag=1;
            }
        }
        if(flag==0){
            break;
        }
    }
}

void insertionSort(int arr[],int n){
    for(int i=1;i<n;i++){
        int x=arr[i];
        int j;
        for(j=i-1;j>=0;j--){
            if(x<arr[j]){
                arr[j+1]=arr[j];
            }
            else{
                break;
            }
        }
        arr[j+1]=x;
    }
}

void selectionSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int j,k=i;
        for(int j=i;j<n;j++){
            if(arr[k]>arr[j]){
                k=j;
            }
        }
        int temp = arr[i];
        arr[i]=arr[k];
        arr[k]=temp;
    }
}

int main(){
    int arr[]={2,5,1,0,50,48,34,58,2,9};
    int n = sizeof(arr)/sizeof(int);
    selectionSort(arr,n);
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}

