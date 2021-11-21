#include <iostream>
#include "polynomial.h"
using namespace std;

int main()
{
	polynomial a = {1, -2, 1, -4, 3}, b = {1, -1, 1};
	auto x = a / b;
	polynomial q1 = x.Quotient, r1 = x.Remainder;
	cout << "q: " << q1 << "\n"
		 << "r: " << r1 << "\n";
	return 0;
}
