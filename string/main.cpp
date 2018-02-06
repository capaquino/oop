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
    // my mind is literally being blown, why do i get malloc errors if I take
    // these two out, or if I add additional copies of these statements.
    // ** Ask in class **
    assert(s1 == s2);

    s2 = "cats";
    //std::cout << "s1: " << s1 << std::endl;
    //std::cout << "s2: " << s2 << std::endl;
    assert(s1 != s2);
    assert(s1 > s2);
    assert(s2 < s1);


    s2 = s1;
    //std::cout << "s1: " << s1 << std::endl;
    //std::cout << "s2: " << s2 << std::endl;
    assert(s1 >= s2);
    assert(s1 <= s2);

}
