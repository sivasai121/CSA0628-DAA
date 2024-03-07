#include <stdio.h>
#include <math.h>

int isArmstrong(int num, int originalNum, int n) {
    if (num == 0) {
        return 0;
    }
    int digit = num % 10;
    return pow(digit, n) + isArmstrong(num / 10, originalNum, n);
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    
    int n = 0;
    int temp = num;
    while (temp != 0) {
        temp /= 10;
        n++;
    }
    
    int sum = isArmstrong(num, num, n);
    
    if (sum == num) {
        printf("%d is an Armstrong number.\n", num);
    } else {
        printf("%d is not an Armstrong number.\n", num);
    }
    
    return 0;
}
