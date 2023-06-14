#include<stdio.h>

int findMax(int arr[],int n){
    int max = -99999;
    for(int i=0;i<n;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    return max;
}
void countSort(int arr[],int n){
    int max=findMax(arr,n);
    int count[max+1];
    for(int i=0;i<max+1;i++){ //assign all elements to 0
        count[i]=0;
    }
    for(int i=0;i<n;i++){  //No of occurence of same element
        count[arr[i]]++;
    }
    int i,j;
    i=j=0;
    while(i<max+1){ //Transfer elements to main array in sorted form
        while(count[i]!=0){
            arr[j++]=i;
            count[i]--;
        }
        i++;
    }
}


int main(){
    int arr[]={1,5,2,9,5,0,6,5,2,2,1,6,7,9};
    int n = sizeof(arr)/sizeof(int);
    countSort(arr,n);
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}