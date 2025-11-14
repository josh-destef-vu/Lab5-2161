//Josh DeStefano

#include "myheaders.h"

//to find max value of the array
long getMax(long arr[], int n) {

	long max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }

    return max;
}

//go through and determine how many numbers are in each digit place
void countSort(long arr[], int n, long exp) {
    long output[n];
    int count[10] = {0};

    //Count total of each digit
    for (int i = 0; i < n; i++) {
        int digit = (arr[i] / exp) % 10;
        count[digit]++;
    }

    //stores positions
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    //Builds the output array
    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    //put back into original array
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

void Radixsort(long arr[], int n) {
    long maxi = getMax(arr, n);

    // least sig --> most sig
    for (long exp = 1; maxi / exp > 0; exp *= 10) {
        countSort(arr, n, exp);
    }
}




