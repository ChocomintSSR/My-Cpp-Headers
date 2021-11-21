#ifndef _COMPLEX_
#define _COMPLEX_

#include <iostream>
#include <string>
#include <cmath>

namespace chocomint
{
    class complex
    {
    public:
        double Re, Im;

        complex();
        complex(double val);
        complex(double val1, double val2);
        complex(const complex &val); // copy constructor can ONLY use the refrance

        bool operator==(const complex &ot);
        void operator=(const complex &ot);
        void operator=(const double &ot);

        friend complex operator^(const complex &th, const complex &ot);
        friend complex operator^(const complex &ot, const double n);
        friend complex operator^(const double n, const complex &ot);

        friend complex operator+(const complex &th, const complex &ot);
        friend complex operator-(const complex &th, const complex &ot);
        friend complex operator*(const complex &th, const complex &ot);
        friend complex operator/(const complex &th, const complex &ot);

        friend complex operator+(const double n, const complex &ot);
        friend complex operator-(const double n, const complex &ot);
        friend complex operator*(const double n, const complex &ot);
        friend complex operator/(const double n, const complex &ot);

        friend complex operator+(const complex &ot, const double n);
        friend complex operator-(const complex &ot, const double n);
        friend complex operator*(const complex &ot, const double n);
        friend complex operator/(const complex &ot, const double n);

        complex &operator+=(const complex &ot);
        complex &operator+=(const double &ot);
        complex &operator-=(const complex &ot);
        complex &operator-=(const double &ot);
        complex &operator*=(const complex &ot);
        complex &operator*=(const double &ot);
        complex &operator/=(const complex &ot);
        complex &operator/=(const double &ot);

        friend complex operator""i(long double val);
        friend complex operator""i(unsigned long long val);
    };

    const complex i = {0, 1};

    class polar_complex
    {
    public:
        double mod, arg;
    };

    // output the value
    std::ostream &operator<<(std::ostream &output, const complex print)
    {
        char symbol[2] = {'+', '-'};

        if (print.Re)
        {
            if (abs(print.Im) == 1)
                output << print.Re << " " << symbol[(print.Im < 0)] << " i";
            else
            {
                if (print.Im)
                    output << print.Re << " " << symbol[(print.Im < 0)] << " " << abs(print.Im) << "i";
                else
                    output << print.Re;
            }
        }
        else
        {
            switch (static_cast<int>(print.Im))
            {
            case 1:
                output << "i";
                break;
            case 0:
                output << 0;
                break;
            case -1:
                output << "-i";
                break;
            default:
                output << print.Im << "i";
                break;
            }
        }
        return output;
    }
    // input the value
    std::istream &operator>>(std::istream &input, complex &ob)
    {
        std::string s;
        bool positive = true;
        input >> s;

        if (s == "i")
        {
            ob.Re = 0;
            ob.Im = 1;
            return input;
        }
        else if (s == "-i")
        {
            ob.Re = 0;
            ob.Im = -1;
            return input;
        }

        int pos = s.find('+');
        if (pos == -1)
        {
            pos = s.find('-');
            positive = false;
        }

        int i = s.find('i');
        if (i == -1)
            throw "not a complex";

        std::string re = s.substr(0, pos),
                    im = s.substr(pos + 1, i - 2);

        ob.Re = (re == "\0") ? 0 : std::stod(re);
        ob.Im = (im == "\0") ? (positive ? 1 : -1) : std::stod(im);

        return input;
    }

    complex::complex()
    {
        this->Re = 0;
        this->Im = 0;
    }
    complex::complex(double val)
    {
        this->Re = val;
        this->Im = 0;
    }
    complex::complex(double val1, double val2)
    {
        this->Re = val1;
        this->Im = val2;
    }
    complex::complex(const complex &val)
    {
        *this = val;
    }

    //相等
    bool complex::operator==(const complex &ot)
    {
        return (this->Re == ot.Re) && (this->Im == ot.Im);
    }

    //賦值
    void complex::operator=(const complex &ot)
    {
        this->Re = ot.Re;
        this->Im = ot.Im;
    }
    void complex::operator=(const double &ot)
    {
        this->Re = ot;
        this->Im = 0;
    }

    //加
    complex operator+(const complex &th, const complex &ot)
    {
        return {th.Re + ot.Re, th.Im + ot.Im};
    }
    complex operator+(const double n, const complex &ot)
    {
        return {n + ot.Re, ot.Im};
    }
    complex operator+(const complex &ot, const double n)
    {
        return {n + ot.Re, ot.Im};
    }
    complex &complex::operator+=(const complex &ot)
    {
        this->Re += ot.Re;
        this->Im += ot.Im;
        return *this;
    }
    complex &complex::operator+=(const double &ot)
    {
        *this += {ot, 0};
        return *this;
    }

    //減
    complex operator-(const complex &th, const complex &ot)
    {
        return {th.Re - ot.Re, th.Im - ot.Im};
    }
    complex operator-(const double n, const complex &ot)
    {
        return {n - ot.Re, -ot.Im};
    }
    complex operator-(const complex &ot, const double n)
    {
        return {ot.Re - n, ot.Im};
    }
    complex &complex::operator-=(const complex &ot)
    {
        this->Re -= ot.Re;
        this->Im -= ot.Im;
        return *this;
    }
    complex &complex::operator-=(const double &ot)
    {
        *this -= {ot, 0};
        return *this;
    }

    //複數乘複數
    complex operator*(const complex &th, const complex &ot)
    {
        return {th.Re * ot.Re - th.Im * ot.Im, th.Im * ot.Re + th.Re * ot.Im};
    }
    complex operator*(const double n, const complex &ot)
    {
        return {n * ot.Re, n * ot.Im};
    }
    complex operator*(const complex &ot, const double n)
    {
        return {n * ot.Re, n * ot.Im};
    }
    complex &complex::operator*=(const complex &ot)
    {
        *this = *this * ot;
        return *this;
    }
    complex &complex::operator*=(const double &ot)
    {
        this->Re *= ot;
        this->Im *= ot;
        return *this;
    }
    //複數除複數
    complex operator/(const complex &th, const complex &ot)
    {
        double R = pow(ot.Re, 2) + pow(ot.Im, 2);
        complex temp = {th.Re * ot.Re + th.Im * ot.Im, th.Im * ot.Re - th.Re * ot.Im};
        return temp /= R;
    }
    complex operator/(const double n, const complex &ot)
    {
        complex N = n;
        return N / ot;
    }
    complex operator/(const complex &ot, const double n)
    {
        return {ot.Re / n, ot.Im / n};
    }
    complex &complex::operator/=(const complex &ot)
    {
        *this = *this / ot;
        return *this;
    }
    complex &complex::operator/=(const double &ot)
    {
        this->Re /= ot;
        this->Im /= ot;
        return *this;
    }

    complex operator""i(long double val)
    {
        return complex{0, (double)val};
    }
    complex operator""i(unsigned long long val)
    {
        return complex{0, (double)val};
    }

    //極座標轉換
    polar_complex trans(complex c)
    {
        return {sqrt(pow(c.Re, 2.0) + pow(c.Im, 2.0)), atan(c.Im / c.Re)};
    }

    //指數
    complex cexp(complex c)
    {
        return {exp(c.Re) * cos(c.Im), exp(c.Re) * sin(c.Im)};
    }
    //自然對數
    complex ln(complex c)
    {
        polar_complex p = trans(c);
        return {log(p.mod), p.arg};
    }
    //對數
    complex clog(double base, complex c)
    {
        return ln(c) / log(base);
    }
    complex clog(complex base, complex c)
    {
        return ln(c) / ln(base);
    }
    //C^C
    complex operator^(const complex &th, const complex &ot)
    {
        return 10 ^ (ot * clog(10, th));
    }
    //常數次方
    complex operator^(const complex &ot, const double n)
    {
        polar_complex p = trans(ot);
        return pow(p.mod, n) * cexp({0, n * p.arg});
    }
    //複數次方
    complex operator^(const double n, const complex &ot)
    {
        return cexp(ot * log(n));
    }
    //根號
    complex csqrt(complex c)
    {
        return c ^ 0.5;
    }

    //正弦
    complex csin(complex c)
    {
        return {sin(c.Re) * cosh(c.Im), cos(c.Re) * sinh(c.Im)};
    }
    //餘弦
    complex ccos(complex c)
    {
        return {cos(c.Re) * cosh(c.Im), -sin(c.Re) * sinh(c.Im)};
    }
    //正切
    complex ctan(complex c)
    {
        return csin(c) / ccos(c);
    }
    //反正弦
    complex arcsin(complex c)
    {
        return 0 - 1i * ln(1i * c + csqrt(1 - (c ^ 2)));
    }
    //反餘弦
    complex arccos(complex c)
    {
        return 0 - 1i * ln(c + 1i * csqrt(1 - (c ^ 2)));
    }
    //反正切
    complex arctan(complex c)
    {
        return 1 / (2 * 1i) * ln((1i - c) / (1i + c));
    }
    //雙曲正弦
    complex csinh(complex c)
    {
        return 1 - 1i * csin(1i * c);
    }
    //雙曲餘弦
    complex ccosh(complex c)
    {
        return ccos(1i * c);
    }
    //雙曲正切
    complex ctanh(complex c)
    {
        return csinh(c) / ccosh(c);
    }
}

#endif