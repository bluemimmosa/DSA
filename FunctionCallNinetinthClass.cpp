#include <iostream>

using namespace std;

int div(int x, int y){
	int temp;
	try{
		if(y==0){
			throw y;
		}
		temp = x/y;
	}catch(int z){
		cout<<"Cannot divide by 0";
	}
	return temp;
}

int main(){
	
	int a, b, res;
	cout<<"Enter value of a: ";
	cin>>a;
	cout<<"Enter value of b: ";
	cin>>b;
	
	res = div(a,b);
	cout<<endl<<"Result is "<<res<<endl;
	
	
	return 1;
}
