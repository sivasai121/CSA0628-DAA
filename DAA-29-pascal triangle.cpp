#include <stdio.h>

// Function to calculate factorial
int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

// Function to calculate binomial coefficient (n choose k)
int binomialCoefficient(int n, int k) {
    return factorial(n) / (factorial(k) * factorial(n - k));
}

// Function to generate Pascal's triangle
void generatePascalsTriangle(int numRows) {
    for (int i = 0; i < numRows; i++) {
        // Print leading spaces
        for (int j = 0; j < numRows - i - 1; j++) {
            printf(" ");
        }

        // Print elements in current row
        for (int j = 0; j <= i; j++) {
            printf("%d ", binomialCoefficient(i, j));
        }

        printf("\n");
    }
}

int main() {
    int numRows;
    printf("Enter the number of rows for Pascal's triangle: ");
    scanf("%d", &numRows);

    generatePascalsTriangle(numRows);

    return 0;
}
