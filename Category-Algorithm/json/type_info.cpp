#include <iostream>
#include <typeinfo>
#include <vector>
using namespace std;

template <class... type>
void f(type... name)
{
	((cout << typeid(name).name() << "\n"), ...);
}

int main()
{
	vector<int> v = {1, 2, 3, 4};
	f(1, 2.3, "ab", 'z', v);
	return 0;
}
