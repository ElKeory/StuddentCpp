#include "pch.h"
#include <iostream>
#include <math.h>
using namespace std;

int main()
{
 char y;
 do{
	cout << "Hello, my dear. What are the numbers?\n";
	double a, b, s;
	cin >> a >> b;
	cout << "Number 1: " << a << "\nNumber 2: " << b << endl;
	{
		cout << "What do you want to do?\n 1. +\n 2. -\n 3. *\n 4. /\n 5.^2\n 6.sqrt\n 7.log\n";
		int c;
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
				s = a * a;
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
							bool c = true;
						}
						else {
							cout << "Number 'a' > 0\n";
							c = false;
						}
					}
					else {
						cout << "The base of the logarithm must not be equal to 1\n";
					}
				}
				else {
					cout << "The base of logarithm > 1\n";
				}
				break;
			default:
				cout << "Please, enter a valid number\n";
				break;
		}
		if (c == true) {
			cout << "Result = " << s << endl;
		}
		else;
	}
		cout << "Do you want to try again? y or n\n";
 } while (cin >> y);
}