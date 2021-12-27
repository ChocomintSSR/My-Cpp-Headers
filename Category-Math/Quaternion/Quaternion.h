#ifndef _QUATERNION_H_
#define _QUATERNION_H_

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <sstream>

namespace chocomint
{
	using std::vector;
	class Vector3D
	{
	private:
		double _x, _y, _z;

	public:
		Vector3D() : _x(0), _y(0), _z(0) {}
		Vector3D(double x, double y, double z) : _x(x), _y(y), _z(z) {}
		double getX() const { return _x; }
		double getY() const { return _y; }
		double getZ() const { return _z; }
		vector<double> getVector() const { return {_x, _y, _z}; }
		double magnitude() const { return std::sqrt(std::pow(_x, 2) + std::pow(_y, 2) + std::pow(_z, 2)); };

		Vector3D operator+(const Vector3D &_ref) { return Vector3D(_x + _ref._x, _y + _ref._y, _z + _ref._z); }
		Vector3D operator-(const Vector3D &_ref) { return Vector3D(_x - _ref._x, _y - _ref._y, _z - _ref._z); }

		Vector3D &operator+=(const Vector3D &_ref);
		Vector3D &operator-=(const Vector3D &_ref);
	};

	inline double dot(const Vector3D &_A, const Vector3D &_B) { return _A.getX() * _B.getX() + _A.getY() * _B.getY() + _A.getZ() * _B.getZ(); }

	Vector3D cross(const Vector3D &_A, const Vector3D &_B)
	{
		double x0 = _A.getY() * _B.getZ() - _B.getY() * _A.getZ();
		double y0 = _B.getX() * _A.getZ() - _A.getX() * _B.getZ();
		double z0 = _A.getX() * _B.getY() - _B.getX() * _A.getY();
		return Vector3D(x0, y0, z0);
	}

	enum imag
	{
		i,
		j,
		k
	};
	class Quaternion
	{
	private:
		double _real;
		Vector3D _imag;

	public:
		Quaternion() : _real(0), _imag(Vector3D()) {}
		Quaternion(double real, double i, double j, double k) : _real(real), _imag(Vector3D(i, j, k)) {}
		Quaternion(double real, Vector3D imagine) : _real(real), _imag(imagine) {}
		double Re() const { return _real; }
		Vector3D Im() const { return _imag; }
		double Im(imag im_part) const { return _imag.getVector()[im_part]; }
		vector<double> getVector() const { return vector<double>{_real, _imag.getX(), _imag.getY(), _imag.getZ()}; }

		double magnitude() const { return std::sqrt(std::pow(_real, 2) + std::pow(_imag.magnitude(), 2)); }
		Quaternion conj() const { return {_real, Vector3D(0, 0, 0) - _imag}; }
	};

	std::string compare(double input, char c)
	{
		std::stringstream ss;
		std::string neg = "-";
		switch (static_cast<int>(input))
		{
		case 1:
			ss << "+" << c;
			break;
		case 0:
			break;
		case -1:
			ss << "-" << c;
			break;
		default:
			ss << (input > 0 ? "+" : "") << input << c;
			break;
		}
		return ss.str();
	}

	std::ostream &operator<<(std::ostream &_os, const Quaternion &_Right)
	{
		_os << _Right.Re() << compare(_Right.Im(imag::i), 'i') << compare(_Right.Im(imag::j), 'j') << compare(_Right.Im(imag::k), 'k');
		return _os;
	}

	Quaternion operator+(const Quaternion &_Left, const Quaternion &_Right) { return Quaternion(_Left.Re() + _Right.Re(), _Left.Im() + _Right.Im()); }
	Quaternion operator+(const double &_Left, const Quaternion &_Right) { return Quaternion(_Left + _Right.Re(), _Right.Im()); }
	Quaternion operator+(const Quaternion &_Left, const double &_Right) { return Quaternion(_Left.Re() + _Right, _Left.Im()); }

	Quaternion operator-(const Quaternion &_Left, const Quaternion &_Right) { return Quaternion(_Left.Re() - _Right.Re(), _Left.Im() - _Right.Im()); }
	Quaternion operator-(const double &_Left, const Quaternion &_Right) { return Quaternion(_Left - _Right.Re(), Vector3D(0, 0, 0) - _Right.Im()); }
	Quaternion operator-(const Quaternion &_Left, const double &_Right) { return Quaternion(_Left.Re() - _Right, _Left.Im()); }
}

#endif // _QUATERNION_H_