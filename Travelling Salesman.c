#include <stdio.h>
#define MAX 10
#define INF 99999

int n, cost[MAX][MAX];
int visited[MAX];

// Function to find minimum of two numbers
int min(int a, int b) {
    return (a < b) ? a : b;
}

// Recursive TSP function
int tsp(int city, int count) {
    int i, ans = INF;

    // If all cities visited, return cost to go back to start
    if(count == n && cost[city][0]) {
        return cost[city][0];
    }

    for(i = 0; i < n; i++) {
        if(!visited[i] && cost[city][i]) {
            visited[i] = 1;

            int temp = cost[city][i] + tsp(i, count + 1);
            ans = min(ans, temp);

            visited[i] = 0; // backtrack
        }
    }

    return ans;
}

int main() {
    int i, j;

    printf("Enter number of cities: ");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    for(i = 0; i < n; i++)
        visited[i] = 0;

    visited[0] = 1; // start from city 0

    int result = tsp(0, 1);

    printf("\nMinimum travelling cost = %d\n", result);

    return 0;
}
