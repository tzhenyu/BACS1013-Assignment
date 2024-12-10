#include <iostream>

using namespace std; 

int main(){
	int temperature_count = 1;
	double celsius, fahrenheit;

	do { 
		cin >> fahrenheit;
		celsius = ((fahrenheit - 32) * 5) / 9;
		cout << celsius << endl;
		temperature_count++;

	} while (temperature_count <= 15);

	cout << "All temp processed";
	return 0;
}