#ifndef _JSON_H_
#define _JSON_H_

#include <iostream>
#include <fstream>
#include <vector>
#include <typeinfo>
#include <utility>
#include <tuple>

namespace chocomint
{
    using std::cout;
    using std::string, std::vector, std::tuple;

    template <class... value_type>
    class json
    {
    private:
        vector<void *> data_list;
        vector<string> type_list;

    public:
        json();
        json(std::pair<string, value_type>... initialize)
        {
            // ((cout << initialize.first << " "), ...);
            tuple<value_type...> tmp = {initialize.second...};
            auto val = tmp;
        }
    };
}

#endif
