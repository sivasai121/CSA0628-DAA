#include <stdio.h>

#define MAX_ITEMS 100
#define MAX_CONTAINERS 100

void containerLoader(int items[], int n, int capacity) {
    int containers[MAX_CONTAINERS] = {0}; // Array to store the remaining capacity of each container
    int containerCount = 0; // Number of containers used
    int currentItem = 0;

    for (int i = 0; i < n; i++) {
        if (containers[currentItem] + items[i] <= capacity) {
            containers[currentItem] += items[i];
        } else {
            containerCount++;
            currentItem++;
            containers[currentItem] += items[i];
        }
    }

    printf("Number of containers used: %d\n", containerCount + 1);
    printf("Remaining capacity of containers:\n");
    for (int i = 0; i <= containerCount; i++) {
        printf("Container %d: %d\n", i + 1, capacity - containers[i]);
    }
}

int main() {
    int items[MAX_ITEMS];
    int n, capacity;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("Enter the capacity of each container: ");
    scanf("%d", &capacity);

    printf("Enter the dimensions of each item:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &items[i]);
    }

    containerLoader(items, n, capacity);

    return 0;
}
