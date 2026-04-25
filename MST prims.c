#include <stdio.h>

#define MAX 10

int main() {
    int n, i, j, min, mincost = 0;
    int cost[MAX][MAX], visited[MAX] = {0};

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if(cost[i][j] == 0)
                cost[i][j] = 999;
        }
    }

    visited[1] = 1;

    printf("\nEdges in MST:\n");

    int edges = 0;
    while(edges < n - 1) {
        min = 999;

        for(i = 1; i <= n; i++) {
            if(visited[i]) {
                for(j = 1; j <= n; j++) {
                    if(!visited[j] && cost[i][j] < min) {
                        min = cost[i][j];
                        int a = i, b = j;
                        
                        // store edge
                        printf("%d - %d = %d\n", a, b, min);
                        mincost += min;
                        visited[b] = 1;
                        edges++;
                    }
                }
            }
        }
    }

    printf("\nMinimum cost = %d\n", mincost);
    return 0;
}
