#ifndef _UNIT_H_
#define _UNIT_H_

#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>

namespace std
{
    class reference_unit
    {
    };

    template <int amount> // amount == _unit_names.size() == _unit_values.size() - 1
    class unit
    {
    private:
        vector<string> _unit_names;  // sec, min, ...
        vector<double> _unit_ref;    // 60, ...
        vector<double> _unit_values; // 2 (sec)

    public:
        unit();
        unit(vector<string> unit_names, vector<double> unit_values) : _unit_names(unit_names), _unit_values(unit_values) {}
        unit(initializer_list<string> unit_names, initializer_list<double> unit_values) : _unit_names(unit_names.begin(), unit_names.end()), _unit_values(unit_values.begin(), unit_values.end()) {}

        vector<string> get_unit_names() const { return _unit_names; }
        vector<double> get_unit_values() const { return _unit_values; }

        double to_value(char *_Unit);
    };

    template <int amount>
    ostream &operator<<(ostream &_os, const unit<amount> &_u)
    {
        for (int i = 0; i < _u.get_unit_names().size(); i++)
        {
        }
    }

    template <int amount>
    double unit<amount>::to_value(char *_Unit)
    {
        auto container = this->_unit_names;
        auto pos = find(container.begin(), container.end(), _Unit);
        if (pos == container.end())
        {
            cout << "[Warning!] " << string("There is no \"") + _Unit + "\" unit in the list.\n";
            return -1;
        }
        else
        {
            int index = pos - container.begin();
            cout << index;
            return 0;
        }
    }
}

#endif