#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

void main()
{	
	setlocale(LC_ALL, "Rus");
	cout << ("Enter today's date (year, month and day)\n");
	  int todayY=0, todayM=0, todayD=0;
	  cin >> todayY >> todayM >> todayD;
    cout << " What is your name? When you were born (year, month and day)?\n"; 
	string n;	
	int t1 = 0, t2 = 0, t3 = 0;
    cin >> n >> t1 >> t2 >> t3;	
	t1 = todayY - t1;
	int a;
	if (todayM > t2) {
		a = 0;
	}
	else {
		if (todayM = t2) {
			if (todayD < t3) {
				a = 1;
			}
		}
		else {
			if (todayM < t2) {
				a = 0;
			}
		}
	}
	a = t1 - a;
	cout << "Hello, " << n << endl << "You're " << a << " old.";
}