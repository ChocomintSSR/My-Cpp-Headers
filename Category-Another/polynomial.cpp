#include <iostream>
#include "..\0_GitHub\Matrix.h"
#include "..\0_GitHub\complex.h"
using namespace std;
using namespace chocomint;

int main()
{
    vector<complex> c = {1, 1, 1}, tmp;
    vector<vector<complex>> mat;

    for (int i = 0; i < c.size() - 1; i++)
    {
        for (int j = 0; j < c.size(); j++)
        {
            if (j == i + 1)
                tmp.push_back(1);
            else
                tmp.push_back(0);
        }
        mat.push_back(tmp);
        tmp.clear();
    }
    for (auto k : c)
        tmp.push_back(0 - k);
    mat.push_back(tmp);

    matrix<complex> x;
    x = mat;

    cout << EigenValue(x);
}
