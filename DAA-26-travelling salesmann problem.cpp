#include <stdio.h>
#include <limits.h>

#define MAX_CITIES 10

int min(int a, int b) {
    return (a < b) ? a : b;
}

int tsp(int graph[MAX_CITIES][MAX_CITIES], int n, int mask, int pos, int dp[MAX_CITIES][1 << MAX_CITIES]) {
    if (mask == (1 << n) - 1) {
        // All cities have been visited, return to the starting city
        return graph[pos][0];
    }

    if (dp[pos][mask] != -1) {
        // If the result is already computed, return it
        return dp[pos][mask];
    }

    int ans = INT_MAX;

    for (int i = 0; i < n; i++) {
        // Check if the city is not visited yet
        if ((mask & (1 << i)) == 0) {
            int newMask = mask | (1 << i);
            ans = min(ans, graph[pos][i] + tsp(graph, n, newMask, i, dp));
        }
    }

    return dp[pos][mask] = ans;
}

int main() {
    int n;
    printf("Enter the number of cities: ");
    scanf("%d", &n);

    int graph[MAX_CITIES][MAX_CITIES];

    printf("Enter the adjacency matrix for the graph:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // Initialize the dp table with -1
    int dp[MAX_CITIES][1 << MAX_CITIES];
    for (int i = 0; i < MAX_CITIES; i++) {
        for (int j = 0; j < (1 << MAX_CITIES); j++) {
            dp[i][j] = -1;
        }
    }

    int result = tsp(graph, n, 1, 0, dp);

    printf("The minimum cost of the Travelling Salesman Problem is: %d\n", result);

    return 0;
}
