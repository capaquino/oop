#pragma once

#include <cstring>
#include <iostream>

class String
{
private:
    int _len;
    char* _str;

public:
    String() {}
    String(const char* s);
    String(const String& s);
    String& operator=(const char* s);
    String& operator=(const String &s);
    ~String();
    bool operator==(const String &s);
    bool operator!=(const String &s);
    bool operator>(const String &s);
    bool operator<(const String &s);
    bool operator>=(const String &s);
    bool operator<=(const String &s);
    friend std::ostream& operator<<(std::ostream &out, const String &s);
};
