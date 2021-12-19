#include <iostream>
#include <cmath>
#include <string>
#define e 2.718281828
#define error 1e-8
using namespace std;
//======================================================//

namespace Complex
{
	//複數型態
	struct comp
	{
		double Re, Im;

		bool operator==(const comp &ot);
		void operator=(const comp &ot);
		void operator=(const double &ot);

		friend comp operator^(const comp &th, const comp &ot);
		friend comp operator^(const comp &ot, const double n);
		friend comp operator^(const double n, const comp &ot);

		friend comp operator+(const comp &th, const comp &ot);
		friend comp operator-(const comp &th, const comp &ot);
		friend comp operator*(const comp &th, const comp &ot);
		friend comp operator/(const comp &th, const comp &ot);

		friend comp operator+(const double n, const comp &ot);
		friend comp operator-(const double n, const comp &ot);
		friend comp operator*(const double n, const comp &ot);
		friend comp operator/(const double n, const comp &ot);

		friend comp operator+(const comp &ot, const double n);
		friend comp operator-(const comp &ot, const double n);
		friend comp operator*(const comp &ot, const double n);
		friend comp operator/(const comp &ot, const double n);

		comp &operator+=(const comp &ot);
		comp &operator-=(const comp &ot);
		comp &operator*=(const comp &ot);
		comp &operator*=(const double &ot);
		comp &operator/=(const comp &ot);
		comp &operator/=(const double &ot);
	};

	//print
	ostream &operator<<(ostream &output, const comp print)
	{
		if (print.Re == 0)
		{
			if (print.Im == 1)
				output << "i";
			else if (print.Im == -1)
				output << "-i";
			else if (print.Im == 0)
				output << "0";
			else
				output << print.Im << "i";
		}
		else
		{
			if (print.Im == 1)
			{
				output << print.Re << " + i";
			}
			else if (print.Im == -1)
			{
				output << print.Re << " - i";
			}
			else
			{
				if (print.Im > 0)
				{
					output << print.Re << " + " << print.Im << "i";
				}
				else if (print.Im == 0)
					output << print.Re;
				else
				{
					output << print.Re << " - " << -print.Im << "i";
				}
			}
		}
		return output;
	}
	//get value
	istream &operator>>(istream &input, comp &ob)
	{
		string s;
		input >> s;
		int len = s.length(), pos = s.rfind("+");
		ob.Re = stod(s.substr(0, pos));
		ob.Im = stod(s.substr(pos, len - pos + 1));
		return input;
	}

	//基本運算

	//相等
	bool comp::operator==(const comp &ot)
	{
		return (this->Re == ot.Re) && (this->Im == ot.Im);
	}

	//賦值
	void comp::operator=(const comp &ot)
	{
		Re = ot.Re;
		Im = ot.Im;
	}
	void comp::operator=(const double &ot)
	{
		Re = ot;
		Im = 0;
	}

	//加
	comp operator+(const comp &th, const comp &ot)
	{
		return {th.Re + ot.Re, th.Im + ot.Im};
	}
	comp operator+(const double n, const comp &ot)
	{
		return {n + ot.Re, ot.Im};
	}
	comp operator+(const comp &ot, const double n)
	{
		return {n + ot.Re, ot.Im};
	}
	comp &comp::operator+=(const comp &ot)
	{
		this->Re += ot.Re;
		this->Im += ot.Im;
		return *this;
	}
	//減
	comp operator-(const comp &th, const comp &ot)
	{
		return {th.Re - ot.Re, th.Im - ot.Im};
	}
	comp operator-(const double n, const comp &ot)
	{
		return {n - ot.Re, -ot.Im};
	}
	comp operator-(const comp &ot, const double n)
	{
		return {ot.Re - n, ot.Im};
	}
	comp &comp::operator-=(const comp &ot)
	{
		this->Re -= ot.Re;
		this->Im -= ot.Im;
		return *this;
	}
	//複數乘複數
	comp operator*(const comp &th, const comp &ot)
	{
		return {th.Re * ot.Re - th.Im * ot.Im, th.Im * ot.Re + th.Re * ot.Im};
	}
	comp operator*(const double n, const comp &ot)
	{
		return {n * ot.Re, n * ot.Im};
	}
	comp operator*(const comp &ot, const double n)
	{
		return {n * ot.Re, n * ot.Im};
	}
	comp &comp::operator*=(const comp &ot)
	{
		*this = *this * ot;
		return *this;
	}
	comp &comp::operator*=(const double &ot)
	{
		this->Re *= ot;
		this->Im *= ot;
		return *this;
	}
	//複數除複數
	comp operator/(const comp &th, const comp &ot)
	{
		double R = pow(ot.Re, 2) + pow(ot.Im, 2);
		comp temp = {th.Re * ot.Re + th.Im * ot.Im, th.Im * ot.Re - th.Re * ot.Im};
		return temp /= R;
	}
	comp operator/(const double n, const comp &ot)
	{
		comp N = {n, 0};
		return N / ot;
	}
	comp operator/(const comp &ot, const double n)
	{
		return {ot.Re / n, ot.Im / n};
	}
	comp &comp::operator/=(const comp &ot)
	{
		*this = *this / ot;
		return *this;
	}
	comp &comp::operator/=(const double &ot)
	{
		this->Re /= ot;
		this->Im /= ot;
		return *this;
	}

	//極座標型態
	struct polar_comp
	{
		double mod, arg;
	};

	//複數運算
	class complex
	{
	private:
		comp zero;
		comp one;

	public:
		comp i;
		complex();
		polar_comp trans(comp c);
		comp csqrt(comp c);
		comp cexp(comp c);
		comp ln(comp c);
		comp clog(double base, comp c);
		comp clog(comp base, comp c);
		comp csin(comp c);
		comp ccos(comp c);
		comp ctan(comp c);
		comp arcsin(comp c);
		comp arccos(comp c);
		comp arctan(comp c);
		comp csinh(comp c);
		comp ccosh(comp c);
		comp ctanh(comp c);
	};

	complex::complex()
	{
		i = {0, 1};
		zero = {0, 0};
		one = {1, 0};
	}

	//極座標轉換
	polar_comp complex::trans(comp c)
	{
		return {sqrt(pow(c.Re, 2.0) + pow(c.Im, 2.0)), atan(c.Im / c.Re)};
	}

	//C^C
	comp operator^(const comp &th, const comp &ot)
	{
		complex c;
		return 10 ^ (ot * c.clog(10, th));
	}
	//常數次方
	comp operator^(const comp &ot, const double n)
	{
		complex c;
		polar_comp p = c.trans(ot);
		return pow(p.mod, n) * c.cexp({0, n * p.arg});
	}
	//複數次方
	comp operator^(const double n, const comp &ot)
	{
		complex c;
		return c.cexp(ot * log(n));
	}

	//根號
	comp complex::csqrt(comp c)
	{
		return c ^ 0.5;
	}
	//指數
	comp complex::cexp(comp c)
	{
		return {exp(c.Re) * cos(c.Im), exp(c.Re) * sin(c.Im)};
	}
	//自然對數
	comp complex::ln(comp c)
	{
		polar_comp p = trans(c);
		return {log(p.mod), p.arg};
	}
	//對數
	comp complex::clog(double base, comp c)
	{
		return ln(c) / log(base);
	}
	comp complex::clog(comp base, comp c)
	{
		return ln(c) / ln(base);
	}

	//正弦
	comp complex::csin(comp c)
	{
		return {sin(c.Re) * cosh(c.Im), cos(c.Re) * sinh(c.Im)};
	}
	//餘弦
	comp complex::ccos(comp c)
	{
		return {cos(c.Re) * cosh(c.Im), -sin(c.Re) * sinh(c.Im)};
	}
	//正切
	comp complex::ctan(comp c)
	{
		return csin(c) / ccos(c);
	}
	//反正弦
	comp complex::arcsin(comp c)
	{
		return 0 - i * ln(i * c + csqrt(one - (c ^ 2)));
	}
	//反餘弦
	comp complex::arccos(comp c)
	{
		return 0 - i * ln(c + i * csqrt(one - (c ^ 2)));
	}
	//反正切
	comp complex::arctan(comp c)
	{
		return 1 / (2 * i) * ln((i - c) / (i + c));
	}
	//雙曲正弦
	comp complex::csinh(comp c)
	{
		return 1 - i * csin(i * c);
	}
	//雙曲餘弦
	comp complex::ccosh(comp c)
	{
		return ccos(i * c);
	}
	//雙曲正切
	comp complex::ctanh(comp c)
	{
		return csinh(c) / ccosh(c);
	}
}
