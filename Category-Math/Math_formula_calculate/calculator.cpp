#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

string operators = "()[]{}+-*/^";

bool in(char c, string s)
{
	for (auto i : s)
	{
		if (c == i)
			return true;
	}
	return false;
}

template <class T>
ostream &operator<<(ostream &_os, stack<T> q)
{
	stack<T> tmp = q;
	while (tmp.empty() != true)
	{
		_os << tmp.top() << " ";
		tmp.pop();
	}
	return _os;
}

bool compare(char stack_o, char infix_o)
{
	string infix_priority = ")]}+-*/^ ([{";
	string stack_priority = "([{+-*/^ ";
	// stack >= infix --> return true
	return (stack_priority.find(stack_o) >= infix_priority.find(infix_o));
}

stack<string> infix_to_postfix(string &infix)
{
	char past;
	stack<char> op;
	stack<string> postfix;
	for (auto i : infix)
	{
		cout << i << "\n";
		switch (i)
		{
		// 輸入為)，則輸出堆疊內運算子，直到堆疊內為(
		case ')':
			while (op.top() != '(')
			{
				string x;
				x += op.top();
				postfix.push(x);
				op.pop();
			}
			op.pop();
			break;
		case ']':
			while (op.top() != '[')
			{
				string x;
				x += op.top();
				postfix.push(x);
				op.pop();
			}
			op.pop();
			break;
		case '}':
			while (op.top() != '{')
			{
				string x;
				x += op.top();
				postfix.push(x);
				op.pop();
			}
			op.pop();
			break;

		/* 
			輸入為運算子，若小於TOP在堆疊中所指運算子，
			則將堆疊所指運算子輸出，若大於等於TOP在堆疊
			中所指運算子，則將輸入之運算子放入堆疊
		*/
		case '(':
		case '[':
		case '{':
		case '^':
		case '*':
		case '/':
		case '+':
		case '-':
			if (op.empty() == false)
			{
				while (compare(op.top(), i) == true)
				{
					string x;
					x += op.top();
					postfix.push(x);
					op.pop();
					if (op.empty() == true)
						break;
				}
			}
			op.push(i);
			break;

		default:
			if (!in(past, operators))
				postfix.top() += i;
			else
			{
				string x;
				x += i;
				postfix.push(x);
			}
			break;
		}
		past = i;
	}
	while (op.size() != 0)
	{
		string x;
		x += op.top();
		postfix.push(x);
		op.pop();
	}
	return postfix;
}
stack<string> infix_to_postfix(const char *infix)
{
	string in = infix;
	return infix_to_postfix(in);
}

template <class T>
void reverseStack(stack<T> &s)
{
	T item;
	stack<T> tmpStack;

	while (s.empty() == false)
	{
		item = s.top();
		s.pop();
		tmpStack.push(item);
	}

	s = tmpStack;
	return;
}

double basic_calculator(double first_val, double second_val, char op)
{
	double res;
	switch (op)
	{
	case '+':
		res = first_val + second_val;
		break;
	case '-':
		res = first_val - second_val;
		break;
	case '*':
		res = first_val * second_val;
		break;
	case '/':
		res = first_val / second_val;
		break;
	case '^':
		res = pow(first_val, second_val);
		break;

	default:
		res = 0;
		break;
	}
	return res;
}

double compute(stack<string> postfix)
{
	reverseStack(postfix);
	stack<string> tmp = postfix;
	stack<double> element;
	while (tmp.empty() != true)
	{
		if (tmp.top().length() != 1 || !in(tmp.top()[0], operators))
		{
			element.push(stod(tmp.top()));
			tmp.pop();
		}
		else
		{
			if (element.empty() == false)
			{
				// get 2 toppest element
				double second = element.top();
				element.pop();
				double first = element.top();
				element.pop();

				element.push(basic_calculator(first, second, tmp.top()[0]));
				tmp.pop();
			}
		}
	}
	reverseStack(postfix);
	return element.top();
}

int main()
{
	string formula = "{[1+(2.27*32/5+14)*33]+92*7}/20";
	cout << compute(infix_to_postfix(formula));
	return 0;
}
