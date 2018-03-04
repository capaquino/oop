#include "rational.hpp"
#include <numeric>
#include <iostream>


// Dr. Sutton,
// Is this okay? As in, simplify() is only ever being used to simplify the
// Rational's _num and _den, but I feel like not including parameters is bad
// style or less readable.
void Rational::simplify()
{
    int gcd = std::gcd(_num, _den);
    _num = _num/gcd;
    _den = _den/gcd;
}

// 1. Only allow the creation of valid rational numbers
Rational::Rational(int n, int d)
{
    if (d == 0)
    {
        throw;
    }

    _num = n;
    _den = d;
    simplify();
}

bool Rational::operator==(Rational r)
{
    return _num == r._num && _den == r._den;
}

bool Rational::operator!=(Rational r)
{
    return !(*this == r);
}

// Pretty neat, don't remember learning this before.
// http://www.themathpage.com/arith/compare-fractions-2.htm
bool Rational::operator<(Rational r)
{
    int left = _num * r._den;
    int right = r._num * _den;
    return left < right;
}

// same code as operator<
bool Rational::operator>(Rational r)
{
    int left = _num * r._den;
    int right = r._num * _den;
    return left > right;
}

bool Rational::operator<=(Rational r)
{
    return *this < r || *this == r;
}

bool Rational::operator>=(Rational r)
{
    return *this > r || *this == r;
}

bool Rational::operator+(Rational r)
{

}

bool Rational::operator-(Rational r)
{

}

bool Rational::operator*(Rational r)
{

}

bool Rational::operator/(Rational r)
{

}

std::istream& operator>>(std::istream &in, Rational &r)
{

}

std::ostream& operator<<(std::ostream &out, const Rational &r)
{
    if (r._den == 1)
        out << r._num;
    else
        out << r._num << "/" << r._den;
    return out;
}
