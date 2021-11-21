#include <iostream>
#include <cmath>
#include <iomanip>
#include "formula.h"
#define pi 3.141592653589793
using namespace chocomint;

class math
{
public:
	double def(double x)
	{
		return pow(x, 2) + 2 * x - 1;
	}
};

int main()
{
	math m;
	formula<double, double> h1(math::def);
	std::cout << h1.find_root() << "\n";

	return 0;
}
