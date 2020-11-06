#include <iostream>

using namespace std;

void insertionRecursiveSort(int *array, int size){
	if(size > 0){
		insertionRecursiveSort(array, size-1);
		int x = *(array+size);
		int j = size-1;
		while(j >= 0 && *(array+j) > x){
			*(array+j+1) = *(array+j);
			j--;
		}
		*(array+j+1) = x;
	}
}

void insertionSort(int *array, int size) {
  for (int i = 1; i < size; i++) { // from second element to last.
    int key = *(array+i); // set the second elemtn the key.
    int j = i-1; // indexing for element right to key which is assumed to be sorted.
	cout<<"Step: "<<i<<endl;
	cout<<"Key: "<<key<<endl;
    // Compare key with each element on the left of it until an element smaller than
    // it is found.
    cout<<"Before change: "<<endl;
    cout<<"The array contains: "<<endl;
    
	for(int k=0; k<size; k++){
		cout<<*(array+k)<<" ";
	}
	
    while (key < *(array+j) && j >= 0) { //key < array[j]
      	*(array+j+1) = *(array+j); //array[j+1] = array[j]
      	--j;
    }
    *(array+j+1) = key; //array[j+1] = key.
    cout<<endl<<"After change: "<<endl;
    cout<<"The array contains: "<<endl;
    for(int k=0; k<size; k++){
		cout<<*(array+k)<<" ";
	}
    cout<<endl<<endl;
  }
}

int main(){
	int arr[10] = {4,2,98,45,32,48,3,8,7,1};
	
	cout<<"The array contains: "<<endl;
	for(int i=0; i<10; i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl<<endl;
	
	insertionRecursiveSort(arr, 10);
	
	cout<<endl<<"After insertion sort. "<<endl;
	for(int i=0; i<10; i++){
		cout<<arr[i]<<" ";
	}
	
}
