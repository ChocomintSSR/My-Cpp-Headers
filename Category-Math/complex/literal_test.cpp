#include <iostream>
using namespace std;

long double operator"" kg(long double x)
{
	return x * 1000;
}

int main()
{
	long double kg = 12kg;
	return 0;
}
