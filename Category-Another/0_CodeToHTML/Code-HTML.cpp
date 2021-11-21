#include <iostream>
#include <fstream>
#include "..\0_GitHub\stringEX.h"
using namespace std;

int main()
{
	ifstream is;
	ofstream os;
	string keyword_list[5] = {"green", "dark_blue", "blue", "yellow", "purple"};
	is.open("code.txt");

	stringEX code_line;
	vector<stringEX> code;
	while (getline(is, code_line))
		code.push_back(code_line);
	is.close();

	for (auto i : code)
	{
		cout << i << " - line:\n";
		for (int key = 0; key < 5; key++)
		{
			is.open("keywords\\" + keyword_list[key]);
			stringEX tmp;
			while (getline(is, tmp))
			{
				cout << tmp << " -> " << i.find(tmp) << "\n";
			}
			is.close();
		}
		cout << "\n";
	}

	return 0;
}
