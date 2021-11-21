#include <iostream>
#include "stringEX.h"
#include <bitset>
#include <fstream>
using namespace std;

ofstream os;
ifstream is;

int main()
{
    stringEX file_name, tmp;
    int n;
    cin >> file_name;
    cin >> n;
    is.open(file_name + ".txt");
    os.open(file_name + "-encode.txt");
    stringEX ns = to_string(n);
    os << base64_encode("base64") << " " << base64_encode(ns) << "\n";
    while (getline(is, tmp))
        os << base64_encode(tmp, n) << "\n";
    os.close();
    is.close();

    return 0;
}
