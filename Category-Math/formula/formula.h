#ifndef _FORMULA_
#define _FORMULA_

#include <iostream>
#include <stdlib.h>
#define delta 1e-11
#define eps 1e-7
double lowerBound = -1e8, upperBound = 1e8;

namespace chocomint
{
    template <class T1, class T2>
    class formula
    {
    private:
        T1(*f)
        (T2);

    public:
        formula();
        formula(T1 (*func)(T2));

        T1 operator()(const T2 &_at);
        T1 differential(const T2 &_at);
        T1 diff_N_order(const int &N, const T2 &_at);
        T1 integral(const T2 &_lower, const T2 &_upper);
        T1 find_root();
    };

    template <class T1, class T2>
    formula<T1, T2>::formula() {}

    template <class T1, class T2>
    formula<T1, T2>::formula(T1 (*func)(T2))
    {
        this->f = func;
    }

    template <class T1, class T2>
    T1 formula<T1, T2>::operator()(const T2 &_at)
    {
        return this->f(_at);
    }

    template <class T1, class T2>
    T1 formula<T1, T2>::differential(const T2 &_at)
    {
        T1 diff = (this->f(_at + delta) - this->f(_at - delta)) / (2 * delta);
        return diff;
    }

    template <class T1, class T2>
    T1 formula<T1, T2>::diff_N_order(const int &N, const T2 &_at)
    {
        return (N == 1) ? (this->differential(_at)) : ((this->diff_N_order(N - 1, _at + delta) - this->diff_N_order(N - 1, _at - delta)) / (2 * delta));
    }

    // Simpson's Rule
    template <class T1, class T2>
    T1 formula<T1, T2>::integral(const T2 &_lower, const T2 &_upper)
    {
        int n = 5e4;
        T2 section = (_upper - _lower) / n, res = 0;
        for (int i = 0; i < n; i++)
        {
            T2 low = _lower + section * i, up = low + section, mid = (low + up) / 2;
            res += ((up - low) / 6) * (this->f(low) + 4 * this->f(mid) + this->f(up));
        }
        return res;
    }

    template <class T1, class T2>
    T1 bns(T2 l, T2 u, T1 (*func)(T2))
    {
        T2 m = (l + u) / 2;
        if (abs(func(m)) < eps)
            return m;
        if (func(l) * func(m) < 0)
            bns(l, m, func);
        else
            bns(m, u, func);
    }

    template <class T1, class T2>
    T1 formula<T1, T2>::find_root()
    {
        for (double i = lowerBound; i < upperBound; i += 1e4)
        {
            auto j = i + 1e4;
            std::cout << this->f(i) << " | " << this->f(j) << " => "
                      << this->f(i) * this->f(j) << " (" << abs(this->f(i)) << "\n";
            if (abs(this->f(i)) < eps)
                return i;
            else if ((this->f(i) / abs(this->f(i))) * (this->f(j) / abs(this->f(j))) < 0)
                return bns(i, j, this->f);
        }
    }

    // template <class re, class... variables>
    // class multivar_formula
    // {
    // private:
    //     re (*f)(variables... var);

    // public:
    //     multivar_formula();
    //     multivar_formula(re (*func)(variables... var));

    //     re operator()(variables... var);
    // };

    // template <class re, class... variables>
    // re multivar_formula<re, variables...>::operator()(variables... var)
    // {
    //     return this->f(var...);
    // }
}

#endif