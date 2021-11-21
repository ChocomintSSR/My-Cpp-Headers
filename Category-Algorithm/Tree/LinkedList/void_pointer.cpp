#include <iostream>
#include <vector>
#include <string>
using namespace std;

template <class T>
void print(void *in)
{
	cout << *(T *)in << "\n";
}

int main()
{
	vector<void *> v;

	// data
	int a = 2;
	double b = 3.0;
	char c = 'c';
	string s = "abc";

	// input data into vector<void*>
	v.push_back(&a);
	v.push_back(&b);
	v.push_back(&c);
	v.push_back(&s);

	print<int>(v[0]);
	print<double>(v[1]);
	print<char>(v[2]);
	print<string>(v[3]);

	return 0;
}
