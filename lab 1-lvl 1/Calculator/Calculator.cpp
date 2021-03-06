#include "pch.h"
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
	while (!(cin >> a))
		check();
	while (!(cin >> b))
		check();
	cout << "Number 1 = " << a << '\n' << "Number 2 = " << b << '\n';
	cout << "What do you want to do?\n 1. +\n 2. -\n 3. *\n 4. /\n 5.^2\n 6.sqrt\n 7.log\n";
	int c;
	while (!(cin >> c))
		check();
	if (c < 1 || c>7) {
		while (c < 1 || c>7) { cout << "Enter numbers from 1 to 7.\n"; check(); cin >> c; }
	}
	cout << "Your answer: " << c << '\n';
	double s;
	switch (c) {
	case 1: s = a + b;
		break;
	case 2: s = a - b;
		break;
	case 3: s = a * b;
		break;
	case 4: if (b != 0)  s = a / b; 
			else { cout << "Number 2 must must not be equal to 0, please try again\n Enter two new numbers.\n"; main(); }
		break;
	case 5: s = pow(a, 2);
		break;
	case 6: if (a > 0) s = sqrt(a); 
			else { cout << "Number 1 must be greater then 0, please try again\n Enter new number.\n"; main(); }
		break;
	case 7: if (a <= 0 || b==1 || b <= 0) { 
		cout << "Number 1 must be greater than 0 and Number 2 must be greater than 0 and not equal to 1. Please try again.\n";
		main();
	} else s = log10(a) / log10(b);
		break;
	}
	cout << "Result = " << s << '\n' << "Do you want to try again? 'y or n'\n";
	char z;
	cin >> z;
	while (z != 'y' && z != 'n')
	{
		cout << "Please enter 'y or n'\n";
		cin >> z; cin.ignore(1000, '\n');
	}
	if (z == 'y' || z == 'n') {
		if (z == 'y') main();
		else if (z == 'n') system("pause");
	}	
}