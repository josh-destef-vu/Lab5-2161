//Josh DeStefano
//Radix Sort

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

//find the smallest value in the array
long getMin(long arr[], int n) {

	long min = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] < min)
            min = arr[i];
    }

    return min;
}


//go through and determine how many numbers are in each digit place
void countSort(long arr[], int n, long exp) {
    long* output = new long[n]; //dynamic allocation because program breaks otherwise
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

    delete[] output;
}

void Radixsort(long arr[], int n) {

	long mini = getMin(arr, n); //get smallest value

	//create offset to add adjust all numbers to be positive so radix
	//sort executes properly
	long offset = 0;
	if (mini < 0){
		offset = mini;
		for (int i = 0; i < n; i++){
			arr[i] -= offset;
		}
	}


	//find maximum value
	long maxi = getMax(arr, n);

    //loop through each digit position starting with Least Significant
	//exp = 1 is 1s place, 10 is 10s place, etc.
	//continue until maxi/exp <= 0
    for (long exp = 1; maxi / exp > 0; exp *= 10) {
        countSort(arr, n, exp);
    }


    //readjust all values from earlier back to real values
    if(offset != 0){
    	for(int i = 0; i < n; i++){
    		arr[i] += offset;
    	}
    }
}




