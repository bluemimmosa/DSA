#include <iostream>  
using namespace std;

class Node{
	public:
	int data;
	Node *left;
	Node *right;
	
	Node(){
		data = (int) NULL;
		left = NULL;
		right = NULL;
	}
	
	Node(int num){
		data = num;
		left = NULL;
		right = NULL;
	}
};

class Tree{
	public:
	Node *root;
	
	Tree(){
		root = NULL;
	}
	
	~Tree(){
		// call some functions to free the memory.
		// that function should delete each and every node from both left and right.
		// check if the current node is null or not? if null delete that node, otherwise
		// recursive call tho the function with both left and right turn by turn.
		destroy(root);
		
	}
	
	
	bool search(Node *n, int num){
		cout<<n->data;
		if(num == n->data){
			return true;
		}
		else if(num < n->data){
			if(n->left == NULL){
				return false; // cannot find the specified number in our tree.
			}
			else{
				cout<<" -L- ";
				return (search(n->left, num));
			}
		}
		else{
			if(n->right == NULL){
				return false; // cannot find the specified number in our tree.
			}
			else{
				cout<<" -R- ";
				return (search(n->right, num));
			}
		}
	}
	
	bool search(int num){
		if(root == NULL){
			return false;
		}
		else{
			return (search(root, num));
		}
	}
	
	void destroy(Node *n){
		if(n == NULL){
			delete n;
		}
		else{
			destroy(n->left);
			destroy(n->right);
		}
	}
		
	void insertinto(Node *n, int num){
		if(num < n->data){
			if(n->left == NULL){
				n->left = new Node(num);
			}
			else{
				insertinto(n->left, num);
			}
		}
		else{
			if(n->right == NULL){
				n->right = new Node(num);
			}
			else{
				insertinto(n->right, num);
			}
		}
	}
	
	void insert(int num){
		if(root == NULL){
			root = new Node(num);
		}
		else{
			insertinto(root, num);
		}
	}
	
	
	void print2DUtil(Node *leaf, int space)  
	{	  
    	// Base case  
    	if (leaf == NULL)  
        	return;  
  
    	// Increase distance between levels  
    	space += 5;  
  
    	// Process right child first  
    	print2DUtil(leaf->right, space);  
  
    	// Print current node after space  
    	// count  
    	cout<<endl;  
    	for (int i = 5; i < space; i++)  
        	cout<<" ";  
    	
		cout<<leaf->data<<"\n";  
  
    	// Process left child  
    	print2DUtil(leaf->left, space);  
	}  
  
// Wrapper over print2DUtil()  
void print2D()  
	{  
    	// Pass initial space count as 0  
    	print2DUtil(root, 0);  
	}  
	//copied code upto here.  
};

int main(){
	int nu;
	Tree *t = new Tree();
	t->insert(56);
	t->insert(45);
	t->insert(67);
	t->insert(23);
	t->insert(48);
	t->print2D();
	
	cout<<endl<<endl<<"Enter a number to search: ";
	cin>>nu;
	if(t->search(nu)){
		cout<<endl<<"Found.."<<endl;
	}
	else{
		cout<<endl<<"Not Found.."<<endl;
	}
	
	return 1;
}
