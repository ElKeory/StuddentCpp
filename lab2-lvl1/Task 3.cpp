#include "pch.h"
#include <iostream>
using namespace std;

int check()
{
	while (cin.fail()) {
		cout << "Invalid number, try again\n";
		cin.clear(); cin.ignore(1000, '\n');
	}
	return 0;
}

int main()
{
	cout << "Enter an expression\n";
	float a, b, ans; char z;
	while (!(cin >> a >> z >> b))
		check();
	switch (z)
	{
		case '+': ans = a + b;
			break;
		case '-': ans = a - b;
			break;
		case '/': ans = a / b;
			break;
		case '*': ans = a * b;
			break;
		default: "Error, try again\n"; main();
	}
	cout << "Answer  = " << ans;
	system("pause");
}