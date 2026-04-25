#include <stdio.h>

#define MAX 10

int parent[MAX];

// Find parent (for cycle detection)
int find(int i) {
    while(parent[i])
        i = parent[i];
    return i;
}

// Union of two sets
void unionSet(int i, int j) {
    parent[j] = i;
}

int main() {
    int n, i, j, a, b, u, v;
    int min, mincost = 0;
    int cost[MAX][MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if(cost[i][j] == 0)
                cost[i][j] = 999; // no edge
        }
    }

    for(i = 1; i <= n; i++)
        parent[i] = 0;

    printf("\nEdges in MST:\n");

    int edges = 0;
    while(edges < n - 1) {
        min = 999;

        for(i = 1; i <= n; i++) {
            for(j = 1; j <= n; j++) {
                if(cost[i][j] < min) {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }

        u = find(u);
        v = find(v);

        if(u != v) {
            printf("%d - %d = %d\n", a, b, min);
            mincost += min;
            unionSet(u, v);
            edges++;
        }

        cost[a][b] = cost[b][a] = 999;
    }

    printf("\nMinimum cost = %d\n", mincost);
    return 0;
}
