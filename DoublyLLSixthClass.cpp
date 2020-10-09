#include <iostream>

using namespace std;

class Node{
	public:
		int data;
		Node *prev;
		Node *next;
		
		Node(){
			data = int(NULL);
			prev = NULL;
			next = NULL;
		}
		
		Node(int n){
			data = n;
			prev = NULL;
			next = NULL;
		}
};

class LinkedList{
	public:
		Node *head;
		Node *tail;
		
		LinkedList(){
			head = NULL;
			tail = NULL;
		}
		
		void display();
		void addInLast(Node *n);
		void addInFront(Node *n);
		Node *search(int num);
		void addAfter(Node *prevNode, Node *newNode);
		bool deleteNode(Node *n);
};

Node* LinkedList::search(int num){
	//body of search
	Node *tmp = head;
	if(head == NULL){
		return NULL;
	}
	while(tmp != NULL){
		if(tmp->data == num){
			return tmp;
		}
		tmp = tmp->next;
	}
	return NULL;
}

bool LinkedList::deleteNode(Node *n){
	//first case; yedi list maa jamma euta matra element cha bhane.
	if(n->next == NULL && n->prev == NULL){
		head = NULL;
		tail = NULL;
		return true;
	}
	//second case; yedi list ko first element lai delete garnu paryo bhane.
	if(n->prev == NULL){
		n = n->next;
		n->prev = NULL;
		head = n;
		return true;
	}
	//third case; yedi list ko antim element lai delete garnu cha bhane.
	if(n->next == NULL){
		n = n->prev;
		n->next = NULL;
		tail = n;
		return true;
	}
	//normal case
	n->prev->next = n->next;
	n->next->prev = n->prev;
	return true;
}

void LinkedList::addAfter(Node *prevNode, Node *newNode){
	//body of new insertAfter
	//prepare the newNode fully.
	newNode->next = prevNode->next;
	newNode->prev = prevNode;
	
	//modify the existing linked list chain with my newNode.
	prevNode->next->prev = newNode;
	prevNode->next = newNode;
}
void LinkedList::addInLast(Node *n){
	if(head == NULL){ //if the list is really empty.
		head = n;
		tail = n;
	}
	else{ //so the list already contains some element.
		n->prev = tail;
		tail->next = n;
		tail = n;		
	}
}

void LinkedList::addInFront(Node *n){
	if(head == NULL){
		head = n;
		tail =n;
	}
	else{
		n->next = head;
		head->prev = n;
		head = n;	
	}
}

void LinkedList::display(){
	Node *cur = head;
	cout<<endl<<"The elements in the list are: "<<endl;
	while(cur != NULL){
		cout<<cur->data<<"\t";
		cur = cur->next;
	}
}

int main(){
	LinkedList *list = new LinkedList();
	Node *n, *newn;
	int choice, num, num2, status;
	do{
		cout<<endl;
		cout<<"Welcome to our program"<<endl;
		cout<<"1. Insert a new Node into the Linked List."<<endl;
		cout<<"2. Display all the nodes in the Linked List."<<endl;
		cout<<"3. Add a new node into the front of the Linked List."<<endl;
		cout<<"4. Insert a new node after a certain element."<<endl;
		cout<<"5. Delete a node from the list."<<endl;
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
				list->addInLast(n);
				break;
			case 2:
				cout<<endl;
				cout<<"The elements in the lists are: "<<endl;
				list->display();
				cout<<endl;
				break;
			case 3:
				cout<<endl;
				cout<<"Enter a number to insert in the front of the List: ";
				cin>>num;
				n = new Node(num);
				list->addInFront(n);
				break;
			case 4:
				cout<<endl;
				cout<<"Enter a number after which you want to insert a new node: ";
				cin>>num;
				n = list->search(num);
				if(n == NULL){
					cout<<"Cannot find the specified node on the list."<<endl;
				}
				else if(list->tail == n){
					cout<<"Cannot add new element after tail using this method. Choose option 1."<<endl;
				}
				else{
					cout<<"Enter a new number to insert in the list: ";
					cin>>num2;
					newn = new Node(num2);
					list->addAfter(n, newn);
				}
				break;
			case 5:
				cout<<endl;
				cout<<"Enter a number you want to delete from the list: ";
				cin>>num;
				n = list->search(num);
				if(n==NULL){
					cout<<"Cannot find the node to be deleted; either the node is empty or the element doesnt exist at all."<<endl;
					break;
				}
				if(list->deleteNode(n)){
					cout<<"The node is succesfully deleted."<<endl;
				}
				else{
					cout<<"Cannot delete the node."<<endl;
				}
				
		}
	}while(choice!= 0);
	return 0;
}

