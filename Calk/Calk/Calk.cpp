#include "pch.h"
#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	cout << "Hello, my dear. What are the numbers?\n";
	double a, b, s;
	cin >> a >> b;
	cout << "Number 1: " << a << "\nNumber 2: " << b << endl;
	{
		cout << "What do you want to do?\n" << "1. +\n" << "2. -\n" << "3. *\n" << "4. /\n" << "5.^2\n" << "6.sqrt\n" << "7.log\n";
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
			  s = log10(a) / log10(o);
			  break;
		  default:
			  cout << "Please, enter a valid number\n";
			  break;
		}
	}
	cout << "Result = " << s << endl;
	cout << "Do you want to try again? y or n" << endl;
}
