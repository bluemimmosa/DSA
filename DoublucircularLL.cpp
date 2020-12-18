#include <iostream>

using namespace std;

class Node{
	public:
	int data;
	Node *prev;
	Node *next;
	
	Node(){
		data = (int) NULL;
		prev = NULL;
		next = NULL;
	}
	
	Node(int n){
		data = n;
		prev = NULL;
		next = NULL;
	}
};


class CircularLL{
	public:
	Node *last;
	
	CircularLL(){
		last = NULL;
	}
	
	void addNode(Node *n){
		//check if the list is empty?
		if(last == NULL){
			n->next = n;
			n->prev = n;
			last = n;
			return;
		}
		//if the list has elements..
		//1. point n->prev = last.
		//2. point n->next = last->next.
		//3. point last->next = n.
		//4. last = n;
		
		//preparation on new node.
		n->prev = last; // ahile ko last.
		n->next = last->next; //first element.
		
		// update of existing pointers.
		last->next->prev = n;
		last->next = n; // now change last->next to point to n.
		last = n;
	}
	
	void displayforward(){
		if(last == NULL){
			cout<<endl;
			cout<<"List is Empty."<<endl;
			return;
		}
		
		Node *cur = last->next;
		while(cur != last){
			cout<<cur->data<<"\t";
			cur =cur->next;
		}
		cout<<cur->data<<endl;
			
	}
	
	void displaybackward(){
		if(last == NULL){
			cout<<endl;
			cout<<"List is Empty."<<endl;
			return;
		}
		
		Node *cur = last;
		while(cur != last->next){
			cout<<cur->data<<"\t";
			cur =cur->prev;
		}
		cout<<cur->data<<endl;
			
	}
};

int main(){
	
	CircularLL *linkedlist = new CircularLL();
	
	
	linkedlist->addNode(new Node(10));
	linkedlist->addNode(new Node(20));
	linkedlist->addNode(new Node(30));
	linkedlist->addNode(new Node(40));
	
	linkedlist->displayforward();
	linkedlist->displaybackward();
}


