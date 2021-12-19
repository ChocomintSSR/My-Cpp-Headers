#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <iomanip>
#define delta 1e-12
#define eps 1e-12
using namespace std;

inline double f(double w, double value) { return w * exp(w) - value; }

// precision: about 13 digits
double ProductLog(double _X)
{
	double root = 0;
	while (abs(f(root, _X)) > eps)
	{
		double diff = (f(root + delta, _X) - f(root - delta, _X)) / (2 * delta);
		root -= f(root, _X) / diff;
	}
	return root;
}
// precision: about 13 digits
inline double lambert_W(double _X) { return ProductLog(_X); }

int main()
{
	cout << setprecision(13) << ProductLog(1) << "\n";
	return 0;
}