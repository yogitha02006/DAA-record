#include <stdio.h>
#include <string.h>

#define MAX 10
#define INF 999

int n;
int capacity[MAX][MAX];
int residual[MAX][MAX];
int visited[MAX];
int parent[MAX];

// BFS to find augmenting path
int bfs(int s, int t) {
    int queue[MAX], front = 0, rear = 0;
    memset(visited, 0, sizeof(visited));

    queue[rear++] = s;
    visited[s] = 1;
    parent[s] = -1;

    while(front < rear) {
        int u = queue[front++];

        for(int v = 0; v < n; v++) {
            if(!visited[v] && residual[u][v] > 0) {
                queue[rear++] = v;
                parent[v] = u;
                visited[v] = 1;
            }
        }
    }
    return visited[t];
}

// Ford-Fulkerson function
int maxFlow(int s, int t) {
    int u, v;
    int max_flow = 0;

    // Initialize residual graph
    for(u = 0; u < n; u++) {
        for(v = 0; v < n; v++) {
            residual[u][v] = capacity[u][v];
        }
    }

    // While there is a path from source to sink
    while(bfs(s, t)) {
        int path_flow = INF;

        // Find minimum residual capacity in path
        for(v = t; v != s; v = parent[v]) {
            u = parent[v];
            if(residual[u][v] < path_flow)
                path_flow = residual[u][v];
        }

        // Update residual capacities
        for(v = t; v != s; v = parent[v]) {
            u = parent[v];
            residual[u][v] -= path_flow;
            residual[v][u] += path_flow;
        }

        max_flow += path_flow;
    }

    return max_flow;
}

int main() {
    int s, t;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter capacity matrix:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &capacity[i][j]);
        }
    }

    printf("Enter source and sink: ");
    scanf("%d %d", &s, &t);

    int result = maxFlow(s, t);

    printf("\nMaximum Flow = %d\n", result);

    return 0;
}
