#ifndef _FILE_EX_
#define _FILE_EX_

#include <iostream>
#include <vector>
#include <string>
#include "stringEX.h"
#include <fstream>

namespace std
{
    vector<vector<stringEX>> read_csv(const char *Filename)
    {
        stringEX file_name = Filename;
        vector<vector<stringEX>> tmp{};
        if (file_name.split(".").back() == "csv")
        {
            //file_name.erase(file_name.end() - 4, file_name.end());
            //cout << file_name << "\n";
            ifstream is;
            is.open(file_name);
            stringEX s_tmp;
            while (getline(is, s_tmp))
                tmp.push_back(s_tmp.split(","));
        }
        return tmp;
    }
}

#endif