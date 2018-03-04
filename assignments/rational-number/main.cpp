#include <iostream>
#include <cassert>
#include <fstream>

#include "rational.hpp"


int main(int argc, char const *argv[]) {

    // Equivalent
    Rational r1 = Rational(10,2);
    Rational r2 = Rational(5,1);
    assert(r1 == r2);

    // Not equivalent
    Rational r3 = Rational(9,2);
    assert(r1 != r3);

    // Greater/Less Than
    assert(r3 < r1);
    assert(r1 > r3);

    // Greater/Less Than or Equal to, not equivalent case
    assert(r3 <= r1);
    assert(r1 >= r3);

    // Greater/Less Than or Equal to, equivalent case
    assert(r1 <= r2);
    assert(r1 >= r2);

    // Addition
    Rational r4 = r1 + r2;
    assert(r4 == Rational(10));         // 10/2 + 5/1 = 10

    // Subtraction
    Rational r5 = r4 - Rational(-10,3);
    assert(r5 == Rational(40,3));       // 10 - -10/3 = 40/3, note 10 = 30/3

    // Multiplcation
    Rational r6 = r1 * -r4;
    assert(r6 == Rational(-50));        // 5 * -10 = -50

    // Division
    Rational r7 = Rational(10,2);
    Rational r8 = Rational(3);
    Rational r9 = r7 / r8;

    // Input stream
    std::ifstream in;
    in.open("input"); // input file is "11 -3" and a newline/cr
    Rational r10;
    in >> r10;
    assert(r10 == Rational(11,-3));

    // Output stream
    std::cout << "Rational(5) is displayed as " << Rational(5) << std::endl;
    std::cout << "Rational(5,1) is displayed as " << Rational(5,1) << std::endl;
    std::cout << "Rational(0) is displayed as " << Rational(0) << std::endl;
    std::cout << "Rational(0, 5) is displayed as " << Rational(0,5) << std::endl;
    std::cout << "Rational(-5,5) is displayed as " << Rational(-5,5) << std::endl;
    std::cout << "Rational(1,-5) is displayed as " << Rational(1,-5) << std::endl;
    std::cout << "Rational(-8,-3) is displayed as " << Rational(-8,-3) << std::endl;
    std::cout << "Rational(-8,-4) is displayed as " << Rational(-8,-4) << std::endl;
    std::cout << "-Rational(5,5) is displayed as " << -Rational(5,5) << std::endl;
    std::cout << "-Rational(-6,-3) is displayed as " << -Rational(-6,-3) << std::endl;

    return 0;
}
