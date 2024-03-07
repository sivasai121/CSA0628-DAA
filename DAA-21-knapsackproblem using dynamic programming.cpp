#include<stdio.h>

// Function to find the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to solve knapsack problem using dynamic programming
int knapsack(int W, int wt[], int val[], int n, int selected[]) {
    int i, w;
    int K[n+1][W+1];

    // Build table K[][] in bottom-up manner
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i==0 || w==0)
                K[i][w] = 0;
            else if (wt[i-1] <= w)
                K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]], K[i-1][w]);
            else
                K[i][w] = K[i-1][w];
        }
    }

    // Find the selected items
    w = W;
    for (i = n; i > 0 && K[i][w] > 0; i--) {
        if (K[i][w] != K[i-1][w]) {
            selected[i-1] = 1;
            w -= wt[i-1];
        } else {
            selected[i-1] = 0;
        }
    }

    return K[n][W];
}

// Driver program to test above function
int main() {
    int val[100], wt[100], W, n;
    
    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("Enter the values of the items:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &val[i]);
    }

    printf("Enter the weights of the items:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &wt[i]);
    }

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &W);

    int selected[100];
    int max_value = knapsack(W, wt, val, n, selected);
    
    printf("Maximum value that can be obtained is %d\n", max_value);
    printf("Solution set: ");
    for (int i = 0; i < n; i++) {
        if (selected[i]) {
            printf("%d ", i + 1);
        }
    }
    printf("\n");

    return 0;
}
