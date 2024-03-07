#include <stdio.h>
#include <stdbool.h>

#define MAX_V 10

void printSolution(int path[], int V) {
    printf("Hamiltonian Circuit:\n");
    for (int i = 0; i < V; i++) {
        printf("%d ", path[i]);
    }
    printf("%d\n", path[0]);
}

bool isSafe(int v, bool graph[][MAX_V], int path[], int pos, int V) {
    if (graph[path[pos - 1]][v] == 0) {
        return false;
    }

    for (int i = 0; i < pos; i++) {
        if (path[i] == v) {
            return false;
        }
    }

    return true;
}

bool hamCycleUtil(bool graph[][MAX_V], int path[], int pos, int V) {
    if (pos == V) {
        if (graph[path[pos - 1]][path[0]] == 1) {
            return true;
        } else {
            return false;
        }
    }

    for (int v = 1; v < V; v++) {
        if (isSafe(v, graph, path, pos, V)) {
            path[pos] = v;
            if (hamCycleUtil(graph, path, pos + 1, V)) {
                return true;
            }
            path[pos] = -1; // Backtrack
        }
    }

    return false;
}

bool hamCycle(bool graph[][MAX_V], int V) {
    int path[MAX_V];
    for (int i = 0; i < V; i++) {
        path[i] = -1;
    }
    path[0] = 0;

    if (!hamCycleUtil(graph, path, 1, V)) {
        printf("Hamiltonian Circuit does not exist");
        return false;
    }

    printSolution(path, V);
    return true;
}

int main() {
    int V;
    bool graph[MAX_V][MAX_V];

    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &V);

    printf("Enter the adjacency matrix of the graph:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    hamCycle(graph, V);

    return 0;
}
