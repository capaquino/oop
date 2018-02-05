#include <iostream>
#include <cassert>
#include "String.hpp"

int main()
{
    String s0;

    String s1 = "foo";
    String s2 = s1;
    std::cout << "s1: " << s1 << std::endl;
    std::cout << "s2: " << s2 << std::endl;

    assert(s1==s2);

    std::cout << "Changing s2 and hopefully not changing s1." << std::endl;
    s2 = "cats";

    assert(s1!=s2);
    assert(s1>s2);
    assert(s2<s1);

    std::cout << "Changing s2 back to s1" << std::endl;
    s2 = s1; // pretty sure this causes a malloc error

    assert(s1>=s2);
    assert(s1<=s2);
}
