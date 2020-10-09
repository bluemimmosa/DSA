#include <iostream>

using namespace std;

class Node{
	public:
		int data;
		Node *next;
		
		Node(){
			data = (int)NULL;
			next = NULL;
		}
		
		Node(int n){
			data = n;
			next = NULL;
		}
};

class CircularLinkedList{
	public:
		Node *last;
		
		CircularLinkedList(){
			last = NULL;
		}
		
		void addNode(Node *n){
			if(last == NULL){ //the list is empty.
				n->next = n;
				last = n;
				return;
			}
			n->next = last->next;
			last->next = n;
			last = n;
		}
		
		void display(){
			if(last == NULL){
				cout<<endl;
				cout<<"List is Empty."<<endl;
				return;
			}
			Node *cur = last->next;// cur points to the first element.
			while(cur != last){
				cout<<cur->data<<"\t";
				cur =cur->next;
			}
			cout<<cur->data<<endl;
		}
		
		Node* search(int n){
			Node *cur;
			if(last == NULL){
				return NULL;
			}
			cur = last->next;
			while(cur!= last){
				if(cur->data == n){
					return cur;
				}
				cur = cur->next;
			}
			if(cur->data == n){
				return cur;
			}
			return NULL;
		}
		
		void addinMiddle(Node *f, Node *n){
			n->next = f->next;
			f->next = n;
		}
		
		void addinFront(Node *n){
			if(last == NULL){ //the list is empty.
				n->next = n;
				last = n;
				return;
			}
			n->next = last->next;
			last->next = n;
		}
		
		void deleteNode(Node *n){
			Node *cur, *prevCur;
			cur = last->next;
			prevCur = last; 
			while(cur != last){
				if(cur->data == n->data){
					//now delete the node.
					prevCur->next = cur->next;
					return;
				}
				prevCur = cur;
				cur = cur->next;
			}
			//when the element you want to delete is in the last of the circula list.
			if(cur->data == n->data){
				//now delete the node.
				cout<<endl<<"deleting...."<<endl;
				prevCur->next = cur->next;
				last = prevCur;
				if(cur == prevCur){
					last = NULL;
				}
			}	
		}
};

int main(){
	CircularLinkedList *clist = new CircularLinkedList();
	Node *n, *found;
	int choice, num, num2, status;
	do{
		cout<<endl;
		cout<<"Welcome to our program"<<endl;
		cout<<"1. Insert a new Node into the Linked List."<<endl;
		cout<<"2. Insert new node into the begining of the List. "<<endl;
		cout<<"3. Display all the nodes in the Linked List."<<endl;
		cout<<"4. Add in the middle of list. "<<endl;
		cout<<"5. Delete a node from the circularly linked list. "<<endl;
		cout<<"0. Exit. "<<endl;
		cout<<endl;
		cout<<"Enter Your choice: ";
		cin>>choice;
		switch(choice){
			case 1:
				cout<<endl;
				cout<<"Enter a number to insert in the list: ";
				cin>>num;
				n = new Node(num);
				clist->addNode(n);
				break;
			case 2:
				cout<<endl;
				cout<<"Enter a number to insert in the list: ";
				cin>>num;
				n = new Node(num);
				clist->addinFront(n);	
				break;
			case 3:
				cout<<endl;
				cout<<"The elements in the lists are: "<<endl;
				clist->display();
				cout<<endl;
				break;
			case 4:
				cout<<endl;
				cout<<"Enter a number after which you want to add a new element: ";
				cin>>num;
				found = clist->search(num);
				if(found == NULL){
					cout<<"Either the list is empty or the Node doenst exists. "<<endl;
					break;
				}
				cout<<"Enter a new number: ";
				cin>>num;
				n = new Node(num);
				clist->addinMiddle(found, n);
				break;
			case 5:
				cout<<endl;
				cout<<"Enter a number you want to delete: ";
				cin>>num;
				found = clist->search(num);
				if(found == NULL){
					cout<<endl<<"The element you want to remove either doesnt exists at all or the list is empty. "<<endl;
					break;
				}
				clist->deleteNode(found);
			}
		}while(choice != 0);
	
	return 0;
}
