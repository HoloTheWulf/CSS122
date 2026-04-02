#include <iostream>
using namespace std;

int main(){
	int a[15] = {};
	int even = 0;
	int odd = 0;
	
	cout << "Inputs 15 numbers, then shows the number of even and odd numbers in the array" << endl;
	
	for (int i = 0; i < 15; i++){
		cout << "Integer Number " << i+1 << ": "; 
		cin >> a[i];
		if (a[i] % 2 == 0 ){
			even += 1;
		}else{
			odd += 1;
		}
	}
	cout << endl;
	cout << "Even numbers: " << even << endl;
	cout << "Odd numbers: " << odd << endl;
}