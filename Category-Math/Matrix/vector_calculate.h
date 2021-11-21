#ifndef _VECTOR_EX_
#define _VECTOR_EX_

#include <vector>
#include <utility>

namespace std
{
    template <class T>
    ostream &operator<<(ostream &_output, const vector<T> &_vector)
    {
        for (auto i : _vector)
            _output << i << " ";
        return _output;
    }

    template <class T>
    T vabs(vector<T> v)
    {
        T tmp = 0;
        for (auto i : v)
            tmp += i * i;
        return pow(tmp, 0.5);
    }

    template <class T>
    vector<T> operator+(const vector<T> &_this, const vector<T> &_other)
    {
        vector<T> tmp;
        int size = max(_this.size(), _other.size());
        for (int i = 0; i < size; i++)
            tmp.push_back(_this[i] + _other[i]);
        return tmp;
    };

    template <class T>
    vector<T> operator-(const vector<T> &_this, const vector<T> &_other)
    {
        vector<T> tmp;
        int size = max(_this.size(), _other.size());
        for (int i = 0; i < size; i++)
            tmp.push_back(_this[i] - _other[i]);
        return tmp;
    };

    template <class T>
    T dot(vector<T> &a, vector<T> &b)
    {
        T tmp = 0;
        for (int i = 0; i < a.size(); i++)
            tmp += a[i] * b[i];
        return tmp;
    };

    template <class T>
    vector<T> operator*(const T z, const vector<T> &v)
    {
        vector<T> tmp;
        for (int i = 0; i < v.size(); i++)
            tmp.push_back(v[i] * z);
        return tmp;
    };

    template <class T>
    vector<T> operator*(const vector<T> &v, const T &z)
    {
        vector<T> tmp;
        for (int i = 0; i < v.size(); i++)
            tmp.push_back(v[i] * z);
        return tmp;
    };

    template <class T>
    vector<T> operator/(const vector<T> &v, const T &z)
    {
        vector<T> tmp;
        for (int i = 0; i < v.size(); i++)
            tmp.push_back(v[i] / z);
        return tmp;
    };
}

#endif