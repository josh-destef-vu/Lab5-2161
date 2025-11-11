#include "myheaders.h"

//Shell sort : Matt
void shellSort(int arr[], int n) {
    // Start with a large gap, then reduce the gap
    for (int gap = n / 2; gap > 0; gap /= 2) {
        // Do a gapped insertion sort for each element
        for (int i = gap; i < n; i++) {
            long temp = arr[i];
            int j = i;

            // Use a for loop to shift elements of array that are greater 
            // than temp, to one position ahead
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}
