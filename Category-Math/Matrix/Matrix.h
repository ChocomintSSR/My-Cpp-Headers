#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <cmath>
#include <vector>
#include <complex>

#if __has_include("vector_calculate.h")
#include "vector_calculate.h"
#else
#error "cannot find vector_calculate.h"
#endif

#define iterate 1000

typedef std::complex<double> Complex;
typedef std::vector<std::vector<Complex>> Matrix;

namespace std
{
    ostream &operator<<(ostream &_output, const Complex _ref)
    {
        char symbol[2] = {'+', '-'};

        if (_ref.real())
        {
            if (abs(_ref.imag()) == 1)
                _output << _ref.real() << " " << symbol[(_ref.imag() < 0)] << " i";
            else
            {
                if (_ref.imag())
                    _output << _ref.real() << " " << symbol[(_ref.imag() < 0)] << " " << abs(_ref.imag()) << "i";
                else
                    _output << _ref.real();
            }
        }
        else
        {
            switch (static_cast<int>(_ref.imag()))
            {
            case 1:
                _output << "i";
                break;
            case 0:
                _output << 0;
                break;
            case -1:
                _output << "-i";
                break;
            default:
                _output << _ref.imag() << "i";
                break;
            }
        }
        return _output;
    }

    ostream &operator<<(ostream &_output, const Matrix &_ref)
    {
        for (auto i : _ref)
        {
            for (auto j : i)
                _output << j << " ";
            _output << "\n";
        }
        return _output;
    }

    Matrix Trans(Matrix &_ref)
    {
        int r = _ref.size(), c = _ref[0].size();
        Matrix tmp(c, vector<Complex>(r, 0));
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
                tmp[i][j] = _ref[j][i];
        }
        return tmp;
    }

    Matrix operator+(const Matrix &_this, const Matrix &_other)
    {
        if (_this.size() == _other.size() && _this[0].size() == _other[0].size())
        {
            int size = _this.size();
            Matrix tmp(size, vector<Complex>(size, 0));
            for (int i = 0; i < size; i++)
            {
                for (int j = 0; j < size; j++)
                    tmp[i][j] = _this[i][j] + _other[i][j];
            }
            return tmp;
        }
        else
            throw "The size of these two matrixes are NOT the same.";
    }

    Matrix operator-(const Matrix &_this, const Matrix &_other)
    {
        if (_this.size() == _other.size() && _this[0].size() == _other[0].size())
        {
            int size = _this.size();
            Matrix tmp(size, vector<Complex>(size, 0));
            for (int i = 0; i < size; i++)
            {
                for (int j = 0; j < size; j++)
                    tmp[i][j] = _this[i][j] - _other[i][j];
            }
            return tmp;
        }
        else
            throw "The size of these two matrixes are NOT the same.";
    }

    Matrix operator*(const Matrix &_this, const Matrix &_other)
    {
        if (_this[0].size() == _other.size())
        {
            int row = _this.size(), col = _other[0].size(), n = _this[0].size();
            Matrix tmp(row, vector<Complex>(col, 0));
            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < col; j++)
                {
                    for (int k = 0; k < n; k++)
                        tmp[i][j] += _this[i][k] * _other[k][j];
                }
            }
            return tmp;
        }
        else
            throw "Cannot Calculate it.";
    }

    Matrix operator*(const Complex &_comp, const Matrix &_ref)
    {
        Matrix tmp(_ref.size(), vector<Complex>(_ref[0].size(), 0));
        for (int i = 0; i < _ref.size(); i++)
        {
            for (int j = 0; j < _ref.size(); j++)
                tmp[i][j] = _comp * _ref[i][j];
        }
        return tmp;
    }
    Matrix operator*(const Matrix &_ref, const Complex &_comp)
    {
        Matrix tmp(_ref.size(), vector<Complex>(_ref[0].size(), 0));
        for (int i = 0; i < _ref.size(); i++)
        {
            for (int j = 0; j < _ref.size(); j++)
                tmp[i][j] = _comp * _ref[i][j];
        }
        return tmp;
    }

    class QR
    {
    public:
        Matrix Q, R;
    };

    QR QRdecompose_R(Matrix &_ref) // correct in R
    {
        if (_ref.size() == _ref[0].size())
        {
            QR tmp;
            int size = _ref.size();
            Matrix e, result(size, vector<Complex>(size, 0)), matrix_tmp = Trans(_ref);

            vector<Complex> a, u;
            for (int i = 0; i < size; i++)
            {
                a = matrix_tmp[i];
                u = a;
                if (i != 0)
                {
                    for (int j = 0; j < i; j++)
                        u = u - dot(a, e[j]) * e[j];
                }

                e.push_back(u / vabs(u));
            }
            tmp.Q = Trans(e);

            Matrix t2(size, vector<Complex>(size, 0));
            for (int i = 0; i < size; i++)
            {
                Matrix tr = Trans(_ref);
                for (int j = i; j < size; j++)
                    t2[i][j] = dot(tr[j], e[i]);
            }
            tmp.R = t2;

            return tmp;
        }
        else
            throw "Not a Square Matrix.";
    }

    void Householder()
    {}

    vector<Complex> EigenValue(Matrix &_ref)
    {
        QR qr;
        Matrix tmp = _ref;
        for (int i = 0; i < iterate; i++)
        {
            qr = QRdecompose_R(tmp);
            tmp = qr.R * qr.Q;
        }
        vector<Complex> result;
        for (int i = 0; i < _ref.size(); i++)
            result.push_back(tmp[i][i]);
        return result;
    }

}

#endif