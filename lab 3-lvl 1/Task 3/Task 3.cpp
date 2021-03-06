#include "pch.h"
#include <iostream>
#include <vector>
#define elif else if

typedef unsigned char ctr;
using namespace std;

ctr check(char*& a);
ctr priority(char& p);
double apply(double x, double y, char p);

int main()
{
	char *text = new char[255];
	cin.getline(text, 255);
	text = static_cast<char*>(realloc(text, strlen(text) + 1));

	switch (check(text))
	{
		case 1: cout << "A lot of symbols" << endl; delete[] text; return 0;
		case 2: cout << "A lot of brackets" << endl; delete[] text; return 0;
		case 3: cout << "Error symbols" << endl; delete[] text; return 0;
	}

	vector<char> str;
	vector<double> def;
	vector<char> tmp; tmp.push_back('0');

	char*& a = text;

	for (ctr i = 0, n = 0; i < strlen(a); i++)
	{
		if ((isdigit(a[i])) || (i == 0 || a[i - 1] == '*' || a[i - 1] == '/' || a[i - 1] == '(') && (a[i] == '+' || a[i] == '-'))
		{
			str.push_back(n++); def.push_back(atof(a + i++));
			while (a[i] == '.' || isdigit(a[i])) i++;
		}
		if (a[i] == '+' || a[i] == '-' || a[i] == '*' || a[i] == '/')
		{
			if (priority(a[i]) <= priority(tmp.back()))
			{
				str.push_back(tmp.back()); tmp.pop_back();
				tmp.push_back(a[i]);
			}
			else tmp.push_back(a[i]);
		}
		if (a[i] == '(') tmp.push_back(a[i]);
		if (a[i] == ')')
		{
			while (tmp.back() != '(')
			{
				str.push_back(tmp.back()); tmp.pop_back();
			}
			tmp.pop_back();
		}
	}
	while (tmp.back() != '0')
	{
		str.push_back(tmp.back()); tmp.pop_back();
	}

	delete[] text;
	tmp.clear();

	ctr len = str.size();
	for (ctr i = 0, flag = false; i < len && len > 1; flag = false, i++)
	{
		while (str[i] < 32) i++;
		def[str[i - 2]] = apply(def[str[i - 2]], def[str[i - 1]], str[i]);

		for (ctr j = 0, k = 0; j < len; j++)
		{
			if (j != i - 1 && j != i)
				str[k++] = str[j];
			flag = true;
		}
		if (flag)
		{
			len -= 2;
			i = 0;
		}
	}

	cout << def[0];
	return 0;
}

ctr check(char*& a)
{
	ctr b = 0;
	for (ctr i = 0; i < strlen(a) && b >= 0; i++)
	{
		if (a[i] == '+' || a[i] == '-')
		{
			if (a[i + 1] == '+' || a[i + 1] == '-' || a[i + 1] == '*' || a[i + 1] == '/' || a[i + 1] == ')' || a[i + 1] == '\0') return 1;
		}
		elif(a[i] == '*' || a[i] == '/')
		{
			if (i == 0 || a[i + 1] == '*' || a[i + 1] == '/' || a[i + 1] == ')' || a[i + 1] == '\0') return 1;
		}
		elif(a[i] == '(')
		{
			if (a[i + 1] == '*' || a[i + 1] == '/' || a[i + 1] == ')' || a[i + 1] == '\0') return 2; b++;
		}
		elif(a[i] == ')')
		{
			if (i == 0) return 2; b--;
		}
		elif(a[i] == '.' || isdigit(a[i]))
		{
			ctr c = 0;
			while (a[i] == '.' || isdigit(a[i]))
				if (a[i++] == '.') c++;
			if (c > 1) return 3;
			i--;
		}
		else return 3;
	}

	if (b != 0) return 2;

	return 0;
}

ctr priority(char& p)
{
	switch (p)
	{
		case '(': case '0': return 0;
		case '+': case '-': return 1;
		case '*': case '/': return 2;
	}
}

double apply(double x, double y, char p)
{
	switch (p)
	{
		case '+': return x + y;
		case '-': return x - y;
		case '*': return x * y;
		case '/': return x / y;
	}
}
