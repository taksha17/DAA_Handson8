#include <stdio.h>

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

int quickselect(int arr[], int low, int high, int i) {
    if (low == high) {
        return arr[low];
    }

    int pivotIndex = partition(arr, low, high);

    int k = pivotIndex - low + 1;
    if (i == k) {
        return arr[pivotIndex];
    } else if (i < k) {
        return quickselect(arr, low, pivotIndex - 1, i);
    } else {
        return quickselect(arr, pivotIndex + 1, high, i - k);
    }
}

// Here the below main method shows an example usage and implementation of the quicksort
// Here a random array of 7 elements is chosen and the 3rd smallest element is found after quick sort implementation.

int main() {
    int arr[] = {10, 4, 92, 8, 30, 11, 26};
    int n = sizeof(arr) / sizeof(arr[0]);
    int i = 3;
    printf("The %drd smallest element is %d\n", i, quickselect(arr, 0, n - 1, i));
    return 0;
}






//Author : Taksha Sachin Thosani
//UTA ID: 1002086312
//Net ID : txt6312