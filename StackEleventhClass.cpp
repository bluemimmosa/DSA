#include <iostream>
#include <string>

using namespace std;

class Student{
	public:
	string name;
	int rollNo;
	int standard;
	char section;
	
	Student(){
		name = "";
		rollNo = (int) NULL;
		standard = (int) NULL;
		section = (char) NULL;
	}
	
	Student(string n, int r, int s, char sec){
		name = n;
		rollNo = r;
		standard = s;
		section = sec;
	}
	void display(){
		cout<<"Name: "<<name<<" Roll No: "<<rollNo<<" Class: "<<standard<<" Section: "<<section<<endl;
	}
};

class Stack{
	public:
		Student *base;
		int top;
		int capacity;
		
		Stack(){
			base = NULL;
			top = (int) NULL;
			capacity = (int) NULL;
		}
		
		~Stack(){
			delete []base;
		}
		
		Stack(int cap){
			base = new Student[cap];
			top = -1;
			capacity = cap;
		}
		
		bool isEmpty(){
			return (top==-1?true:false);
		}
		
		bool isFull(){
			return (top == capacity-1?true:false);
		}
		
		bool push(Student* s){
			if(!isFull()){
				++top;
				*(base+top) = *s;
				return true;
			}
			return false;
		}
		
		Student* pop(){
			if(!isEmpty()){
				Student *std = (base+top);
				top--;
				return std;
			}
			return NULL;
		}
		
		Student* peek(){
			if(!isEmpty()){
				Student *std = (base+top);
				return std;
			}
			return NULL;
		}
		
		int size(){
			return top+1;
		}
		
		void displayStack(){
			Student std;
			int siz = size();
			cout<<endl;
			for(int i=0; i<siz; i++){
				std = *(base+i);
				std.display();
				cout<<endl;
			}
		}
};

int main(){
	Stack *s;
	Student *std;
	string name;
	int rollNo, standard;
	char section;
	int siz, choice, num;
	cout<<"Enter the size of the stack you want to create: "<<endl;
	cin>>siz;
	s = new Stack(siz);
	
	do{
		cout<<"Welcome to Stack management."<<endl<<endl;
		cout<<"1. Push Student to stack."<<endl;
		cout<<"2. Pop Student from stack."<<endl;
		cout<<"3. Find current occupied size of Student stack."<<endl;
		cout<<"4. Peek the Student on the stack."<<endl;
		cout<<"5. Display the Student list on stack."<<endl;
		cout<<"0. Exit the program."<<endl;
		cout<<"Enter choice: ";
		cin>>choice;
		switch(choice){
			case 1:
				cout<<endl;
				cout<<"Enter a new Student detail to push into the stack: "<<endl;
				
				cout<<"Enter Name: ";
				cin>>name;
				cout<<"Enter Roll No: ";
				cin>>rollNo;
				cout<<"Enter Class: ";
				cin>>standard;
				cout<<"Enter Section: ";
				cin>>section;
				std = new Student(name, rollNo, standard, section);
				if(s->push(std)){
					cout<<endl<<"The Student has been stored into stack."<<endl;
				}
				else{
					cout<<"The stack is full so cannot push this new Student."<<endl;
				}
				break;
			case 2:
				cout<<endl;
				std = s->pop();
				if(!std){
					cout<<"The stack is empty so cannot pop."<<endl;
				}
				else{
					cout<<"The student poped is "<<endl;
					std->display();
					cout<<endl;
				}
				break;
			case 3:
				cout<<endl;
				cout<<"The current number of students in stack is "<<s->size()<<endl;
				break;
			case 4:
				cout<<endl;
				std = s->peek();
				if(std == NULL){
					cout<<"The stack is empty so cannot peek."<<endl;
				}
				else{
					cout<<"The student peeked is "<<endl;
					std->display();
					cout<<endl;
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
