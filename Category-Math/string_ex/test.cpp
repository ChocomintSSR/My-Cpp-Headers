#include <iostream>
#include <stdlib.h>
#include <string>
#include <algorithm>
using namespace std;

char *base_transform(const char *_string, int from_base, int to_base)
{
	char *c, tmp[10000];
	itoa(strtol(_string, &c, from_base), tmp, to_base);
	char *tmp2 = tmp;
	return tmp2;
}

int main()
{
	char c[100];
	cout << base_transform("123", 10, 10);
	return 0;
}
