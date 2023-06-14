#include<stdio.h>

int partition(int arr[],int l,int h,int piv){
    int i=l;
    int j=h;
    do{
        while(!(arr[i]>arr[piv]) && i<=h){
            i++;
        }
        while(!(arr[j]<=arr[piv])){
            j--;
        }
        if(i<j){
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
    while(i<j);
    int temp=arr[piv];
    arr[piv]=arr[j];
    arr[j]=temp;
    return j;
}

void quickSort(int arr[],int l,int h,int pivot){
    if(l<h){
        int j=partition(arr,l,h,pivot);
        quickSort(arr,l,j-1,l);
        quickSort(arr,j+1,h,l);
    }
}

int main(){
    int arr[] = {6,3,9,1,23,45,11,2,1,5,91,69};
    int n= sizeof(arr)/sizeof(int);
    quickSort(arr,0,n-1,5);
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}