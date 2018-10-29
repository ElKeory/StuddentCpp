#include "pch.h"
#include <iostream>
#include <cmath> 
using namespace std;
double check_A(double a)
{   
	cout << "Enter a first number.\n";
	cin >> a;
	while (cin.fail()) {
		cout << "Invalid number 1, please, try again.\nNumber 1: ";
		cin.clear(); cin.ignore(1000, '\n');
		cin >> a;
	}
	return a;
}
double check_B(double b)
{
	cout << "Enter a second number.\n";
	cin >> b;
	while (cin.fail()) {
		cout << "Invalid number 2, please, try again.\nNumber 2: ";
		cin.clear(); cin.ignore(1000, '\n');
		cin >> b;
	}
	return b;
}
double math_operation_check(int c, double a, double b)
{
	cout << "Number 1 = " << a << endl << "Number 2 = " << b << endl;
	cout << "What do you want to do?\n 1. +\n 2. -\n 3. *\n 4. /\n 5.^2\n 6.sqrt\n 7.log\n";
	cin >> c;	
	while (cin.fail()) {
		cout << "Invalid number, please, try again,\n";
		cin.clear(); cin.ignore(1000, '\n');
		cin >> c;
	}if (c > 0 && c < 8) {
		cout << "Your answer: " << c << endl;
	}
	return c;
}
double base_of_logarithm(double o)
{
	cout << "Enter the base of the logarithm.\n";
	cin >> o;
	while (cin.fail() && (o <= 0 || o == 1)) {
		cout << "Invalid base of the logarithm, please try again.\n";
		cin.clear(); cin.ignore(1000, '\n');
		cin >> o;
	}
	/*while (o <= 0 || o == 1) {
		if (o <=0 || o == 1) {
			cout << "The base of logarithm must be greater than 0 and not equal to 1, please try again.\n";
			o = base_of_logarithm(o);
		}
	}*/
	return o;
}
double result(double s, double a, double b, double o, int c)
{
	switch (c) {
	case 1: s = a + b;
		break;
	case 2: s = a - b;
		break;
	case 3: s = a * b;
		break;
	case 4: while (s == 0) {
		if (b != 0) { s = a / b; }
		else {
			cout << "Number 2 must must not be equal to 0, please try again.\nEnter new number.\n";
			s = 0;
			b = check_B(b);
		}
	}
		break;
	case 5: s = pow(a, 2);
		break;
	case 6: while (s == 0) {
		if (a > 0) { s = sqrt(a); }
		else {
			cout << "Number 1 must be greater then 0, please try again.\nEnter new number.\n";
			s = 0;
			a = check_A(a);
		}
	}
		break;
	case 7: 
		o = base_of_logarithm(o);
		while (s == 0) {
		if (a <= 0) {
			cout << "Number 1 must be greater than 0.\nEnter new number.\n";
			a = check_A(a);
		}
		else {			
			s = log10(a) / log10(o);
		}
	}
		break;		
	}	
	return s;
}
int main(double s, double a, double b, double o, int c)
{
	cout << "Hello, my dear. What are the numbers?\n";	
	a = check_A(a);
	b = check_B(b);
	c = math_operation_check(c, a, b);
	//o = base_of_logarithm(o);
	s = result(s, a, b, c, o);	
	cout << "Result " << s << endl;
	system("pause");
	return 0;	
}