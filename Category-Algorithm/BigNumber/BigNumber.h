#ifndef _BIGNUMBER_
#define _BIGNUMBER_

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <typeinfo>

namespace chocomint
{
	class BigInt
	{
	private:
		std::vector<int> container;
		bool positive;
		int at(int index) { return this->container[index]; }

	public:
		friend BigInt operator""_BigInt(const char *val, size_t size);

		BigInt() {}
		template <class T>
		BigInt(const T &val);

		// Get digit from index
		int operator[](int index) { return this->container[this->container.size() - index]; }
		std::size_t length() { return this->container.size(); }
		std::vector<int> get_container() { return this->container; }
		bool is_positive() { return this->positive; }

		BigInt operator<<(const int &dp);
		void operator<<=(const int &dp);
		void operator=(const BigInt &ref);

		BigInt operator+(const BigInt &ref);
		BigInt operator-(const BigInt &ref);
		BigInt operator*(const int &ref);
		BigInt operator*(const BigInt &ref);
		BigInt operator^(const int &ref);
		// I need to write a divide(/) & remainder(%) function

		void operator++(int);
		void operator--(int);
		void operator+=(const BigInt &ref);
		void operator-=(const BigInt &ref);

		bool operator==(const BigInt &ref);
		bool operator!=(const BigInt &ref);
		bool operator>(const BigInt &ref);
		bool operator<(const BigInt &ref);
		bool operator>=(const BigInt &ref);
		bool operator<=(const BigInt &ref);

		std::string base(int base);
	};

	std::ostream &operator<<(std::ostream &os, BigInt &value)
	{
		if (value.is_positive() == false)
			os << "-";
		int n = value.get_container().size();
		for (int i = n - 1; i >= 0; i--)
			os << value.get_container()[i];
		return os;
	}

	// =============== displacement & assignment =============== //

	template <class T>
	BigInt::BigInt(const T &val)
	{
		if (typeid(T).name() != typeid(int).name() && typeid(T).name() != typeid(long long).name())
			throw "Not Integer";
		std::string s = std::to_string(val);
		if (val < 0)
		{
			this->positive = false;
			s.erase(s.begin());
		}
		else
			this->positive = true;
		for (int i = s.size() - 1; i >= 0; i--)
			this->container.push_back(s[i] - '0');
	}

	// 10^dp
	BigInt BigInt::operator<<(const int &dp)
	{
		BigInt tmp;
		tmp.positive = this->positive;
		for (int i = 0; i < dp; i++)
			tmp.container.push_back(0);
		for (int i = 0; i < this->container.size(); i++)
			tmp.container.push_back(this->container[i]);
		*this = tmp;
	}
	// 10^dp
	void BigInt::operator<<=(const int &dp)
	{
		*this = ((*this) << dp);
	}

	BigInt operator""_BigInt(const char *val, size_t size) // size_t must be exist!
	{
		BigInt tmp;
		for (int i = size - 1; i >= 0; i--)
		{
			if (i == 0 && val[i] == '-')
				tmp.positive = false;
			else
			{
				tmp.positive = true;
				int n = val[i] - '0';
				if (n < 0 || n > 9)
					throw "Not a Number";
				else
					tmp.container.push_back(n);
			}
		}
		return tmp;
	}

	void BigInt::operator=(const BigInt &ref)
	{
		BigInt tmp;
		this->container.clear();
		for (auto i : ref.container)
			this->container.push_back(i);
		this->positive = ref.positive;
	}

	// =================== basic  operation ==================== //

	BigInt BigInt::operator+(const BigInt &ref)
	{
		BigInt tmp;
		if (this->positive == true && ref.positive == false)
		{
			BigInt r = ref;
			r.positive = true;
			tmp = *this - r;
		}
		else if (this->positive == false && ref.positive == true)
		{
			BigInt t = *this;
			BigInt r = ref;
			t.positive = true;
			tmp = r - t;
		}
		else // 2(+) or 2(-)
		{
			BigInt t = *this, r = ref;
			bool neg;
			if (this->positive == false && ref.positive == false)
				neg = true;
			t.positive = true;
			r.positive = true;
			int flag = 0, add, n = std::max(t.container.size(), r.container.size());
			for (int i = 0; i < n; i++)
			{
				add = ((i >= t.length()) ? 0 : t.at(i)) + ((i >= r.container.size()) ? 0 : r.container[i]) + flag;
				if (add >= 10)
				{
					add -= 10;
					flag = 1;
				}
				else
					flag = 0;
				tmp.container.push_back(add);
			}
			if (flag == 1)
				tmp.container.push_back(1);
			if (neg == true)
				tmp.positive = false;
		}
		return tmp;
	}

	BigInt BigInt::operator-(const BigInt &ref)
	{
		BigInt tmp, t = *this /* [th] can be modified */, r = ref;
		int n = std::max(t.container.size(), r.container.size());
		if (t.positive == true && r.positive == true)
		{
			// subtract with borrow
			for (int i = 0; i < n; i++)
			{
				int former = (i >= t.container.size()) ? 0 : t.container[i];
				int later = (i >= r.container.size()) ? 0 : r.container[i];
				if (former >= later)
					tmp.container.push_back(former - later);
				else
				{
					tmp.container.push_back(10 + former - later);
					// borrow
					for (int j = i + 1;; j++)
					{
						former = t.container[j];
						later = r.container[j];
						if (former = 0)
							t.container[j] = 9;
						else
						{
							t.container[j] -= 1;
							break;
						}
					}
				}
			}
		}
		return tmp;
	}

	// single digit multiply
	BigInt BigInt::operator*(const int &ref)
	{
		BigInt tmp;
		if (ref > 0 && ref <= 9)
		{
			int flag = 0, n = this->container.size(), m;
			for (int i = 0; i < n; i++)
			{
				m = this->container[i] * ref + flag;
				flag = floor(m / 10);
				m = m - (flag * 10);
				tmp.container.push_back(m);
			}
			if (flag != 0)
				tmp.container.push_back(flag);
			tmp.positive = true;
		}
		else
			throw "This function only allow the single digit number";
		return tmp;
	}

	BigInt BigInt::operator*(const BigInt &ref)
	{
		BigInt tmp = 0;
		int n = ref.container.size();
		for (int i = 0; i < n; i++)
		{
			BigInt m = (*this) * ref.container[i];
			m << i;
			if (i == 0)
				tmp = m;
			else
				tmp += m;
		}
		return tmp;
	}

	// int power
	BigInt BigInt::operator^(const int &ref)
	{
		BigInt tmp = 1;
		for (int i = 0; i < ref; i++)
			tmp = tmp * (*this);
		return tmp;
	}

	// ============== operation with assignment =============== //

	void BigInt::operator++(int)
	{
		*this = *this + (BigInt)1;
	}

	void BigInt::operator--(int)
	{
		*this = *this - (BigInt)1;
	}

	void BigInt::operator+=(const BigInt &ref)
	{
		*this = *this + ref;
	}

	void BigInt::operator-=(const BigInt &ref)
	{
		*this = *this - ref;
	}

	// ======================= compare ======================== //

	bool BigInt::operator==(const BigInt &ref)
	{
		int n1 = this->container.size(), n2 = ref.container.size();
		if (n1 != n2)
			return false;
		else
		{
			for (int i = 0; i < n1; i++)
			{
				if (this->container[i] != ref.container[i])
					return false;
			}
			return true;
		}
	}
	bool BigInt::operator!=(const BigInt &ref)
	{
		return !(*this == ref);
	}
	bool BigInt::operator>(const BigInt &ref)
	{
		int n1 = this->container.size(), n2 = ref.container.size();
		if (n1 > n2)
			return true;
		else
		{
			for (int i = n1 - 1; i >= 0; i--)
			{
				if (this->container[i] > ref.container[i])
					return true;
			}
			return false;
		}
	}
	bool BigInt::operator<(const BigInt &ref)
	{
		BigInt t = ref;
		return (t > *this);
	}
	bool BigInt::operator>=(const BigInt &ref)
	{
		return !(*this < ref);
	}
	bool BigInt::operator<=(const BigInt &ref)
	{
		return !(*this > ref);
	}

	std::string BigInt::base(int base)
	{
		std::string tmp;
		*this;
	}
}

#endif