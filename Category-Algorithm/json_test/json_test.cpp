#include <iostream>
#include <vector>
#include <utility>
#include "json.h"
using namespace std;
using namespace chocomint;

int main()
{
	string s;
	json<double, int> j2({"123", 2.0}, {"123", 2});
	return 0;
}
