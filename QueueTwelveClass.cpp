#include <iostream>

using namespace std;

class queue{
	public:
	int *base;
	int front; // stores the front index
	int rear; //stores the rear index.
	unsigned int capacity; // storees the total capacity of this particular queue.
	
	//default constructor
	queue(){
		base = NULL;
		front = (int) NULL;
		rear = (int) NULL;
		capacity = (int) NULL;
	}
	
	//parameterized constructor
	queue(unsigned int cap){
		base = new int[cap];
		front = 0;
		rear = -1;
		capacity = cap;
	}
	
	bool isEmpty(){
		if(front>rear){
			return true;
		}
		return false;
	}
	
	unsigned int size(){
		return rear-front+1;
		// initailly we have 0 elements.
		// front = 0;
		// rear = -1
		// 0-1+1 = 0
	}
	bool isFull(){
		//cout<<endl<<"Size is: "<<size()<<endl;
		if(size() >= capacity){
			return true;
		}
		return false;
	}
	
	
	void enqueue(int x){
		if(isFull()){
			cout<<"The queue is already full, cannot insert new element."<<endl;
			return;
		}
		rear++;
		
		*(base+rear) = x;
	}
	
	int dequeue(){
		if(isEmpty()){
			cout<<"The queue is empty, cannot dequeue an element."<<endl;
			return (int) NULL;
		}
		int temp = *(base+front);
		front++;
		return temp;
	}
	
	
	//display method.
	void display(){
		cout<<"The elements in the queue are: "<<endl;
		if(isEmpty()){
			cout<<"The queue is empty."<<endl;
			return;
		}
		/*
		rear = 7       front =2
		 |					|
		-----------------------------
		6  89  45  65  12  45        
		-----------------------------
								   |
								*base		
		
		
		*/
		for(int i=front; i<=rear; i++){
			cout<<*(base+i)<<" <-- "; // base[i] = base[2] // base[0], base[1], base[2]
		}
		cout<<endl;
	}
};

int main(){
	queue qu(5);
	qu.enqueue(5);
	qu.enqueue(99);
	qu.enqueue(54);
	qu.enqueue(76);
	qu.enqueue(67);
	qu.display();
	qu.enqueue(100);
	cout<<qu.dequeue();
	qu.display();
	
	
	return 0;
}
