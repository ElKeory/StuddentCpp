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
			case 5:
				s = pow(a, 2);
				break;
			case 6:
				s = sqrt(a);
				break;
			case 7:
				cout << "Enter the base of the logarithm\n";
				int o;
				cin >> o;
				if (o > 0) {
					if (o != 1) {
						if (a > 0) {
							s = log10(a) / log10(o);
						}
						else {
							cout << "Number 'a' must be > 0\n";
						}
					}
					else {
						cout << "The base of the logarithm must not be equal to 1\n";
					}
				}
				else {
					cout << "The base of logarithm must be > 1\n";
				}
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