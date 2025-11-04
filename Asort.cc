#include "myheaders.h"

//Bubble sort : Matt
//commit
// Your ASort function(s) goes here ..
void bubbleSort(){
	bool swapped;
	for (int i = 0; i < n - 1){
		swapped = false;
		for (int j = 0; j < n - 1 - i; j++){
			if (arr[j] > arr[j + 1]){
				long temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp; 
				swapped = true;
			}
		}
	}
		
}