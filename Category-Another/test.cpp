#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main()
{
	stringstream ss;
	ss << hex << 123;
	string s = ss.str();
	cout << s;
	return 0;
}
