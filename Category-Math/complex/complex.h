#ifndef _COMPLEX_H_
#define _COMPLEX_H_

#include <iostream>
#include <cmath>

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

		complex operator+(const complex &_Right) { return {real + _Right.real, imag + _Right.imag}; }
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
}

#endif // _COMPLEX_H_