#include "pch.h"
#include <iostream>
using namespace std;

int check()
{
	while (cin.fail())
	{
		cout << "Error, try again\n";
		cin.clear(); cin.ignore(1000, '\n');
		return 0;
	}
	return 1;
}

int main()
{
	cout << "Enter an expression\n";
	float a, b, ans; char z;
	while (!(cin >> a >> z >> b))
		check();
	switch (z)
	{
	case '+': cout << a + b;
		break;
	case '-': cout << a - b;
		break;
	case '/': cout << a / b;
		break;
	case '*': cout << a * b;
		break;
	default: "Error, try again\n"; main();
	}
	return 0;
	system("pause");
}