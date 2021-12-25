#ifndef _COMMON_H_
#define _COMMON_H_

#include <iostream>
#include <random>

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
	inline bool isPrime(char c)
	{
	}

	// Random
	int random(int lower_bound, int upper_bound)
	{
		random_device rd;
		default_random_engine gen = default_random_engine(rd());
		uniform_int_distribution<int> dis(lower_bound, upper_bound);
		return dis(gen);
	}

	// ostream <<
}

#endif // _COMMON_H_