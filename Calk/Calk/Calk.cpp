#include "pch.h"
#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	cout << "Hello, my dear. What are the numbers?\n";
  double a, b, s;
	  a = 0;
	  b = 0;
	  cin >> a >> b;
	  cout << "Number 1: " << a << endl << "Number 2: " << b << endl;
  {
		  cout << "What do you want to do?" << endl << "1. +" << endl << "2. -" << endl << "3. *" << endl << "4. /" << endl;
		  int c;
		  cin >> c;
		  cout << "Your answer: " << c << endl;
     
     if (c == 1) {
		 s = a + b;
	 }
	 else {
		 if (c == 2) {
			 s = a - b;
		 }
		 else {
			 if (c == 3) {
				 s = a * b;
			 }
			 else
				 if (c == 4) {
					 s = a / b;
				 }
		 }
	 }
  }
  cout << "Result = " << s << endl;
 {
	  cout << "Do you want to try again? y/n" << endl;
	  char p, y;
	  p = (cin << y || n);
	  while (p == y);
 }
}  
