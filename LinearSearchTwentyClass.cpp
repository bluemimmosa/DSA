#include <iostream>

using namespace std;

int binarySearch(int num, int arr[], int n){
	int l = 0;
	int r = n-1;
	int mid;
	while(l<=r){
		mid = (l+r)/2;
		if(arr[mid] < num){
			l = mid+1;
		}
		else if(arr[mid] > num){
			r = mid-1;
		}
		else{
			return mid;
		}
	}
	return -1;
}

int linearSearch(int num, int arr[], int n){
	for(int i=0; i<n; i++){
		if(num == arr[i]){ //num == arr[0]
						// num == arr[1]
						// num == arr[2]
						// num == arr[3]
						// num == arr[4]
						// ......
						// num == arr[n-1]
			return i;
		}
	}
	
	return -1;
}

void insertionSort(int *array, int size) {
  for (int i = 1; i < size; i++) { // from second element to last.
    int key = *(array+i); // set the second elemtn the key.
    int j = i-1; // indexing for element right to key which is assumed to be sorted.
    while (key < *(array+j) && j >= 0) { //key < array[j]
      	*(array+j+1) = *(array+j); //array[j+1] = array[j]
      	--j;
    }
    *(array+j+1) = key; //array[j+1] = key.
  }
}

int main(){
	int num = 45;
	int arr[] = {45, 98, 23, 46, 77, 11, 5, 3, 90};
	int res = -1;
//	cout<<"Enter the number to search: ";
//	cin>>num;
	insertionSort(arr, 9);
	cout<<"After Sorting.."<<endl;
	for(int i=0; i<9; i++){
		cout<<arr[i]<<"\t";
	}
	cout<<endl;
	res = binarySearch(num, arr, 9);
	if(res < 0){
		cout<<endl<<"Cannot find the given number in the array."<<endl;
	}
	else{
		cout<<"Found number at position: "<<res<<endl;
	}
	
	return 0;
}
