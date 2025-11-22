//Josh DeStefano
//Comb Sort Algo

#include "myheaders.h"


void Combsort(long arr[], int n) {
    int gap = n;
    bool swapped = true;

    //shrink factor = 1.3 (standard for comb sort)
    while (gap > 1 || swapped) {

        //update gap
        gap = (gap * 10) / 13; //using recommended implementation of 10/13 instead of 1.3 based on reading
        if (gap < 1){
            gap = 1;
        }

        swapped = false;

        //gapped comparison
        for (int i = 0; i + gap < n; i++) {
            if (arr[i] > arr[i + gap]) {
                long temp = arr[i];
                arr[i] = arr[i + gap];
                arr[i + gap] = temp;
                swapped = true;
            }
        }
    }
}
