#include <stdio.h>
#include <stdbool.h>
bool isPrime(int num, int i) {
    if (num <= 2) {
        return (num == 2) ? true : false;
    }
    if (num % i == 0) {
        return false;
    }
    if (i * i > num) {
        return true;
    }
    return isPrime(num, i + 1);
}

void printPrimes(int n, int i) {
    if (i <= n) {
        if (isPrime(i, 2)) {
            printf("%d ", i);
        }
        printPrimes(n, i + 1);
    }
}

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    
    printf("Prime numbers up to %d are: ", n);
    printPrimes(n, 2); 
    
    return 0;
}
