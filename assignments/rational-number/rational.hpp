#pragma once

#include <iosfwd>

/*
Implement a rational number class. The class must:

Only allow the creation of valid rational numbers
Support equality (==, !=)
Support ordering (<, >, <=, >=)
Support basic arithmetic operators (+, - , * /)
Support input and output using istream (>>) and ostream (<<)
The input and output format form rational numbers should be of the form "n / d".
*/

class Rational
{
private:

public:
    bool operator==(const Rational &r);
    bool operator!=(const Rational &r);
    bool operator<(const Rational &r);
    bool operator>(const Rational &r);
    bool operator<=(const Rational &r);
    bool operator>=(const Rational &r);
    bool operator+(const Rational &r);
    bool operator-(const Rational &r);
    bool operator*(const Rational &r);
    bool operator/(const Rational &r);
    // bool operator>>(const Rational &r);
    friend std::ostream& operator<<(std::ostream &out, const Rational &r);

};
