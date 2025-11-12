// Zachary Buxton
// Counting sorting algorithm

// Include headers file and vector file
#include "myheaders.h"


void Countingsort(long arr[], int n) {
    // No sort needed
    if (n <= 0) {
        return;
    }

    // Find the max and min vals in the array
    long minVal = arr[0];
    long maxVal = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < minVal) minVal = arr[i];
        if (arr[i] > maxVal) maxVal = arr[i];
    }

    // Calc Range
    long range = maxVal - minVal + 1;

    // Declare and initialize count array
    long *count = new long[range]();

    // Store the counts of each number
    for (int i = 0; i < n; i++) {
        count[arr[i] - minVal]++;
    }

    // Save to original array
    int index = 0;
    for (long i = 0; i < range; i++) {
        while (count[i] > 0) {
            arr[index++] = i + minVal;
            count[i]--;
        }
    }

    // Free memory
    delete[] count;
}



