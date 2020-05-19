#include "complex.hpp"
#include <iostream>
#include <cmath>

double Complex::re() const {
	return _re;
}

double Complex::amp() const {
	return sqrt(_re * _re + _im * _im);
}

double Complex::phase() const {
	if (_re == 0);
		if (_im == 0)
			return 0;
		else  if (_im > 0)
			return M_PI/2;
		else 
			return -M_PI/2;
	if (_re > 0)
		return atan(_im/_re);
	else
		if (_im >= 0)
			return atan(_im/_re) + M_PI;
	return atan(_im/_re) - M_PI;
}

Complex Complex::operator * (double re) const {
	Complex obj;
	obj._re += _re * re;
	obj._im += _im * re;
	return obj;
}

Complex Complex::operator / (double re) const {
	Complex obj;
	obj._re += _re / re;
	obj._im += _im / re;
	return obj;
}

Complex Complex::operator ^ (double alpha) const {
	Complex obj(_re, _im);
	obj._re = this -> amp() * cos(this -> phase() + alpha);
	obj._im = this -> amp() * sin(this -> phase() + alpha);
	return obj;
}

Complex Complex::operator + (Complex object) const {
	Complex obj;
	obj._re += _re + object._re;
	obj._im += _im + object._im;
	return obj;
}

Complex Complex::operator - (Complex object) const {
	Complex obj;
	obj._re += _re - object._re;
	obj._im += _im - object._im;
	return obj;
}

Complex& Complex::operator = (const Complex &object) {
	_re = object._re;
	_im = object._im;
	return *this;
}

Complex& Complex::operator += (const Complex &object) {
	_re += object._re;
	_im += object._im;
	return *this;
}

std::ostream& operator << (std::ostream& out, const Complex& object) {
	if (object._im < 0)
		std::cout << object._re << object._im << "i\n";
	else
		std::cout << object._re << " + " << object._im << "i\n";
	return out;
}

std::istream& operator >> (std::istream& in, Complex& object) {
	std::cout << "Enter real Complex number:";
	in >> object._re;
	std::cout << "\nEnter imaginary complex number:";
	in >> object._im;
	std::cout << '\n';
	return in;
}