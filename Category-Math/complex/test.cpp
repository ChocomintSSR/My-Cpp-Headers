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
	std::cout << pow(i, i).PV();
	return 0;
}
