#include <stdio.h>
#include <stdbool.h>

#define MAX_V 10

void printSolution(int color[], int V) {
    printf("Solution Exists:\nThe assigned colors are:\n");
    for (int i = 0; i < V; i++) {
        printf("Vertex %d: Color %d\n", i, color[i]);
    }
}

bool isSafe(int graph[][MAX_V], int vertex, int color[], int c, int V) {
    for (int i = 0; i < V; i++) {
        if (graph[vertex][i] && c == color[i]) {
            return false;
        }
    }
    return true;
}

bool graphColoringUtil(int graph[][MAX_V], int m, int color[], int vertex, int V) {
    if (vertex == V) {
        return true;
    }

    for (int c = 1; c <= m; c++) {
        if (isSafe(graph, vertex, color, c, V)) {
            color[vertex] = c;
            if (graphColoringUtil(graph, m, color, vertex + 1, V)) {
                return true;
            }
            color[vertex] = 0; // Backtrack
        }
    }

    return false;
}

bool graphColoring(int graph[][MAX_V], int m, int V) {
    int color[MAX_V];
    for (int i = 0; i < V; i++) {
        color[i] = 0;
    }

    if (!graphColoringUtil(graph, m, color, 0, V)) {
        printf("Solution does not exist");
        return false;
    }

    printSolution(color, V);
    return true;
}

int main() {
    int graph[MAX_V][MAX_V];
    int V, m;

    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &V);

    printf("Enter the adjacency matrix of the graph:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the number of colors: ");
    scanf("%d", &m);

    if (!graphColoring(graph, m, V)) {
        printf("Failed to color the graph.");
    }

    return 0;
}
