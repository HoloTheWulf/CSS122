#include <iostream>
using namespace std;


int main(){
	int a[10] = {};
	int running[10] = {};
	
	cout << "Program accepts 10 integers and prints the running sum of the array" << endl;
	
	for (int i=0; i<10; i++){
		cout << "Integer " << i+1 << ": ";
		cin >> a[i];
		running[i] = a[i] + running[i-1];
	}

	for (int i=0; i<10; i++){
		cout << a[i] << " ";
	}
	
	cout << endl;
	
	for (int i=0; i<10; i++){
		cout << running[i] << " ";
	}
}