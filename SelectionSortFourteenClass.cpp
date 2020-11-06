#include <iostream>

using namespace std;

void selectionSort(int *arr, int size){
	int minPos; //variable to store the minimum number.
	for(int i=0; i<size-1; i++){ //This iteration is to selection all the numbers from
		// index 0 to the second last element.
		//1. Let us assume the element pointed by arr[i] is minimum.
		minPos = i;
		for(int j=i+1; j<size; j++){ //This iteration is to find the position of minimum number
			// in the given array.
			if(*(arr+j) < *(arr+minPos)){
				minPos = j;
			}
		}
		cout<<"Step: "<<i+1<<endl;
		cout<<"Minimum found: "<<*(arr+minPos)<<endl; // arr[minPos]
		
		//checking if the minimum found is the current index pointed by i.
		if(minPos == i){
			cout<<"continued....."<<endl<<endl;
			continue;
		}
		
		//swap logic.
		int temp = *(arr+i); // temp = arr[i]
		*(arr+i) = *(arr+minPos); // arr[i] = arr[minPos]
		*(arr+minPos) = temp; // arr[minPos] = temp
		
		//printing in each step.
		for(int k=0; k<size; k++){
			cout<<*(arr+k)<<" ";
		}
		cout<<endl<<endl;
	}
}

int main(){
	int arr[10] = {11,21,8,4,32,48,3,87,7,10};
	
	cout<<"The array contains: "<<endl;
	for(int i=0; i<10; i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	
	selectionSort(arr, 10);
	
	cout<<endl<<"After selection sort. "<<endl;
	for(int i=0; i<10; i++){
		cout<<arr[i]<<" ";
	}
	
}
