// Zachary Buxton
// Selection sorting algorithm

// Include headers file
#include "myheaders.h"

void selectionsort(long data[], int n) {
    // Declare least variable
    int least;

    // Algorithm to sort by selection
    for (int i = 0; i < n - 1; i++) {
        least = i;
        for (int j = i + 1; j < n; j++) {
            if (data[j] < data[least])
                least = j;
        }

        //Josh function fix --> swapping to correct spot in array
        if(least != i) {
        	long temp = data[i];
        	data[i] = data[least];
        	data[least] = temp;
        }
    }
}
