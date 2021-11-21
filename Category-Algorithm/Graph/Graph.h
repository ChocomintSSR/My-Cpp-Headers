#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <iostream>
#include <vector>
#include <utility>

namespace chocomint
{
    using std::cout;
    using std::vector;

    template <class T>
    class path_data
    {
    private:
        int start, end;
        T data;

    public:
        path_data();
        path_data(int _st, int _en, T _data)
        {
            this->start = _st;
            this->end = _en;
            this->data = _data;
        }
        int get_start() { return this->start; }
        int get_end() { return this->end; }
        T get_data() { return this->data; }
    };

    template <class T>
    path_data<T> make_path(int _st, int _en, T _data)
    {
        path_data<T> tmp(_st, _en, _data);
        return tmp;
    }

    // ============================== //

    template <class T>
    class graph
    {
    private:
        T zero_element;
        vector<vector<T>> graph_matrix;

    public:
        graph() { zero_element = 0; }

        void set_zero(T _z);
        void add(path_data<T> _pd);
        void add_doubly(path_data<T> _pd);
        T get_path_value(int from, int to);
        vector<vector<T>> get_graph();

        int in_degree(int number);
        int out_degree(int number);
    };

    template <class T>
    std::ostream &operator<<(std::ostream &_os, graph<T> &ref_graph)
    {
        for (auto i : ref_graph.get_graph())
        {
            for (auto j : i)
                _os << "[" << j << "] ";
            _os << "\n";
        }
        return _os;
    }

    template <class T>
    void graph<T>::set_zero(T _z)
    {
        this->zero_element = _z;
    }

    template <class T>
    void graph<T>::add(path_data<T> _pd)
    {
        int size = std::max(_pd.get_start(), _pd.get_end()), this_size = this->graph_matrix.size();
        if (size + 1 > this_size)
        {
            vector<T> tmp2;
            for (int i = 0; i <= size; i++)
                tmp2.push_back(this->zero_element);

            for (int i = 0; i < this_size; i++)
            {
                for (int j = this_size; j <= size; j++)
                    this->graph_matrix[i].push_back(this->zero_element);
            }
            for (int i = this_size; i <= size; i++)
                this->graph_matrix.push_back(tmp2);
        }
        this->graph_matrix[_pd.get_start()][_pd.get_end()] = _pd.get_data();
    }
    template <class T>
    void graph<T>::add_doubly(path_data<T> _pd)
    {
        add(_pd);
        path_data<T> tmp(_pd.get_end(), _pd.get_start(), _pd.get_data());
        add(tmp);
    }

    template <class T>
    T graph<T>::get_path_value(int from, int to)
    {
        return this->graph_matrix[from][to];
    }

    template <class T>
    vector<vector<T>> graph<T>::get_graph()
    {
        return this->graph_matrix;
    }

    template <class T>
    int graph<T>::in_degree(int number)
    {
        int in = 0;
        for (int i = 0; i < this->graph_matrix.size(); i++)
        {
            in += (this->graph_matrix[i][number] == this->zero_element) ? 0 : 1;
        }
        return in;
    }

    template <class T>
    int graph<T>::out_degree(int number)
    {
        int out = 0;
        for (auto i : this->graph_matrix[number])
            out += (i == this->zero_element) ? 0 : 1;
        return out;
    }
}

#endif