#include<stdio.h>

void dfs(int adj[][5],int start,int n,int visited[]){
    printf("%d ",start);
    visited[start]=1;
    for(int i=0;i<n;i++){
        if(adj[start][i]==1 && visited[i]==0){
            dfs(adj,i,n,visited);
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
    int visited[5];
    for(int i=0;i<5;i++){
        visited[i]=0;
    }
    dfs(adj,0,numVertices,visited);
}