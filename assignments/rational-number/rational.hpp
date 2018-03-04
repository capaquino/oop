#pragma once

#include <iosfwd>

/*
Implement a rational number class. The class must:

1. Only allow the creation of valid rational numbers
2. Support equality (==, !=)
3. Support ordering (<, >, <=, >=)
4. Support basic arithmetic operators (+, - , * /)
5. Support input and output using istream (>>) and ostream (<<)
6. The input and output format form rational numbers should be of the form "n / d".
*/

class Rational
{
private:
    int _num;
    int _den;
    void simplify();
public:
    Rational(int n, int d);
    bool operator==(Rational r);
    bool operator!=(Rational r);
    bool operator<(Rational r);
    bool operator>(Rational r);
    bool operator<=(Rational r);
    bool operator>=(Rational r);
    bool operator+(Rational r);
    bool operator-(Rational r);
    bool operator*(Rational r);
    bool operator/(Rational r);
    friend std::istream& operator>>(std::istream &in, Rational &r);
    friend std::ostream& operator<<(std::ostream &out, const Rational &r);

};
