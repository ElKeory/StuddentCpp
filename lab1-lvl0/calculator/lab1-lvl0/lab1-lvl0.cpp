#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
	char z;
	do {
		cout << "Hello, my dear. What are the numbers?\n";
		double a = 0, b = 0, s = 0;
		cin >> a >> b;
		cout << "Number 1: " << a << "\nNumber 2: " << b << endl;
		{
			cout << "What do you want to do?\n 1. +\n 2. -\n 3. *\n 4. /\n 5.^2\n 6.sqrt\n 7.log\n";
			int c = 0;
			cin >> c;
			cout << "Your answer: " << c << endl;
			switch (c) {
			case 1:
				s = a + b;
				break;
			case 2:
				s = a - b;
				break;
			case 3:
				s = a * b;
				break;
			case 4:
				s = a / b;
				break;
			default:
				cout << "Please, enter a valid number\n";
				break;
			}
		}
		cout << "Result = " << s << endl;
		cout << "Do you want to try again? 'y or n'\n";
		cin >> z;
		while (z != 'y' && z != 'n') {
			cout << "Please enter 'y or n'\n";
			cin >> z;
		}
	} while (z == 'y');
}