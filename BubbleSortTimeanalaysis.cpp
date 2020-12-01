#include <iostream>

using namespace std;

void insertionSort(int *array, int size) {
  for (int i = 1; i < size; i++) { // from second element to last.
    int key = *(array+i); // set the second elemtn the key.
    int j = i-1; // indexing for element right to key which is assumed to be sorted.
    // Compare key with each element on the left of it until an element smaller than
    // it is found.
    while (key < *(array+j) && j >= 0) { //key < array[j]
      	*(array+j+1) = *(array+j); //array[j+1] = array[j]
      	--j;
    }
    *(array+j+1) = key; //array[j+1] = key.
  }
}

void bubbleSort(int *arr, int n){
	do{
		for(int i=1; i<n; i++){
			if(arr[i-1] > arr[i]){
				int temp = arr[i-1];
				arr[i-1] = arr[i];
				arr[i] = temp;
			}
		}
		n--;
	}while(n!=0);
}

int main(){
	int array[5] = {8,7,3,10,2};
	bubbleSort(array, 5);
	insertionSort(array, 5);
}


