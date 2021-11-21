#include <iostream>
#include <vector>
#include "stringEX.h"
#include <fstream>
#include "fileEX.h"
using namespace std;

int main()
{
	ifstream is;
	is.open("123");
	auto x = read_csv("test.csv");
	for (auto i : x)
	{
		for (auto j : i)
			cout << j << " ";
		cout << "\n";
	}
	return 0;
}
