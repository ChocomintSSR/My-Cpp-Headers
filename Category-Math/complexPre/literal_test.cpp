#include <iostream>
using namespace std;
#define ull unsigned long long int

ull operator"" kg(ull x)
{
	return x * 1000;
}

int main()
{
	auto k = 12kg;
	return 0;
}
