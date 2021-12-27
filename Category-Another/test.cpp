#include <iostream>
#include "common.h"
#include <iomanip>
using namespace std;

vector<int> operator,(vector<int> v, int n)
{
	vector<int> res = v;
	res.push_back(n);
	return res;
}

int main()
{
	vector<int> v = {12, 34, 3, 5, 67, 87, 3, 2, 3, 1, 2, 3, 4, 5, 7, 7, 8, 5, 4, 2, 23};
	sort(all(v), [](int i, int j)
		 { return i < j; });
	cout << v << "\n";
	return 0;
}
