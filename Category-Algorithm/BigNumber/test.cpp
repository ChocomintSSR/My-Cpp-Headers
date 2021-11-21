#include <iostream>
#include "BigNumber.h"
using namespace std;
using namespace chocomint;

int main()
{
	BigInt bi = "123295856205465013454738384567329123278438479828953464564523478343263745"_BigInt;
	cout << (bi * 2);

	return 0;
}
