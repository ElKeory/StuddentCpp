#include "pch.h"
#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	char z;
	do {
		cout << "Hello, my dear. What are the numbers?\n";
		double a = 0, b = 0, s = 0;
	error1:
		cin >> a;
		while (cin.fail()) {
			cout << "Invalid number 1, please, try again,\n Number 1: ";
			cin.clear(); cin.ignore(1000, '\n');
			cin >> a;
		}
		cin >> b;
		while (cin.fail()) {
			cout << "Invalid number 2, please, try again,\n Number 2: ";
			cin.clear(); cin.ignore(1000, '\n');
			cin >> b;
		}
		cout << "Number 1: " << a << "\nNumber 2: " << b << endl;
		{
		error2:
			cout << "What do you want to do?\n 1. +\n 2. -\n 3. *\n 4. /\n 5.^2\n 6.sqrt\n 7.log\n";
			int c = 0;
			cin >> c;
			while (cin.fail()) {
				cout << "Invalid number, please, try again,\n";
				cin.clear(); cin.ignore(1000, '\n');
				cin >> c;
			}
			if (c > 0 && c < 8) {
				cout << "Your answer: " << c << endl;
				switch (c) {
				case 1: s = a + b;
					break;
				case 2: s = a - b;
					break;
				case 3: s = a * b;
					break;
				case 4: if (b != 0) { s = a / b; }
						else { cout << "Number 2 must must not be equal to 0, please try again\n Enter two new numbers.\n"; goto error1; }
						break;
				case 5: s = pow(a, 2);
					break;
				case 6: if (a > 0) { s = sqrt(a); }
						else { cout << "Number 1 must be greater then 0, please try again\n Enter two new numbers.\n"; goto error1; }
						break;
				case 7:
				error3:
					cout << "Enter the base of the logarithm\n";
					int o;
					cin >> o;
					while (cin.fail()) {
						cout << "Invalid base of the logarithm, please, try again,\n";
						cin.clear(); cin.ignore(1000, '\n');
						cin >> o;
					}
					if (o > 0 && o != 1 && a > 0) { s = log10(a) / log10(o); }
					else {
						if (o < 0 || o == 1) {
							cout << "The base of logarithm must be greater than 0 and not equal to 1,please try again\n"; goto error3;
						}if (a < 0) {
							cout << "Number 1 must be greater than 0, please try again\n"; goto error1;
						}
					}
					break;
				}
			}
			else { cout << "Please, enter a valid number\n"; goto error2; }
		}
		cout << "Result = " << s << endl; cout << "Do you want to try again? 'y or n'\n";
		cin >> z;
		while (z != 'y' && z != 'n') {
			cout << "Please enter 'y or n'\n";
			cin >> z;
		}
	} while (z == 'y');
}