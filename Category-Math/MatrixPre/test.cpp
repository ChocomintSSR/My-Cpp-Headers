#include <iostream>
#include "Matrix.h"
using namespace std;

int main()
{
	matrix<double> matA, matB, q;
	matA = {{2.92, 0.86, -1.15},
			{0.86, 6.51, 3.32},
			{-1.15, 3.32, 4.57}};

	matB = {{2, 1, 1},
			{3, -1, 4},
			{-3, 2, -3}};

	cout << QRdecompose(matA).Q;

	return 0;
}
