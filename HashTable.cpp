#include <iostream>
#define MAX 100

using namespace std;

class Node{
	public:
	int key;
	int data;
	
	Node(){
		key = -2;
		data = (int) NULL;
	}
	
	Node(int k, int d){
		key = k;
		data = d;
	}
};

class HashTable{
	public:
	int size;
	Node hashArray[MAX];
	
	HashTable(){
		size = 0;
	}
	
	HashTable(int s){
		if(s > 100){
			cout<<"Error creating hash table limit size to 100."<<endl;
		}
		else{
			size = s;
		}
		
		for(int i=0; i<size; i++){
			hashArray[i].key = -2; //this line guarantees, that all the hashArray[] is
			//filled with -1 prior to usage.
		}
	}
	
	int hashIndex(int key){
		
		return key%size;
	}
	
	void insert(Node *n){
		int hI = hashIndex(n->key);
		while((hashArray[hI].key != -1) && (hashArray[hI].key != -2)){
			hI++;  //linear probing
			hI = hI%size; //wrap around.
		}
		
		hashArray[hI] = *n;
	}
	
	//write display routine here
	void display(){
		for(int i=0; i <size; i++){
			if(hashArray[i].key != -1 && hashArray[i].key != -2){
				cout<<i<<"\t"<<hashArray[i].key<<"\t"<<hashArray[i].data<<endl;
			}
		}
	}
	
	bool del(Node *n){
		int hI = hashIndex(n->key);
		while(hashArray[hI].key != -2){
			if(hashArray[hI].key == n->key){
				hashArray[hI].key = -1;
				hashArray[hI].data = (int) NULL;
			}
			hI++;
			hI = hI%size;
		}
	}
	
	Node *search(int k){
		int hI = hashIndex(k); //calculate hashindex based on the key provided.
		while(hashArray[hI].key != -1 || hashArray[hI].key != -2){ // loop until the hasharray is empty.
			if(hashArray[hI].key == k){ //check if the key mathes.
				return &hashArray[hI]; //return the data if matches.
			}
			hI++; //linear probing
			hI = hI%size; // wrap around.
		}
		return NULL; //if not found a trace, return NULL.
	}
};

int main(){
	HashTable *h = new HashTable(20);
	Node *n = new Node(2, 20);
	h->insert(n);
	n=new Node(22, 120);
	h->insert(n);
	n = new Node(5, 38);
	h->insert(n);
	n = new Node(22, 99);
	h->insert(n);
	n = new Node(25, 109);
	h->insert(n);
	h->display();
	Node *found = h->search(2);
	if(found){
		cout<<"found"<<endl<<found->key<<"\t"<<found->data<<endl;
	}
	else{
		cout<<"Not found."<<endl;
	}
	h->display();
	
	if(h->del(found)){
		cout<<"Delete Successful."<<endl;
	}
	else{
		cout<<"Cannot Delete."<<endl;
	}
	h->display();
	
	found = h->search(22);
	if(found){
		cout<<"found"<<endl<<found->key<<"\t"<<found->data<<endl;
	}
	else{
		cout<<"Not found."<<endl;
	}
	h->display();
	return 1;
}
