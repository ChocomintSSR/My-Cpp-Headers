#include <iostream>

template <class... Args>
void print(Args... args)
{
    (std::cout << ... << args) << "\n";
}

int main()
{
    print(1, ':', " Hello", ',', " ", "World!");
    return 0;
}