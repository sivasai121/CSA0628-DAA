#include <stdio.h>
#include <stdlib.h>

// Structure to represent an item
struct Item {
    int value;
    int weight;
};

// Function to compare items based on their value-to-weight ratio
int compare(const void *a, const void *b) {
    double ratio1 = ((double)((struct Item *)a)->value) / ((struct Item *)a)->weight;
    double ratio2 = ((double)((struct Item *)b)->value) / ((struct Item *)b)->weight;
    return (ratio2 > ratio1) ? 1 : -1; // Sort in decreasing order of value-to-weight ratio
}

// Function to solve the fractional knapsack problem
double knapsack(struct Item items[], int n, int capacity) {
    // Sort items based on their value-to-weight ratio
    qsort(items, n, sizeof(items[0]), compare);

    double totalValue = 0.0;
    int remainingCapacity = capacity;

    // Iterate through the sorted items
    for (int i = 0; i < n; i++) {
        // If the weight of the current item fits in the knapsack, take it completely
        if (items[i].weight <= remainingCapacity) {
            totalValue += items[i].value;
            remainingCapacity -= items[i].weight;
        } 
        // Otherwise, take a fraction of the item to fill the remaining capacity
        else {
            totalValue += ((double)items[i].value / items[i].weight) * remainingCapacity;
            break; // Knapsack is full
        }
    }

    return totalValue;
}

int main() {
    int n, capacity;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    struct Item items[n];
    printf("Enter the value and weight of each item:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d: ", i + 1);
        scanf("%d %d", &items[i].value, &items[i].weight);
    }

    double maxValue = knapsack(items, n, capacity);
    printf("Maximum value that can be obtained: %.2lf\n", maxValue);

    return 0;
}
