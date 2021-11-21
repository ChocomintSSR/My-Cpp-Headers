#ifndef _MATRIX_
#define _MATRIX_

#include <iostream>
#include <cmath>
#include <vector>
#define eps 1e-13

namespace std
{
    template <class T>
    class matrix
    {
    private:
        T det_diag(const int &m, const int &n);

    public:
        vector<vector<T>> value;
        matrix(){};
        matrix(int n, int _val);
        matrix(int row, int col, int _val);

        int row_size();
        int column_size();

        vector<T> operator[](int index);
        void operator=(const matrix<T> &ot);
        void operator=(const vector<vector<T>> &ot);

        matrix<T> operator+(const matrix<T> &ot);
        matrix<T> operator-(const matrix<T> &ot);
        matrix<T> operator*(const matrix<T> &ot);
        matrix<T> operator*(const T &ot);
        matrix<T> operator/(const T &ot);

        matrix<T> &operator+=(const matrix<T> &ot);
        matrix<T> &operator-=(const matrix<T> &ot);
        matrix<T> &operator*=(const matrix<T> &ot);
        matrix<T> &operator*=(const T &ot);

        T det();
        matrix<T> Trans();
        T M(int r, int c);
        T A(int r, int c);
        matrix<T> adj();
        matrix<T> inverse();
    };

    template <class T>
    matrix<T>::matrix(int n, int _val)
    {
        for (int i = 0; i < n; i++)
        {
            vector<T> vec;
            for (int i = 0; i < n; i++)
            {
                vec.push_back(_val);
            }
            this->value.push_back(vec);
        }
    }

    template <class T>
    matrix<T>::matrix(int row, int col, int _val)
    {
        for (int i = 0; i < row; i++)
        {
            vector<T> vec;
            for (int i = 0; i < col; i++)
            {
                vec.push_back(_val);
            }
            this->value.push_back(vec);
        }
    }

    template <class T>
    ostream &operator<<(ostream &output, const matrix<T> &mat)
    {
        for (vector<T> i : mat.value)
        {
            for (T j : i)
                output << ((abs(j) < eps) ? 0 : j) << ",";
            output << "\n";
        }
        return output;
    }

    template <class T>
    int matrix<T>::row_size()
    {
        return this->value.size();
    }
    template <class T>
    int matrix<T>::column_size()
    {
        return this->value[0].size();
    }

    template <class T>
    vector<T> matrix<T>::operator[](int index)
    {
        return this->value[index];
    }

    template <class T>
    void matrix<T>::operator=(const matrix<T> &ot) { this->value = ot.value; }
    template <class T>
    void matrix<T>::operator=(const vector<vector<T>> &ot) { this->value = ot; }

    template <class T>
    matrix<T> matrix<T>::operator+(const matrix<T> &ot)
    {
        int r = this->row_size(), c = this->column_size();
        matrix<T> tmp(r, c, 0);
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
                tmp.value[i][j] = this->value[i][j] + ot.value[i][j];
        }
        return tmp;
    }

    template <class T>
    matrix<T> matrix<T>::operator-(const matrix<T> &ot)
    {
        int r = this->row_size(), c = this->column_size();
        matrix<T> tmp(r, c, 0);
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
                tmp.value[i][j] = this->value[i][j] - ot.value[i][j];
        }
        return tmp;
    }

    template <class T>
    matrix<T> matrix<T>::operator*(const matrix<T> &ot)
    {
        if (this->value[0].size() == ot.value.size())
        {
            int times = this->value[0].size();
            int r = this->value.size(), c = ot.value[0].size();
            matrix<T> tmp(r, c, 0);
            for (int i = 0; i < r; i++)
            {
                for (int j = 0; j < c; j++)
                {
                    for (int k = 0; k < times; k++)
                        tmp.value[i][j] += this->value[i][k] * ot.value[k][j];
                }
            }
            return tmp;
        }
        else
            throw "Can't Calculate";
    }

    template <class T>
    matrix<T> matrix<T>::operator*(const T &ot)
    {
        int r = this->row_size(), c = this->column_size();
        matrix<T> tmp(r, c, 0);
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
                tmp.value[i][j] = this->value[i][j] * ot;
        }
        return tmp;
    }

    template <class T>
    matrix<T> matrix<T>::operator/(const T &ot)
    {
        int r = this->row_size(), c = this->column_size();
        matrix<T> tmp(r, c, 0);
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
                tmp.value[i][j] = this->value[i][j] / ot;
        }
        return tmp;
    }

    template <class T>
    matrix<T> &matrix<T>::operator+=(const matrix<T> &ot)
    {
        *this = *this + ot;
        return *this;
    }
    template <class T>
    matrix<T> &matrix<T>::operator-=(const matrix<T> &ot)
    {
        *this = *this - ot;
        return *this;
    }
    template <class T>
    matrix<T> &matrix<T>::operator*=(const matrix<T> &ot)
    {
        *this = *this * ot;
        return *this;
    }
    template <class T>
    matrix<T> &matrix<T>::operator*=(const T &ot)
    {
        *this = *this * ot;
        return *this;
    }

    template <class T>
    matrix<T> matrix<T>::Trans()
    {
        int r = this->value.size(), c = this->value[0].size();
        matrix<T> tmp(c, r, 0);
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
                tmp.value[i][j] = this->value[j][i];
        }
        return tmp;
    }

    template <class T>
    T matrix<T>::det()
    {
        if (this->value.size() == this->value[0].size())
        {
            if (this->value.size() == 2)
                return this->det_diag(1, 1);
            else
            {
                int n = this->value.size();
                matrix<T> b(n - 1, 0);
                for (int i = 0; i < n - 1; i++)
                {
                    for (int j = 0; j < n - 1; j++)
                    {
                        b.value[i][j] = this->det_diag(i + 1, j + 1);
                    }
                }
                return b.det() / pow(this->value[0][0], (n - 2));
            }
        }
        else
            throw "Can't Calculate";
    }

    template <class T>
    T matrix<T>::det_diag(const int &m, const int &n)
    {
        return this->value[0][0] * this->value[m][n] - this->value[0][n] * this->value[m][0];
    }

    template <class T>
    T matrix<T>::M(int r, int c)
    {
        if (this->value.size() == this->value[0].size())
        {
            int n = this->value.size();
            matrix<T> tmp(n - 1, 0);
            for (int i = 0; i < n - 1; i++)
            {
                for (int j = 0; j < n - 1; j++)
                {
                    if (i < r && j < c)
                        tmp.value[i][j] = this->value[i][j];
                    else if (i < r && j >= c)
                        tmp.value[i][j] = this->value[i][j + 1];
                    else if (i >= r && j < c)
                        tmp.value[i][j] = this->value[i + 1][j];
                    else if (i >= r && j >= c)
                        tmp.value[i][j] = this->value[i + 1][j + 1];
                    else
                        ;
                }
            }
            return tmp.det();
        }
        else
            throw "Can't Calculate";
    }

    template <class T>
    T matrix<T>::A(int r, int c)
    {
        return this->M(r, c) * pow(-1, r + c);
    }

    template <class T>
    matrix<T> matrix<T>::adj()
    {
        if (this->value.size() == this->value[0].size())
        {
            int n = this->value.size();
            matrix<T> tmp(n, 0);
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                    tmp.value[i][j] = this->A(i, j);
            }
            return tmp.Trans();
        }
        else
            throw "Can't Calculate";
    }

    template <class T>
    matrix<T> matrix<T>::inverse()
    {
        if (this->value.size() == this->value[0].size())
        {
            if (this->value.size() == 2)
            {
                matrix<T> tmp = *this;
                swap(tmp.value[0][0], tmp.value[1][1]);
                tmp.value[1][0] = -tmp.value[1][0];
                tmp.value[0][1] = -tmp.value[0][1];
                return tmp / this->det();
            }
            else
                return this->adj() / this->det();
        }
        else
            throw "Can't Calculate";
    }

    // QR decomposed
    template <class T>
    class QR
    {
    public:
        matrix<T> Q, R;
    };

    template <class T>
    T dot(vector<T> a, vector<T> b)
    {
        T tmp = 0;
        for (int i = 0; i < a.size(); i++)
            tmp += a[i] * b[i];
        return tmp;
    };

    template <class T>
    vector<T> multiply(T a, vector<T> b)
    {
        vector<T> tmp(b.size(), 0);
        for (int i = 0; i < b.size(); i++)
            tmp[i] = a * b[i];
        return tmp;
    };

    template <class T>
    vector<T> operator-(vector<T> a, vector<T> b)
    {
        vector<T> tmp(a.size(), 0);
        for (int i = 0; i < a.size(); i++)
            tmp[i] = a[i] - b[i];
        return tmp;
    };

    template <class T>
    T vabs(vector<T> v)
    {
        T tmp = 0;
        for (auto i : v)
            tmp += i * i;
        return pow(tmp, 0.5);
    }

    template <class T>
    ostream &operator<<(ostream &output, const vector<T> &v)
    {
        for (auto i : v)
        {
            output << i << " ";
        }
        return output;
    }

    template <class T>
    QR<T> QRdecompose(matrix<T> &A)
    {
        if (A.column_size() == A.row_size())
        {
            QR<T> tmp;
            int n = A.row_size();
            vector<vector<T>> tt;
            matrix<T> e(n, 1), t = A.Trans();

            for (int i = 0; i < n; i++)
            {
                vector<T> a(0), u(0);

                for (auto j : t[i])
                    a.push_back(j);

                u = a;
                if (i != 0)
                {
                    for (int j = 0; j < i; j++)
                        u = u - multiply(dot(a, tt[j]), tt[j]);
                }

                vector<T> v = multiply(1 / vabs(u), u);
                tt.push_back(v);
            }
            e = tt;
            tmp.Q = e.Trans();

            matrix<T> rt(n, 0);
            vector<vector<T>> t2(n, vector<T>(n, 0));
            for (int i = 0; i < n; i++)
            {
                vector<T> a(0);
                for (auto k : t[i])
                    a.push_back(k);

                for (int j = 0; j < i + 1; j++)
                {
                    t2[i][j] = dot(a, e[j]);
                }
            }
            rt = t2;
            tmp.R = rt.Trans();

            return tmp;
        }
        else
            throw "Not a Square Matrix";
    }

    template <class T>
    matrix<T> iterate(matrix<T> &ref, int times)
    {
        int n = ref.row_size();
        matrix<T> A = ref;
        QR<T> tmp;
        for (int i = 0; i < times; i++)
        {
            tmp = QRdecompose(A);
            A = tmp.R * tmp.Q;
        }
        return A;
    }

    template <class T>
    vector<T> EigenValue(matrix<T> &ref)
    {
        int n = ref.row_size();
        vector<T> tmp;
        matrix<T> qrt = iterate(ref, 1000);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                    tmp.push_back(qrt[i][j]);
            }
        }
        return tmp;
    }
}

#endif