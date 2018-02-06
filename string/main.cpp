#include <cassert>
//#include <iostream>
#include "String.hpp"

int main()
{
    String s0;

    String s1 = "foo";
    String s2 = s1;
    assert(s1 == s2);

    s2 = "cats";
    assert(s1 != s2);
    assert(s1 > s2);
    assert(s2 < s1);

    s2 = s1;
    assert(s1 >= s2);
    assert(s1 <= s2);

}
