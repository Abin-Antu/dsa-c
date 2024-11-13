#include <stdio.h>

void swap(int a[], int k, int c) {
    int temp = a[k];
    a[k] = a[c];
    a[c] = temp;
}

int partition(int a[], int left, int right) {
    int pivot = a[left]; // Use leftmost element as pivot
    int i = left + 1;
    int j = right;
    
    while (i <= j) {
        // Move i to the right, while a[i] < pivot
        while (i <= right && a[i] < pivot) {
            i++;
        }
        // Move j to the left, while a[j] > pivot
        while (a[j] > pivot) {
            j--;
        }
        // If valid, swap elements
        if (i < j) {
            swap(a, i, j);
        }
    }
    // Swap pivot into the correct position
    swap(a, left, j);
    return j; // Return the partition index
}

void quickSort(int a[], int left, int right) {
    if (left < right) {
        int pivotIndex = partition(a, left, right);  // Partition the array
        quickSort(a, left, pivotIndex - 1);  // Sort left part
        quickSort(a, pivotIndex + 1, right); // Sort right part
    }
}

int main() {
    int n;
    
    printf("Enter the size of the Array:\n");
    scanf("%d", &n);
    
    int a[n];  // Dynamically allocated array
    
    printf("Enter the elements into the Array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    quickSort(a, 0, n - 1);  // Call the quicksort function first and last index
    
    printf("Sorted Array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t", a[i]);
    }
    printf("\n");

    return 0;
}
