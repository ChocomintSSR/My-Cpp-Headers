#include <iostream>
#include <string>
#include "Graph.h"
using namespace std;
using namespace chocomint;

int main()
{
	graph<int> g;
	g.set_zero(0);
	g.add(make_path(1, 2, 3));
	cout << g;
	return 0;
}
