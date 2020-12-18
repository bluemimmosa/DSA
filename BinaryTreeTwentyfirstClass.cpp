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
	
	
	Node* search(Node *n, int num){
		cout<<n->data;
		if(num == n->data){
			return n;
		}
		else if(num < n->data){
			if(n->left == NULL){
				return NULL; // cannot find the specified number in our tree.
			}
			else{
				cout<<" -L- ";
				return (search(n->left, num));
			}
		}
		else{
			if(n->right == NULL){
				return NULL; // cannot find the specified number in our tree.
			}
			else{
				cout<<" -R- ";
				return (search(n->right, num));
			}
		}
	}
	
	Node* search(int num){
		if(root == NULL){
			return NULL;
		}
		else{
			return (search(root, num));
		}
	}
	
	void destroy(Node *n){
		if(n == NULL){
			return;
		}
		if(n->left != NULL){
			destroy(n->left);
		}
		if(n->right != NULL){
			destroy(n->right);
		}
		cout << "Deleting node: " << n->data << endl;
		
		n->left = NULL;
		n->right = NULL;
		n = NULL;
		delete n;
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
	char answer = 'N';
	int choice, number;
	Node *se;
	Tree *t = new Tree();
	do{
		cout<<"Tree Program"<<endl;
		cout<<"============"<<endl;
		cout<<"1. Insert an element to the TREE."<<endl;
		cout<<"2. Search an element in a TREE."<<endl;
		cout<<"3. Delete the structure after a particular node in a TREE."<<endl;
		cout<<"4. Print the TREE."<<endl;
		cout<<"5. Exit"<<endl<<endl;
		cout<<"Enter your Choice (1-5): ";
		cin>>choice;
		cout<<endl;
	
	
		switch(choice){
			case 1:
				cout<<"Enter a number to insert in the TREE: "<<endl;
				cin>>number;
				t->insert(number);
				break;
			case 2:
				cout<<"Enter a number to search in the TREE: "<<endl;
				cin>>number;
				se = t->search(number);
				if(se){
					cout<<endl<<"Found.."<<endl;
					cout<<se->data<<endl;
					t->print2D();
				}
				else{
					cout<<endl<<"Not Found.."<<endl;
				}
				break;
			case 3:
				cout<<"Enter a number whose following structure you want to erase: "<<endl;
				cin>>number;
				se = t->search(number);
				if(se){
					cout<<endl<<"Found.."<<endl;
					cout<<se->data<<endl;
					cout<<"Are you sure you want to delete(Y/N): ";
					cin>>answer;
					if(answer == 'Y' || answer == 'y'){
						t->destroy(se);
						cout<<endl<<"The structure after that particular node has been erased."<<endl;
					}
				}
				else{
					cout<<endl<<"Not Found.."<<endl;
				}
				break;
			case 4:
				cout<<endl;
				t->print2D();
				break;
			case 5:
				break;
			default:
				cout<<endl<<"Enter valid option.."<<endl;
		}
	}while(choice != 5);
	return 1;
}
	
