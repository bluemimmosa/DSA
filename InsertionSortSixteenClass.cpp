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
			//
			//1, 9, 19, 21
			
			while(tmp != NULL){
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
		
		void insertionSort(){
			Node *cur, *nextCur, *temp;
			temp = new Node();
			nextCur = head->next;
			
			int i = 0;
			while(nextCur != NULL){ // 1, 5, 2, 3(i) nextCur
				cur = head;
				cout<<endl<<endl;
				cout<<"nextCur: "<<nextCur->data<<endl;
				for(int j=0; j<=i; j++){
					
					
					cout<<"i value: "<<i<<endl;
					cout<<"cur: "<<cur->data<<endl;
					cout<<"j value: "<<j<<endl<<endl;
					if(nextCur->data < cur->data){
						temp->data = nextCur->data;
						nextCur->data = cur->data;
						cur->data = temp->data;
					}
					cur = cur->next;
				}
				i++;
				nextCur = nextCur->next;
				
				this->display();
				cout<<endl;
			}
			
		}
		
		int remove(int num){
			Node *tmp = head;
			Node *prev;
			//to delete the first node.
			if(tmp->data == num){
				head = tmp->next;
				return 1;
			}
			
			//to delete the item in the middle.
			while(tmp->next != NULL){
				if(tmp->data == num){
					prev->next = tmp->next;
					return 1;
				}
				prev = tmp;				
				tmp = tmp->next;
			}
			
			//to delete the item in the last.
			if(tmp->data == num && tmp->next == NULL){
				prev->next = NULL;
				return 1;
			}
			return -1;	
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
	int choice, num, status;
	do{
		cout<<endl;
		cout<<"Welcome to our program"<<endl;
		cout<<"1. Insert a new Node into the Linked List."<<endl;
		cout<<"2. Display all the nodes in the Linked List."<<endl;
		cout<<"3. Add a new node into the front of the Linked List."<<endl;
		cout<<"4. Add a new node into the middle of the Linked List. "<<endl;
		cout<<"5. Delete a node from the Linked List."<<endl;
		cout<<"6. Insertion sort."<<endl;
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
				break;
			case 5:
				cout<<endl;
				cout<<"Enter a number to delete from the list: ";
				cin>>num;
				n = list.search(num);
				if(n == NULL){
					cout<<"The element doesn't exist on the List."<<endl;
					break;
				}
				else{
					status = list.remove(num);
					if(status == 1){
						cout<<"Node successfully removed."<<endl;
						list.display();
						}
					else
						cout<<"Cannot remove Node."<<endl;
				}
				break;
			case 6:
				cout<<endl;
				cout<<"Before Sort: "<<endl;
				list.display();
				list.insertionSort();
				cout<<endl<<"After Sort:"<<endl;
				list.display();
		}
	}while(choice!= 0);
	
	
	return 0;
}
