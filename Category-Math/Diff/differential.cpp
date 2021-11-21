#include <iostream>
#include <sstream>
#include <algorithm>
#include <stack>
#include <string>
using namespace std;

bool isNumber(const string &str)
{
	string sstr = ((str[0] == '-') ? str.substr(1, str.size() - 1) : str);
	sstr.find_first_not_of("0123456789.") == string::npos;
}

string polynomial_diff(string _poly)
{
	stringstream out;

	int x_pos = _poly.find("x^");
	if (x_pos == -1) // not polynomial
		return "Not a polynomial";

	string coeff = _poly.substr(0, x_pos);
	string tmp = _poly.substr(x_pos + 2, _poly.size() - x_pos);

	if (isNumber(tmp))
		out << ((coeff == "") ? 1 : stod(coeff)) * stod(tmp) << "x^" << stod(tmp) - 1;
	else
		return "Not a polynomial";

	return out.str();
}

string diff(string formula)
{
	stack<char> bracket;
	bool dif;
	int size = formula.size(), flag = 0;

	for (int i = 0; i <= size; i++)
	{
		if (formula[i] == '(')
		{
			for (;; i++)
			{
				if (formula[i] == '(')
					bracket.push('(');
				else if (formula[i] == ')')
					bracket.pop();

				if (bracket.empty() && (formula[i] == '+' || formula[i] == '\0'))
					break;
			}

			dif = true;
		}
		else
			dif = (formula[i] == '+');

		if (dif || i == size)
		{
			// differential
			cout << formula.substr(flag, i - flag) << "\n";

			flag = i + 1;
		}
	}
	return formula;
}

int main()
{
	string f = "2x^3+sin(x)";
	diff(f);

	return 0;
}
