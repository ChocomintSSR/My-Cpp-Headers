#include <iostream>
#include "Quaternion.h"
#include "..\..\Category-Another\common.h"
using namespace chocomint;

int main()
{
	Quaternion q(0, 1, 2, 1), q2(1, 1, 1, 1);
	std::cout << q - q2;
	return 0;
}
