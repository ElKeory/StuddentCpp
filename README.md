Test1
#include "stdafx.h"
#include <iostream>
#include <cmath>
using namespace std;

int check()
{	
	while (cin.fail()) {
		cout << "Invalid number, please, try again,\n Number : ";
		cin.clear(); cin.ignore(1000, '\n');
	}
	return 0;
}

int main()
{	
	cout << "Hello, my dear. What are the numbers?\n";
	double a, b;
	while (!(cin >> a)) check();
	while (!(cin >> b)) check();
	cout << "Number 1 = " << a << endl << "Number 2 = " << b << endl;
	cout << "What do you want to do?\n 1. +\n 2. -\n 3. *\n 4. /\n 5.^2\n 6.sqrt\n 7.log\n";
	int c;
	while (!(cin >> c))
		if (c < 1 || c>7) {
			cout << "Invalid number, please, try again,\n Number : ";
		}
		check();
	cout << "asdas\n" << c;
	system("pause");
}
