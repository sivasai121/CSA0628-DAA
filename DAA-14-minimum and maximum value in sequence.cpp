#include <stdio.h>
#include <limits.h>

void min_max_sequence(int numbers[], int length) {
    for (int i = 0; i < length; i++) {
        int min_val = INT_MAX;
        int max_val = INT_MIN;
        for (int j = 0; j <= i; j++) {
            if (numbers[j] < min_val)
                min_val = numbers[j];
            if (numbers[j] > max_val)
                max_val = numbers[j];
        }
        printf("For %d: Minimum = %d, Maximum = %d\n", numbers[i], min_val, max_val);
    }
}

int main() {
    int numbers[] = {1, 3, 5, 7, 9};
    int length = sizeof(numbers) / sizeof(numbers[0]);
    min_max_sequence(numbers, length);
    return 0;
}
