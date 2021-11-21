// Lambda Expression in C++

// [ capture clause ] (parameters) 'mutable throw()' -> return-type
// {
//    definition of method
// }

#include <iostream>
using namespace std;

int main()
{
	int (*fx)(int);

	auto f1 = [](int a) -> int
	{ return a * 10; };
	fx = f1;

	cout << fx(2);

	return 0;
}
