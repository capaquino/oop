#include <iostream>

#include "String.hpp"

int main()
{
    String s0;

    String s1 = "foo";
    String s2 = s1;
    std::cout << "s1: " << s1 << std::endl;
    std::cout << "s2: " << s2 << std::endl;

    std::cout << "s1 == s2 is ";
    if (s1==s2)
    {
        std::cout << "true" << std::endl;
    }
    else
    {
        std::cout << "false" << std::endl;
    }
    std::cout << "Changing s2 and hopefully not changing s1." << std::endl;
    s2 = "cats";
    std::cout << "s1: " << s1 << std::endl;
    std::cout << "s2: " << s2 << std::endl;

    std::cout << "s1 == s2 is ";
    if (s1==s2)
    {
        std::cout << "true" << std::endl;
    }
    else
    {
        std::cout << "false" << std::endl;
    }

    std::cout << "s1 != s2 is ";
    if (s1!=s2)
    {
        std::cout << "true" << std::endl;
    }
    else
    {
        std::cout << "false" << std::endl;
    }

    std::cout << "s1 > s2 is ";
    if (s1>s2)
    {
        std::cout << "true" << std::endl;
    }
    else
    {
        std::cout << "false" << std::endl;
    }

    std::cout << "s1 < s2 is ";
    if (s1<s2)
    {
        std::cout << "true" << std::endl;
    }
    else
    {
        std::cout << "false" << std::endl;
    }

    std::cout << "s1 >= s2 is ";
    if (s1>=s2)
    {
        std::cout << "true" << std::endl;
    }
    else
    {
        std::cout << "false" << std::endl;
    }

    std::cout << "s1 <= s2 is ";
    if (s1<=s2)
    {
        std::cout << "true" << std::endl;
    }
    else
    {
        std::cout << "false" << std::endl;
    }
/*
    std::cout << "Changing s2 back to s1" << std::endl;
    s2 = s1; // this is causing a malloc error
    std::cout << "s1: " << s1 << std::endl;
    std::cout << "s2: " << s2 << std::endl;

    std::cout << "s1 >= s2 is ";
    if (s1>=s2)
    {
        std::cout << "true" << std::endl;
    }
    else
    {
        std::cout << "false" << std::endl;
    }

    std::cout << "s1 <= s2 is ";
    if (s1<=s2)
    {
        std::cout << "true" << std::endl;
    }
    else
    {
        std::cout << "false" << std::endl;
    }
*/
}

/*  Why does this give me a malloc error...
    std::cout << "Performing s1 == s2, " << (s1==s2 ? "True" : "False") << std::endl;

    but this does not...
    std::cout << "s1 == s2 is ";
    if (s1==s2)
        std::cout << "true" << std::endl;
    else
        std::cout << "false" << std::endl;

    Destructor not getting called?
*/
