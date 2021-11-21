#include <iostream>
#include <tuple>
using namespace std;

template <class... type>
tuple<type...> f(type... var)
{
	tuple<type...> tmp = {var...};
	return tmp;
}

int main()
{
	auto x = f(1, 2);
	tuple<int, string, char> t = {1, "234", '5'};
	cout << get<0>(t) << "\n";
	cout << "size: " << tuple_size<decltype(t)>::value;
	return 0;
}
