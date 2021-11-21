// infix to postfix
#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;

// template <class T>
// void print_stack(stack<T> &q)
// {
// 	stack<T> tmp = q;
// 	while (tmp.empty() != true)
// 	{
// 		cout << tmp.top();
// 		tmp.pop();
// 	}
// }

bool compare(char stack_o, char infix_o)
{
	string infix_priority = ")+-*/^ (";
	string stack_priority = "(+-*/^ ";
	// stack >= infix --> return true
	return (stack_priority.find(stack_o) >= infix_priority.find(infix_o));
}

int main()
{
	stack<char> t;
	string result, formula = "(1+2)*4+5/(6+1*4)+3";
	cout << formula << "\n";
	for (auto i : formula)
	{
		switch (i)
		{
		// 輸入為)，則輸出堆疊內運算子，直到堆疊內為(
		case ')':
			while (t.top() != '(')
			{
				result += t.top();
				t.pop();
			}
			t.pop();
			break;

		/* 
			輸入為運算子，若小於TOP在堆疊中所指運算子，
			則將堆疊所指運算子輸出，若大於等於TOP在堆疊
			中所指運算子，則將輸入之運算子放入堆疊
		*/
		case '(':
		case '^':
		case '*':
		case '/':
		case '+':
		case '-':
			if (t.empty() == false)
			{
				while (compare(t.top(), i) == true)
				{
					result += t.top();
					t.pop();
					if (t.empty() == true)
						break;
				}
			}
			t.push(i);
			break;

		default:
			result += i;
			break;
		}
	}
	while (t.size() != 0)
	{
		result += t.top();
		t.pop();
	}
	cout << result << "\n";

	return 0;
}