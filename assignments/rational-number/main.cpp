#include <iostream>
#include <cassert>

#include "rational.hpp"


int main(int argc, char const *argv[]) {

    Rational r1 = Rational(10,2);
    Rational r2 = Rational(5,1);
    assert(r1 == r2);

    Rational r3 = Rational(9,2);
    assert(r1 != r3);

    assert(r3 < r1);
    assert(r1 > r3);

    assert(r3 <= r1);
    assert(r1 >= r3);
    assert(r1 <= r2);
    assert(r1 >= r2);

    std::cout << r3 << std::endl;

    return 0;
}
