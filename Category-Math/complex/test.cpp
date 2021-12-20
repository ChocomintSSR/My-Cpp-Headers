#include <iostream>
#include "complex.h"
using namespace chocomint;

int main()
{
	complex z = {1, 2};
	std::cout << z + z;
	return 0;
}
