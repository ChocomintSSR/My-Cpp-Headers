#ifndef _COMMON_H_
#define _COMMON_H_

#include <iostream>
#include <random>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
#include <set>
#include <stdlib.h>

// define
#define ull unsigned long long

#define delta 1e-12
#define eps 1e-12

#define times(n) for (int i = 0; i < n; i++)

namespace std
{
	// Math

	inline int gcd(int m, int n) { return (m == 0) ? m : gcd(n, m % n); }
	inline int frac(int n) { return (n == 1) ? 1 : frac(n - 1); }
	inline int P(int m, int n) { return frac(m) / frac(m - n); }
	inline int C(int m, int n) { return P(m, n) / frac(n); }
	inline int H(int m, int n) { return C(m + n - 1, n); }

	// Boolean

	inline bool isNumber(char c) { return (c >= '0' && c <= '9'); }
	inline bool isNumber(string s) { return s.find_first_not_of("0123456789") == string::npos; }
	bool isPrime(int n)
	{
		if (n < 2)
			return false;

		if (n % 2 == 0)
			return n == 2;

		for (int i = 3; i < sqrt(n); i += 2)
		{
			if (n % i == 0)
				return false;
		}

		return true;
	}

	// Random
	random_device rd;
	default_random_engine gen = default_random_engine(rd());
	int random_i(int lower_bound, int upper_bound)
	{
		uniform_int_distribution<int> dis(lower_bound, upper_bound);
		return dis(gen);
	}
	double random_d(double lower_bound, double upper_bound)
	{
		uniform_real_distribution<double> dis(lower_bound, upper_bound);
		return dis(gen);
	}
	double normal_dis(double lower_bound, double upper_bound)
	{
		normal_distribution<double> dis(lower_bound, upper_bound);
		return dis(gen);
	}

	// ostream <<

	template <class _Ty>
	ostream &operator<<(ostream &_os, const vector<_Ty> &_Right)
	{
		for (auto i : _Right)
			_os << i << " ";
		return _os;
	}

	template <class _Ty>
	ostream &operator<<(ostream &_os, const set<_Ty> &_Right)
	{
		for (auto i : _Right)
			_os << i << " ";
		return _os;
	}

	template <class _Ty1, class _Ty2>
	ostream &operator<<(ostream &_os, const pair<_Ty1, _Ty2> &_Right)
	{
		_os << _Right.first << " " << _Right.second;
		return _os;
	}

	template <class _Ty1, class _Ty2>
	ostream &operator<<(ostream &_os, const map<_Ty1, _Ty2> &_Right)
	{
		for (auto i : _Right)
			cout << i.first << " -> " << i.second << "\n";
		return _os;
	}

	// lambert inverse
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

	//
	// char positional(const char *number, int radix1, int radix2)
	// {
	// 	char *c, res[99999];
	// 	itoa(strtol(number, &c, radix1), res, radix2);
	// 	return static_cast<char *>(res);
	// }
}

#endif // _COMMON_H_