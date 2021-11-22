#include <iostream>
#include "unit.h"
using namespace std;

int main()
{
	unit<3> u({"sec", "min", "hr"}, {60, 60});
	u.to_value("min");
	return 0;
}
