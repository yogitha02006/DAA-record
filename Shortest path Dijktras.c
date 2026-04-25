#include <stdio.h>

#define MAX 10
#define INF 999

int main() {
    int n, i, j, start;
    int cost[MAX][MAX], distance[MAX], visited[MAX] = {0};

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if(cost[i][j] == 0 && i != j)
                cost[i][j] = INF;
        }
    }

    printf("Enter starting vertex (0 to %d): ", n-1);
    scanf("%d", &start);

    // Initialize distances
    for(i = 0; i < n; i++) {
        distance[i] = cost[start][i];
    }

    visited[start] = 1;
    distance[start] = 0;

    // Find shortest paths
    for(i = 1; i < n; i++) {
        int min = INF, u;

        for(j = 0; j < n; j++) {
            if(!visited[j] && distance[j] < min) {
                min = distance[j];
                u = j;
            }
        }

        visited[u] = 1;

        for(j = 0; j < n; j++) {
            if(!visited[j] && distance[u] + cost[u][j] < distance[j]) {
                distance[j] = distance[u] + cost[u][j];
            }
        }
    }

    printf("\nShortest distances from vertex %d:\n", start);
    for(i = 0; i < n; i++) {
        printf("To %d = %d\n", i, distance[i]);
    }

    return 0;
}
