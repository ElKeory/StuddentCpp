#include "pch.h"
#include <iostream>
using namespace std;
int check_Z1(char *Z)
{
	char i = 0;
	if (Z[0] == '-')
		i = 1;
	for (; i < strlen(Z); i++)
		if (!(Z[i] >= '0' && Z[i] <= '9'))
			return 1;
	return 0;
}
int check_Z2(char *Z)
{
	for (char i = 0; i < strlen(Z); i++)
		if (Z[i] != '+' && Z[i] != '-' && Z[i] != '*' && Z[i] != '/' && Z[i] != ' ')
			return 1;
	return 0;
}
int main()
{
	float *N = new float[32]; char *Z = new char[255];
	char n = 0;
	cout << "Enter the numbers in the column, when you finish typing, write \"end\".\n";
	while (true)
	{
		cin.getline(Z, 255);
		if (Z[0] == 'e' && Z[1] == 'n' && Z[2] == 'd' && n > 0)
			break;
		char e = check_Z1(Z);
		if (e && cout << "Error number\n")
			continue;
		N[n] = atof(Z), n++;
	}
	char s;
	cout << "Enter the symbols in the line, when you finish typing, press \"Enter\".\n";
	while (true)
	{
		cin.getline(Z, 255);
		s = 0;
		for (char i = 0; i < strlen(Z); i++)
			if (Z[i] != ' ')
				Z[s] = Z[i], s++;
		char e = check_Z2(Z);
		if (e && cout << "Error symbol\n")
			continue;
		break;
	}
	float r = N[0];
	for (char i = 0; i < n - 1 && i < s; i++)
	{
		switch (Z[i])
		{
		case '+':
			r = r + N[i + 1];
			break;
		case '-':
			r = r - N[i + 1];
			break;
		case '*':
			r = r * N[i + 1];
			break;
		case '/':
			r = r / N[i + 1];
		}
	}
	cout << "Result = " << r << '\n';
	delete[] Z; delete[] N;
	return 0;
}
