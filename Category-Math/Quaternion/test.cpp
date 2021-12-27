#include <iostream>
#include "Quaternion.h"
#include "..\..\Category-Another\common.h"
using namespace chocomint;
#define rad 3.141592653589793 / 180

int main()
{
	Vector3D u(1, 0, 0);
	std::cout << RQ(u, 270 * rad) << "\n";

	Quaternion q(1, 1, 2, 1), q2(1, -3, 1, 4);
	// std::cout << q / q2;
	return 0;
}
