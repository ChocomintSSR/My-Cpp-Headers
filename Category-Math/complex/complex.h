#ifndef _COMPLEX_H_
#define _COMPLEX_H_

#include <iostream>
#include <cmath>
#include <functional>
#define i complex(0, 1)
#define pi 3.14159265358979323846

namespace chocomint
{
	class complex
	{
	private:
		double real, imag;

	public:
		complex() : real(0.0), imag(0.0) {}
		complex(double Value) : real(Value), imag(0.0) {}
		complex(double Real, double Imagine) : real(Real), imag(Imagine) {}

		double Re() const { return real; }
		double Im() const { return imag; }
		double mod() const { return std::sqrt(real * real + imag * imag); }
		double Arg() const { return atan2(imag, real); } // principle value of argument
		complex conj() const { return {real, -imag}; }
	};

	std::ostream &operator<<(std::ostream &_os, const complex &_Right)
	{
		char symbol[2] = {'+', '-'};

		if (_Right.Re())
		{
			if (std::abs(_Right.Im()) == 1)
				_os << _Right.Re() << " " << symbol[(_Right.Im() < 0)] << " i";
			else
			{
				if (_Right.Im())
					_os << _Right.Re() << " " << symbol[(_Right.Im() < 0)] << " " << std::abs(_Right.Im()) << "i";
				else
					_os << _Right.Re();
			}
		}
		else
		{
			switch (static_cast<int>(_Right.Im()))
			{
			case 1:
				_os << "i";
				break;
			case 0:
				_os << 0;
				break;
			case -1:
				_os << "-i";
				break;
			default:
				_os << _Right.Im() << "i";
				break;
			}
		}
		return _os;
	}

	inline complex operator+(const complex &_Left, const complex &_Right) { return {_Left.Re() + _Right.Re(), _Left.Im() + _Right.Im()}; }
	inline complex operator+(const complex &_Left, const double &_Right) { return {_Left.Re() + _Right, _Left.Im()}; }
	inline complex operator+(const double &_Left, const complex &_Right) { return {_Right.Re() + _Left, _Right.Im()}; }

	inline complex operator-(const complex &_Left, const complex &_Right) { return {_Left.Re() - _Right.Re(), _Left.Im() - _Right.Im()}; }
	inline complex operator-(const complex &_Left, const double &_Right) { return {_Left.Re() - _Right, _Left.Im()}; }
	inline complex operator-(const double &_Left, const complex &_Right) { return {_Left - _Right.Re(), -_Right.Im()}; }
	inline complex operator-(const complex &_Comp) { return {complex(0, 0) - _Comp}; }

	inline complex operator*(const complex &_Left, const complex &_Right) { return {_Left.Re() * _Right.Re() - _Left.Im() * _Right.Im(), _Left.Re() * _Right.Im() + _Left.Im() * _Right.Re()}; }
	inline complex operator*(const complex &_Left, const double &_Right) { return {_Left.Re() * _Right, _Left.Im() * _Right}; }
	inline complex operator*(const double &_Left, const complex &_Right) { return {_Right.Re() * _Left, _Right.Im() * _Left}; }

	inline complex operator/(const complex &_Left, const complex &_Right) { return (_Left * _Right.conj()) / _Right.mod(); }
	inline complex operator/(const complex &_Left, const double &_Right) { return {_Left.Re() / _Right, _Left.Im() / _Right}; }
	inline complex operator/(const double &_Left, const complex &_Right) { return _Left * _Right.conj() / _Right.mod(); }

	inline complex exp(const complex &_Right) { return std::exp(_Right.Re()) * complex(std::cos(_Right.Im()), std::sin(_Right.Im())); }

	inline complex sin(const complex &_Right) { return (exp(i * _Right) - exp(-i * _Right)) / (2 * i); }
	inline complex cos(const complex &_Right) { return (exp(i * _Right) + exp(-i * _Right)) / 2; }
	inline complex tan(const complex &_Right) { return sin(_Right) / cos(_Right); }

	inline complex sinh(const complex &_Right) { return (exp(_Right) - exp(-_Right)) / 2; }
	inline complex cosh(const complex &_Right) { return (exp(_Right) + exp(-_Right)) / 2; }
	inline complex tanh(const complex &_Right) { return sinh(_Right) / cosh(_Right); }

	using fci = std::function<complex(int)>;
	class multiple_valued
	{
	private:
		fci _formula;

	public:
		multiple_valued(fci Formula) : _formula(Formula) {}
		complex value(int k_th) { return this->_formula(k_th); }
		// principle value
		complex PV() { return this->value(0); }
	};

	multiple_valued Ln(const complex &_Right)
	{
		fci _return = [&](int k) -> complex
		{ return complex(std::log(_Right.mod()), _Right.Arg() + 2 * k * pi); };
		return multiple_valued(_return);
	}

	multiple_valued pow(const complex &_Base, const complex &_Power)
	{
		complex A = exp(_Power * Ln(_Base).PV());
		fci _return = [&](int k) -> complex
		{ return A * exp(2 * k * pi * complex(-_Power.Im(), _Power.Re())); };
		return _return;
	}
}

#endif // _COMPLEX_H_