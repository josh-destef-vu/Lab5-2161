// Zachary Buxton
// Counting sorting algorithm

// Include headers file and vector file
#include "myheaders.h"
#include <vector>

void Countingsort(long data[], int n) {
    // Case where there is nothing to sort
    if (n <= 1) return;

    // Find the min and max values of the array
    long minVal = data[0];
    long maxVal = data[0];
    for (int i = 1; i < n; i++) {
        if (data[i] < minVal) minVal = data[i];
        if (data[i] > maxVal) maxVal = data[i];
    }
    // Calculate the range of the array
    long range = maxVal - minVal + 1;

    // Initialize counting array in a vector
    vector<long> count(range, 0);

    // Count the frequency of each element
    for (int i = 0; i < n; i++)
        count[data[i] - minVal]++;

    // Calculate the prefix sums
    for (int i = 1; i < range; i++)
        count[i] += count[i - 1];

    // Create the output array using vectors
    vector<long> output(n);
    for (int i = n - 1; i >= 0; i--) {
        output[count[data[i] - minVal] - 1] = data[i];
        count[data[i] - minVal]--;
    }

    // Copy the sorted data back into data array
    for (int i = 0; i < n; i++)
        data[i] = output[i];
}



