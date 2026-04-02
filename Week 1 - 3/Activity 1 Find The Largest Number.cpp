#include <iostream>
using namespace std;

int main(){
	cout << "Program takes in 10 integers and prints the largest number" << endl;
	
	int a[10] = {};
	int largest = 0;
	
	for (int i = 0; i < 10; i++){
		cin >> a[i];
		if (a[i] > largest){
			largest = a[i];
		}
	}
	cout << endl;
	cout << "Largest number is: " << largest;
	
}

