#include <iostream>
#include "complex.h"
using namespace chocomint;

std::function<int(int)> test()
{
	std::function<int(int)> a = [](int x) -> int
	{ return x * x; };

	return a;
}

int main()
{
	complex z = 1 + 2 * i;
	std::cout << arctan(z).PV() << "\n"
			  << 1 / z << "\n";
	return 0;
}
