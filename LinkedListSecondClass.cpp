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
		
		Node *search(int value){
			Node *tmp = head;
			if(head == NULL){
				return NULL;
			}
			
			while(tmp->next != NULL){
				if(tmp->data == value){
					return tmp;
				}
				tmp = tmp->next;
			}
			return NULL;
		}
		
		void insertAtFront(Node * n){
			if(head == NULL){
				head = n;
			}
			else{
				n->next = head;
				head = n;
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
	Node *n, *n2;
	int choice, num;
	do{
		cout<<endl;
		cout<<"Welcome to our program"<<endl;
		cout<<"1. Insert a new Node into the Linked List."<<endl;
		cout<<"2. Display all the nodes in the Linked List."<<endl;
		cout<<"3. Add a new node into the front of the Linked List."<<endl;
		cout<<"4. Add a new node into the middle of the Linked List. "<<endl;
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
				break;
			case 3:
				cout<<endl;
				cout<<"Enter a number to insert in the front of the List: ";
				cin>>num;
				n = new Node(num);
				list.insertAtFront(n);
				break;
			case 4:
				cout<<endl;
				cout<<"Enter a number after which you want to insert a new node: ";
				cin>>num;
				n = list.search(num);
				if(n == NULL){
					cout<<"The element doesnt exist on the List."<<endl;
					break;
				}
				else{
					cout<<"Enter a number to create a new node: ";
					cin>>num;
					n2 = new Node(num);
					n2->next = n->next;
					n->next = n2;
					cout<<"Insertion of new node successful after "<<n->data<<endl;
				}
		}
	}while(choice!= 0);
	
	
	return 0;
}
