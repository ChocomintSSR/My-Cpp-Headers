#include <iostream>
#include "complex.h"
#include <string>
using namespace chocomint;

std::function<int(int)> test()
{
	std::function<int(int)> a = [](int x) -> int
	{ return x * x; };

	return a;
}

int main()
{
	std::string s1, s2;
	s1 += s2;

	complex z = 1 + 2 * i;
	std::cout << z;
	return 0;
}
