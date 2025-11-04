// Zachary Buxton
// Selection sorting algorithm

// Include headers file
#include <iostream>
#include "myheaders.h"
using namespace std;

void selectionsort(long data[], int n) {
    int least;

    for (int i = 0; i < n - 1; i++) {
        least = i;
        for (int j = i + 1; j < n; j++) {
            if (data[j] < data[least])
                least = j;
        }
    }
}
