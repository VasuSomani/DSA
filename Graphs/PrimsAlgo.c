#include<stdio.h>
#include<stdlib.h>

struct edge {
    int weight;
    int src;
    int dest;
} Edges[25];

struct edge* sortWeights(struct edge E, int adj[][5]) {
    struct edge* sortedWeight = malloc(5 * sizeof(struct edge));
    int n = 25;
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (Edges[i].src == E.src) {
            sortedWeight[count++] = Edges[i];
        }
    }

    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (sortedWeight[j].weight > sortedWeight[j + 1].weight) {
                struct edge temp = sortedWeight[j];
                sortedWeight[j] = sortedWeight[j + 1];
                sortedWeight[j + 1] = temp;
            }
        }
    }

    return sortedWeight;
}

void primsAlgo(int adj[][5]) {
    int n = 25;
    int minWeight = 0;
    int visited[5] = { 0 };

    visited[0] = 1;

    for (int i = 0; i < n; i++) {
        if (Edges[i].weight != 0 && !(visited[Edges[i].dest] == 1 && visited[Edges[i].src] == 1)) {
            struct edge* sortedWeight = sortWeights(Edges[i], adj);

            for (int j = 0; j < 5; j++) {
                if (visited[sortedWeight[j].dest] == 0) {
                    visited[sortedWeight[j].dest] = 1;
                    minWeight += sortedWeight[j].weight;
                    break;
                }
            }

            free(sortedWeight);
        }
    }

    printf("%d", minWeight);
}

int main() {
    int adj[5][5] = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 1},
        {0, 0, 1, 0, 0},
        {1, 0, 1, 0, 0}
    };

    int numVertices = 5;
    int k = 0;

    for (int i = 0; i < 5; i++) {
        for (int j = i + 1; j < 5; j++) {
            if (adj[i][j] == 1) {
                Edges[k].src = i;
                Edges[k].dest = j;
                Edges[k].weight = i + j + 1;
                k++;
            }
        }
    }

    primsAlgo(adj);

    return 0;
}
