#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	//variable declaration
	int x;
	cout << "Enter a number: ";
	cin >> x;
	switch (x) {
	case 1:
		cout << "You typed 1.\n"; break;
	case 2:
		cout << "You typed 2.\n"; break;
	default:
		cout << "You did not type 1 or 2.\n"; break;
	}
	
}