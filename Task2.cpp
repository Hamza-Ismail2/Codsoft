#include <iostream>
using namespace std;

int main() {
	float num1, num2;
	float result = 0.0;
	char option;
	
	cout << "Enter the first number: ";
	cin >> num1;
	cout << "Enter the second number: ";
	cin >> num2;
	cout << "Choose the operator among these(+,-,*,/) that you would like: " << endl;
	cin >> option;
	
	switch(option) {
		
		case '+':
			
			result = num1 + num2;
			break;
			
		case '-':
			
			result = num1 - num2;
			break;
		
		case '*':

			result = num1 * num2;
			break;
			
		case '/':
			
			result = num1 / num2;
			break;
			
		default:
			
			cout << "Wrong operator selcted" << endl;
			exit(1);
	}
	
	cout << "Result of the operation " << num1 << " " << option << " " << num2 << " is: "<< result << endl;
}