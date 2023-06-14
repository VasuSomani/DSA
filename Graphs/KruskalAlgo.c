#include<stdio.h>
#include<stdlib.h>

struct edge{
    int weight;
    int src;
    int dest;
}Edges[25];

void edgeSort(){
    int n=25;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if((Edges[j]).weight>(Edges[j+1]).weight){
                struct edge temp = Edges[j];
                Edges[j] = Edges[j+1];
                Edges[j+1] = temp;
            }
        }
    }
}

void kruskalAlgo(){
    int n=25;
    int minWeight=0;
    int visited[n];
    for(int i=0;i<n;i++){
        visited[i]=0;
    }
    for(int i=0;i<n;i++){
        if(Edges[i].weight!=0 && !(visited[Edges[i].dest]==1 && visited[Edges[i].src]==1)){
            minWeight+=Edges[i].weight;
            visited[Edges[i].src]=1;
            visited[Edges[i].dest]=1;
        }
    }
    printf("\n%d",minWeight);
}

int main(){
    int adj[5][5]={
        {0,1,0,0,1},
        {1,0,1,0,0},
        {0,1,0,1,1},
        {0,0,1,0,0},
        {1,0,1,0,0}
    };
    int numVertices = 5;
    int k=0;
    for(int i=0;i<5;i++){
        for(int j=i+1;j<5;j++){
            if(adj[i][j]==1){
                (Edges[k]).src=i;
                (Edges[k]).dest=j;
                (Edges[k]).weight=i+j+1;
                k++;
            }
        }
    }
    edgeSort();
    for(int i=0;i<25;i++){
        printf("%d ",(Edges[i]).weight);
    }
    kruskalAlgo();
}