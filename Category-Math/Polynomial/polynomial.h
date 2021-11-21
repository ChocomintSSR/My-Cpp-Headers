#ifndef _POLYNOMIAL_H_
#define _POLYNOMIAL_H_

#include <iostream>
#include <vector>
#include <algorithm>
// typedef double Real;

namespace std
{
	struct QR_poly
	{
	public:
		vector<double> Quotient, Remainder;
	};

	// 降冪排列
	// arrangement in descending power
	class polynomial
	{
	private:
		// Eg: 4x^2+3x-1 -> {4,3,-1}
		vector<double> _poly;

	public:
		polynomial(initializer_list<double> _init_list) : _poly(_init_list.begin(), _init_list.end()) {}
		polynomial(vector<double> _vect) : _poly(_vect) {}
		vector<double> get_vector() { return this->_poly; }

		QR_poly operator/(const polynomial &_other);

		double operator()(const double &x);
		polynomial differentiate(int times);
		vector<double> roots();
	};

	ostream &operator<<(ostream &_os, polynomial &_ref)
	{
		auto poly = _ref.get_vector();
		for (int i = poly.size() - 1; i >= 0; i--)
		{
			_os << poly[i];
			if (i >= 2)
				_os << "x^" << i;
			else if (i == 1)
				_os << "x";
			_os << (i ? "+" : "");
		}
		return _os;
	}

	// Synthetic Division
	QR_poly polynomial::operator/(const polynomial &_other)
	{
		QR_poly res;
		vector<double> qr_line, poly = this->_poly;
		// the value in the Synthetic Division
		vector<vector<double>> tmp(_other._poly.size() - 1, vector<double>(this->_poly.size(), 0));
		res.Quotient.push_back(poly[0]); // put the leading coefficient into the top of Q
	}

	double polynomial::operator()(const double &x)
	{
		double result = 0;
		for (auto i : this->_poly)
		{
			result *= x;
			result += i;
		}
		return result;
	}

	polynomial polynomial::differentiate(int times)
	{
	}

	vector<double> polynomial::roots()
	{
		// cout << ((i % 2) * 2 - 1) * (i + 1) / 2 << "\n";
		// check negative roots
		for (int i = 0; i < 8; i++)
		{
		}
	}
}
#endif // _POLYNOMIAL_