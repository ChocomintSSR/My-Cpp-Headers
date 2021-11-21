#include <iostream>
#include "Matrix.h"
using namespace std;

int main()
{
	matrix<double> a, b, c;
	a = {{1, 1, 1},
		 {1, 0, 0},
		 {0, 1, 0}};

	cout << "det(a) = " << a.det() << "\n"
		 << "det(b) = " << b.det() << "\n"
		 << "det(c) = " << c.det();

	return 0;
}
