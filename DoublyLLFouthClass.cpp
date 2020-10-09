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
};

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
	Node *n1 = new Node(10);
	Node *n2 = new Node(20);
	Node *n3 = new Node(40);
	Node *n4 = new Node(80);
	Node *n5 = new Node(100);
	list->addInLast(n1); // 100 -> 80 -> 10 -> 20 -> 40
	list->addInLast(n2);
	list->addInLast(n3);
	list->addInFront(n4);
	list->addInFront(n5);
	
	list->display();
	delete n1;
	delete n2;
	delete n3;
	delete n4;
	delete n5;
	delete list;
	
	return 0;
}

