#include <iostream>
#include <fstream>
#include "stringEX.h"
#include <vector>
using namespace std;

int main()
{
    ifstream read;
    ofstream output;
    string s;
    vector<stringEX> data;

    // 1.Read the file.
    read.open("code.txt");
    while (getline(read, s))
        data.push_back(s);

    // 2.Detect the keywords
    const struct keywords
    {
        const vector<stringEX> green = {"BigInt", "std", "chocomint"};
        const vector<stringEX> dark_blue = {"int", "namespace"};
        const vector<stringEX> blue = {"bi", "cout"};
        const vector<stringEX> function = {"main"};
        const vector<stringEX> _using = {"#include", "using", "return"};
    } key;

    output.open("code-html.txt");
    for (auto i : data)
    {
        for (auto g : key.green)
        {
            int flag = 0;
            while (true)
            {
                int find_pos = i.find(g, flag);
                if (find_pos != string::npos)
                {
                    stringEX ts = "<span xxx=\"code-xxx\">"; // avoid repeated "class"
                    stringEX end = "</span>";
                    int tmp_size = find_pos + ts.size() + g.size() + 1;
                    i.insertEX(find_pos + 1, ts);
                    i.insertEX(tmp_size, end);
                    flag = tmp_size;
                }
                else
                    break;
            }
        }
        for (auto db : key.dark_blue)
        {
            int flag = 0;
            while (true)
            {
                int find_pos = i.find(db, flag);
                if (find_pos != string::npos)
                {
                    stringEX ts = "<span xxx=\"code-type\">";
                    stringEX end = "</span>";
                    int tmp_size = find_pos + ts.size() + db.size() + 1;
                    i.insertEX(find_pos + 1, ts);
                    i.insertEX(tmp_size, end);
                    flag = tmp_size;
                }
                else
                    break;
            }
        }
        for (auto b : key.blue)
        {
            int flag = 0;
            while (true)
            {
                int find_pos = i.find(b, flag);
                if (find_pos != string::npos)
                {
                    stringEX ts = "<span xxx=\"code-var\">";
                    stringEX end = "</span>";
                    int tmp_size = find_pos + ts.size() + b.size() + 1;
                    i.insertEX(find_pos + 1, ts);
                    i.insertEX(tmp_size, end);
                    flag = tmp_size;
                }
                else
                    break;
            }
        }
        for (auto f : key.function)
        {
            int flag = 0;
            while (true)
            {
                int find_pos = i.find(f, flag);
                if (find_pos != string::npos)
                {
                    stringEX ts = "<span xxx=\"code-func\">";
                    stringEX end = "</span>";
                    int tmp_size = find_pos + ts.size() + f.size() + 1;
                    i.insertEX(find_pos + 1, ts);
                    i.insertEX(tmp_size, end);
                    flag = tmp_size;
                }
                else
                    break;
            }
        }
        for (auto u : key._using)
        {
            int flag = 0;
            while (true)
            {
                int find_pos = i.find(u, flag);
                if (find_pos != string::npos)
                {
                    stringEX ts = "<span xxx=\"code-uuu\">";
                    stringEX end = "</span>";
                    int tmp_size = find_pos + ts.size() + u.size() + 1;
                    i.insertEX(find_pos + 1, ts);
                    i.insertEX(tmp_size, end);
                    flag = tmp_size;
                }
                else
                    break;
            }
        }
        i.replaceAll("xxx", "class");
        i.replaceAll("uuu", "using");
        output << i << "\n";
    }

    cout << "Finished.\n";
    read.close();
    output.close();

    return 0;
}