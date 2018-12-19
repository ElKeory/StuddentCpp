#include "pch.h"
#include <iostream>
using namespace std;
int check_Z1(char *Z)
{
	int i = 0;
	if (Z[0] == '-')
		i = 1;
	for (; i < strlen(Z); i++)
		if (Z[i] >= '0' && Z[i] <= '9')
			return 0;
	return 1;
}
int check_Z2(char *Z)
{
	for (int i = 0; i < strlen(Z); i++)
		if (Z[i] != '+' && Z[i] != '-' && Z[i] != '*' && Z[i] != '/')
			return 1;
	return 0;
}
int main()
{
	double *N = new double[255]; char *Z = new char[255];
	int n = 0;
	cout << "Please enter the numbers when you finish typing enter \"end\".\n";
	while (true) {
		cin.getline(Z, 255);
		if (Z[0] == 'e' && Z[1] == 'n' && Z[2] == 'd')
			break;
		float e = check_Z1(Z);
		if (e && cout << "Error number\n")
			continue;
		N[n] = atof(Z); n++;
	}
	cout << "Enter the operations(+, -, *, /) ,when you are finished entering press \"Enter\".\n";
	int s;
	while (true) {
		cin.getline(Z, 255);
		int e = check_Z2(Z);
		if (e && cout << "Error symbol\n")
			continue;
		s = 0;
		for (int i = 0; i < n; i++)
			if (Z[i] != ' ') {
				Z[s] = Z[i]; s++;
			}
		if (s < 1)
			continue;
		break;
	}
	double R = N[0];
	for (int i = 0; i < (n) && i < s; i++) {
		switch (Z[i]) {
		case '+':
			R = R + N[i + 1];
			break;
		case '-':
			R = R - N[i + 1];
			break;
		case '*':
			R = R * N[i + 1];
			break;
		case '/':
			R = R / N[i + 1];
		}
	}
	cout << "Result = " << R << '\n';
	delete[] Z; delete[] N;
	return 0;
}
