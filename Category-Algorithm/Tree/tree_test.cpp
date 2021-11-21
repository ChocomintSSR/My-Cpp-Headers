#include <iostream>
#include <bitset>
#include "tree.h"
using namespace std;
using namespace chocomint;

int main()
{
	bitset<10> b = 1000010100;
	binary_tree bnt;
	bnt.add_right<10>(b);
	return 0;
}
