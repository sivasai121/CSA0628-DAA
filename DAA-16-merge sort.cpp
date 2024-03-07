#include <stdio.h>

int main() {
    int m, n;
    printf("Enter the number of elements in nums1: ");
    scanf("%d", &m);

    int nums1[m];
    printf("Enter the elements of nums1 in non-increasing order:\n");
    for (int i = 0; i < m; i++) {
        scanf("%d", &nums1[i]);
    }

    printf("Enter the number of elements in nums2: ");
    scanf("%d", &n);

    int nums2[n];
    printf("Enter the elements of nums2 in non-increasing order:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums2[i]);
    }

    int merged[m + n];

    // Merge Sort nums1
    for (int i = 0; i < m - 1; i++) {
        for (int j = 0; j < m - i - 1; j++) {
            if (nums1[j] < nums1[j + 1]) {
                int temp = nums1[j];
                nums1[j] = nums1[j + 1];
                nums1[j + 1] = temp;
            }
        }
    }

    // Merge Sort nums2
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (nums2[j] < nums2[j + 1]) {
                int temp = nums2[j];
                nums2[j] = nums2[j + 1];
                nums2[j + 1] = temp;
            }
        }
    }

    // Merge nums1 and nums2 into merged in ascending order
    int i = 0, j = 0, k = 0;
    while (i < m && j < n) {
        if (nums1[i] <= nums2[j]) {
            merged[k++] = nums1[i++];
        } else {
            merged[k++] = nums2[j++];
        }
    }

    while (i < m) {
        merged[k++] = nums1[i++];
    }

    while (j < n) {
        merged[k++] = nums2[j++];
    }

    // Sorting merged array in ascending order using bubble sort
    for (int i = 0; i < m + n - 1; i++) {
        for (int j = 0; j < m + n - i - 1; j++) {
            if (merged[j] > merged[j + 1]) {
                int temp = merged[j];
                merged[j] = merged[j + 1];
                merged[j + 1] = temp;
            }
        }
    }

    // Print merged array
    printf("A * B = (");
    for (int i = 0; i < m + n; i++) {
        printf("%d", merged[i]);
        if (i < m + n - 1) {
            printf(", ");
        }
    }
    printf(")\n");

    return 0;
}
