#include "pch.h"
#include <iostream>
using namespace std;
int check()
{
	while (cin.fail()) {
		cout << "Invalid number, please, try again,\n Number : ";
		cin.clear(); cin.ignore(1000, '\n');
	}
	return 0;
}