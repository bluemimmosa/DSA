#include <iostream>

using namespace std;

class Node{
	public:
		int data;
		Node *next;
		
		Node(){
			data = 0;
			next = NULL;
		}
		
		Node(int x){
			data = x;
			next = NULL;
		}
};

class LinkedList{
	public: 
		Node *head;
		
		LinkedList(){
			head = new Node();
			head = NULL;
		}
		void insert(Node* x){
			//is this the firt element?
			if(head == NULL){
				head = x;
			}
			else{
				Node *tmp = head;
				while(tmp->next != NULL){
					tmp = tmp->next;
				}
				tmp->next = x;
			}
		}
		
		void display(){
			if(head != NULL){
				Node *tmp = head;
				while(tmp->next != NULL){
					cout<<tmp->data<<"\t";
					tmp = tmp->next;
				}
				cout<<tmp->data;
			}
		}
};

int main(){
	
	LinkedList list;
	Node *n;
	int choice, num;
	do{
		cout<<endl;
		cout<<"Welcome to our program"<<endl;
		cout<<"1. Insert a new Node into the Linked List."<<endl;
		cout<<"2. Display all the nodes in the Linked List."<<endl;
		cout<<"0. Exit the Program."<<endl;
		cout<<endl;
		cout<<"Enter Your choice: ";
		cin>>choice;
		switch(choice){
			case 1:
				cout<<endl;
				cout<<"Enter a number to insert in the list: ";
				cin>>num;
				n = new Node(num);
				list.insert(n);
				break;
			case 2:
				cout<<endl;
				cout<<"The elements in the lists are: "<<endl;
				list.display();
				cout<<endl;
		}
	}while(choice!= 0);
	
	
	return 0;
}
