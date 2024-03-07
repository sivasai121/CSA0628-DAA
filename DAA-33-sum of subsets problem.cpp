#include <stdio.h>
#include <stdbool.h>

#define MAX 100

void printSubset(int subset[], int size) {
    printf("{ ");
    for (int i = 0; i < size; i++) {
        printf("%d ", subset[i]);
    }
    printf("}\n");
}

void sumOfSubsets(int set[], int subset[], int n, int subSize, int total, int nodeCount, int sum) {
    if (total == sum) {
        printSubset(subset, subSize); // Print the subset with the required sum
        if (nodeCount + 1 < n && total - set[nodeCount] + set[nodeCount + 1] <= sum) {
            // Exclude previous added item and consider next candidate
            sumOfSubsets(set, subset, n, subSize - 1, total - set[nodeCount], nodeCount + 1, sum);
        }
        return;
    } else {
        // Consider the next element in the set
        for (int i = nodeCount; i < n; i++) {
            subset[subSize] = set[i];
            if (total + set[i] <= sum) {
                // Move to the next node with updated parameters
                sumOfSubsets(set, subset, n, subSize + 1, total + set[i], i + 1, sum);
            }
        }
    }
}

void subsetSums(int set[], int n, int sum) {
    int subset[MAX];
    sumOfSubsets(set, subset, n, 0, 0, 0, sum);
}

int main() {
    int set[MAX];
    int n, sum;

    printf("Enter the number of elements in the set: ");
    scanf("%d", &n);

    printf("Enter the elements of the set: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &set[i]);
    }

    printf("Enter the target sum: ");
    scanf("%d", &sum);

    printf("Subsets with sum %d are:\n", sum);
    subsetSums(set, n, sum);

    return 0;
}
