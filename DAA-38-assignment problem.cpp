#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Structure to represent an item
struct Item {
    int profit;
    int weight;
    float ratio;
};

// Structure to represent a node in the branch and bound tree
struct Node {
    int level;
    int profit;
    int weight;
    float bound;
};

// Function prototypes
float calculateBound(struct Node u, int n, int W, struct Item arr[]);
void branchAndBound(int n, int W, struct Item arr[]);

// Function to calculate the upper bound of a node
float calculateBound(struct Node u, int n, int W, struct Item arr[]) {
    if (u.weight >= W) {
        return 0;
    }

    float profitBound = u.profit;
    int j = u.level + 1;
    int totalWeight = u.weight;

    while (j < n && totalWeight + arr[j].weight <= W) {
        totalWeight += arr[j].weight;
        profitBound += arr[j].profit;
        j++;
    }

    if (j < n) {
        profitBound += (W - totalWeight) * arr[j].ratio;
    }

    return profitBound;
}

// Function to perform branch and bound algorithm
void branchAndBound(int n, int W, struct Item arr[]) {
    struct Node u, v;
    int maxProfit = 0;

    // Create a priority queue for storing nodes
    struct PQ {
        struct Node data[100];
        int front;
        int rear;
    } pq;

    pq.front = pq.rear = -1;

    // Create the root node
    u.level = -1;
    u.profit = u.weight = 0;
    u.bound = calculateBound(u, n, W, arr);

    // Enqueue the root node
    pq.data[++pq.rear] = u;

    while (pq.front != pq.rear) {
        // Dequeue a node
        u = pq.data[++pq.front];

        // If it's a leaf node, update maxProfit if needed
        if (u.level == n - 1) {
            if (u.profit > maxProfit) {
                maxProfit = u.profit;
            }
        } else {
            // Otherwise, generate child nodes
            v.level = u.level + 1;
            v.weight = u.weight + arr[v.level].weight;
            v.profit = u.profit + arr[v.level].profit;

            if (v.weight <= W && v.profit > maxProfit) {
                maxProfit = v.profit;
            }

            v.bound = calculateBound(v, n, W, arr);

            if (v.bound > maxProfit) {
                pq.data[++pq.rear] = v; // Enqueue the node
            }

            v.weight = u.weight;
            v.profit = u.profit;
            v.bound = calculateBound(v, n, W, arr);

            if (v.bound > maxProfit) {
                pq.data[++pq.rear] = v; // Enqueue the node
            }
        }
    }

    printf("Total profit: %d\n", maxProfit);
}

int main() {
    int n, W;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    struct Item arr[n];
    printf("Enter the profits and weights for each item:\n");
    for (int i = 0; i < n; i++) {
        printf("Enter profit and weight for item %d: ", i + 1);
        scanf("%d %d", &arr[i].profit, &arr[i].weight);
        arr[i].ratio = (float)arr[i].profit / arr[i].weight; // Calculate profit/weight ratio
    }

    printf("Enter the knapsack capacity: ");
    scanf("%d", &W);

    branchAndBound(n, W, arr);

    return 0;
}
