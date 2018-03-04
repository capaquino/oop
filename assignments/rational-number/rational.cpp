#include "rational.hpp"
#include <numeric>
#include <iostream>
#include <vector>

void Rational::simplify()
{
    // simplfy
    int gcd = std::gcd(_num, _den);
    _num = _num/gcd;
    _den = _den/gcd;

    // signify
    // ^ ~~~~~ pronounced SIGN as in "sign", I as in "it", and FY as in "Wi-Fi"
    // if den is below zero and num is positive, move negative sign to top
    // if both num and den are neg, get rid of negative signs;
    if ((_num > 0 && _den < 0) ||
        (_num < 0 && _den < 0))
    {
        _num = -_num;
        _den = -_den;
    }

}

// Can compare using cross product and < > <= =>
// Pretty neat, don't remember learning this before.
// http://www.themathpage.com/arith/compare-fractions-2.htm
std::vector<int> Rational::cross_multiply(Rational r)
{
    int left = _num * r._den;
    int right = r._num * _den;
    return std::vector<int> {left, right};
}

Rational::Rational(int num)
{
    _num = num;
    _den = 1;
}
Rational::Rational(int num, int den)
{
    if (den == 0)
    {
        throw;
    }

    _num = num;
    _den = den;
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

bool Rational::operator<(Rational r)
{
    std::vector<int> cmresult = cross_multiply(r);
    return cmresult[0] < cmresult[1];
}

// same code as operator<
bool Rational::operator>(Rational r)
{
    std::vector<int> cmresult = cross_multiply(r);
    return cmresult[0] > cmresult[1];
}

bool Rational::operator<=(Rational r)
{
    return *this < r || *this == r;
}

bool Rational::operator>=(Rational r)
{
    return *this > r || *this == r;
}

Rational Rational::operator+(Rational r)
{
    std::vector<int> cmresult = cross_multiply(r);
    int newNum = cmresult[0] + cmresult[1];
    int newDen = _den * r._den;
    return Rational(newNum, newDen);
}

Rational Rational::operator-(Rational r)
{
    std::vector<int> cmresult = cross_multiply(r);
    int newNum = cmresult[0] - cmresult[1];
    int newDen = _den * r._den;
    return Rational(newNum, newDen);
}

Rational Rational::operator*(Rational r)
{
    int newNum = _num * r._num;
    int newDen = _den * r._den;
    return Rational(newNum, newDen);
}

Rational Rational::operator/(Rational r)
{
    Rational inverted_r = Rational(r._den, r._num);
    int newNum = _num * inverted_r._num;
    int newDen = _den * inverted_r._den;
    return Rational(newNum, newDen);
}

std::istream& operator>>(std::istream &in, Rational &r)
{
    in >> r._num >> r._den;
    r.simplify();
    return in;
}

std::ostream& operator<<(std::ostream &out, const Rational &r)
{
    if (r._num == 0)
        out << 0;
    else if (r._den == 1)
        out << r._num;
    else
        out << r._num << "/" << r._den;
    return out;
}

Rational Rational::operator-()
{
    return Rational(-_num, _den);
}
