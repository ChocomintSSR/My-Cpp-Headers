#include <iostream>
#include "Matrix.h"
using namespace std;

int main()
{
	Matrix a = {{0, 1, 0},
				{0, 0, 1},
				{1, 0, -1}};
	cout << EigenValue(a);
}
