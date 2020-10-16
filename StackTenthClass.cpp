#include <iostream>

using namespace std;

//let us assume that we will deal with the numbers in this stack.
class Stack{
	public:
	int *base;
	int top; //0,1,2,3,4,5,6,7,8,9
	int capacity; // 10
	
	Stack(){
		base = NULL;
		top = (int) NULL;
		capacity = (int) NULL;
	}
	
	Stack(int size){
		base = new int[size];
		top = -1; // base = 0x7890; base+top = top of the stack;
		//stack is empty; base+top = 0x7890-1 = out of memory range of the stack.
		// base = 0x7890 , top++; top=0; base+top = 0x7890+0 = which is a valid address.
		capacity = size;
	}
	
	~Stack(){
		delete []base;
	}
	
	bool isFull(){
		if(capacity == (top+1))
			return true;
		else
			return false;
	}
	
	int size(){
		return top+1;
	}
	
	int peek(){
		if(!isEmpty()){
			return *(base+top);
		}
		return (int)NULL;
	}
	
	bool isEmpty(){
		if(top == -1)
			return true;
		else
			return false;
	}
	
	bool push(int num){
		if(!isFull()){
			++top;
			*(base+top) = num;
			return true;
		}
		return false; // if false is returned we know the list is full.
	}
	
	int pop(){
		if(!isEmpty()){
			int temp = *(base+top);
			top--;
			return temp;
		}
		return (int)NULL;
	}
	
	void displayStack(){
		int elements = top;
		cout<<"The stack contains.. "<<endl<<endl;
		while(elements != -1){
			cout<<"| "<< *(base+elements)<<" |"<<endl;
			elements--;
		}
	}
	
};

int main(){
	Stack *s;
	int siz, choice, num;
	cout<<"Enter the size of the stack you want to create: "<<endl;
	cin>>siz;
	s = new Stack(siz);
	
	do{
		cout<<"Welcome to Stack management."<<endl<<endl;
		cout<<"1. Push element to stack."<<endl;
		cout<<"2. Pop element from stack."<<endl;
		cout<<"3. Find current occupied size of stack."<<endl;
		cout<<"4. Peek the element on the stack."<<endl;
		cout<<"5. Display the stack."<<endl;
		cout<<"0. Exit the program."<<endl;
		cout<<"Enter choice: ";
		cin>>choice;
		switch(choice){
			case 1:
				cout<<endl;
				cout<<"Enter a number to push into the stack: ";
				cin>>num;
				if(s->push(num)){
					cout<<endl<<"The number has been stored into stack."<<endl;
				}
				else{
					cout<<"The stack is full so cannot push this new number."<<endl;
				}
				break;
			case 2:
				cout<<endl;
				num = s->pop();
				if(num == (int)NULL){
					cout<<"The stack is empty so cannot pop."<<endl;
				}
				else{
					cout<<"The element poped is "<<num<<endl;
				}
				break;
			case 3:
				cout<<endl;
				cout<<"The current number of elements in stack is "<<s->size()<<endl;
				break;
			case 4:
				cout<<endl;
				num = s->peek();
				if(num == (int)NULL){
					cout<<"The stack is empty so cannot peek."<<endl;
				}
				else{
					cout<<"The element peeked is "<<num<<endl;
				}
				break;
			case 5:
				cout<<endl;
				s->displayStack();
		}
	}while(choice != 0);
	delete s;
	return 0;
}
