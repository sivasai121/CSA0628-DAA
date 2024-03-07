#include <stdio.h>
#include <stdlib.h>
#include <float.h>

int main() {
    int n;
    printf("Enter the number of keys: ");
    scanf("%d", &n);

    float keys[n], probs[n];
    printf("Enter the keys:\n");
    for (int i = 0; i < n; i++) {
        scanf("%f", &keys[i]);
    }

    printf("Enter the probabilities:\n");
    for (int i = 0; i < n; i++) {
        scanf("%f", &probs[i]);
    }

    float dp[n][n];

    for (int i = 0; i < n; i++) {
        dp[i][i] = probs[i];
    }

    for (int length = 2; length <= n; length++) {
        for (int i = 0; i <= n - length; i++) {
            int j = i + length - 1;
            dp[i][j] = FLT_MAX;

            float sum_probs = 0;
            for (int p = i; p <= j; p++) {
                sum_probs += probs[p];
            }

            for (int k = i; k <= j; k++) {
                float cost = ((k > i) ? dp[i][k - 1] : 0) + ((k < j) ? dp[k + 1][j] : 0) + sum_probs;
                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                }
            }
        }
    }

    printf("Optimal Binary Search Tree Costs:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j >= i) {
                printf("%.2f\t", dp[i][j]);
            } else {
                printf("\t");
            }
        }
        printf("\n");
    }

    printf("Cost of optimal BST is: %.2f\n", dp[0][n - 1]);

    return 0;
}
