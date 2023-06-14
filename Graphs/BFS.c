#include<stdio.h>

void bfs(int adj[][5],int start,int n){
    int queue[n];
    int front,rear;
    front=rear=-1;
    int visited[n]; //Visited Array
    for(int i=0;i<n;i++){ //Iniitalize as 0 (not visited) initally
        visited[i]=0;
    }

    queue[++rear]=start;
    visited[start]=1;
    while(front!=rear){
        int x=queue[++front];
        printf("%d ",x);
        for(int i=0;i<n;i++){
            if(adj[x][i]==1 && visited[i]==0){
                visited[i]=1;
                queue[++rear]=i;
            }
        }
    }
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
    bfs(adj,0,numVertices);
}