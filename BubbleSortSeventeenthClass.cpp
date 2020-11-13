#include <iostream>

using namespace std;

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
	
	cout<<"Before Sorting.. "<<endl;
	for(int i=0; i<5; i++){
		cout<<array[i]<<" ";
	}
	
	bubbleSort(array, 5);
	
	cout<<endl<<"After Sorting.. "<<endl;
	for(int i=0; i<5; i++){
		cout<<array[i]<<" ";
	}
}


