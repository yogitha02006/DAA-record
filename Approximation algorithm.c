#include <stdio.h>

#define MAX 10

int main() {
    int n, i, j;
    int graph[MAX][MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    int visited[MAX] = {0};

    printf("\nApproximate Vertex Cover:\n");

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            if(graph[i][j] == 1 && !visited[i] && !visited[j]) {
                // include both vertices
                visited[i] = 1;
                visited[j] = 1;

                printf("%d %d\n", i, j);
            }
        }
    }

    return 0;
}
