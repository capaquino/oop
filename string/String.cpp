#include "String.hpp"
// len is length of string not including null
// str is full string and needs to include null
// strlen does not count null
// strcpy does copy null char
// no, strncpy is not a typo

String::String(const char* s)
: _len(std::strlen(s)), _str(new char[_len+1])
{
    //std::strncpy(_str, s, _len+1);
    std::strcpy(_str, s);
}

String::String(const String& s)
: _len(s._len), _str(new char[_len+1])
{
    //std::strncpy(_str, s._str, _len+1);
    std::strcpy(_str, s._str);
}

String& String::operator=(const char* s)
{
    delete[] _str;
    _len = std::strlen(s);
    _str = new char[_len+1];
    //std::strncpy(_str, s, _len+1);
    std::strcpy(_str, s);
    return *this;
}

String& String::operator=(const String &s)
{
    delete[] _str;
    _len = s._len; // or std::strlen(s._str);
    _str = new char[_len+1];
    //std::strncpy(_str, s._str, _len+1);
    std::strcpy(_str, s._str);
    return *this;
}

String::~String()
{
    delete[] _str;
}

bool String::operator==(const String &s)
{
    return (std::strcmp(_str, s._str) == 0);
}

bool String::operator!=(const String &s)
{
    return !(*this == s);
}

bool String::operator>(const String &s)
{
    return (std::strcmp(_str, s._str) > 0);
}

bool String::operator<(const String &s)
{
    return (std::strcmp(_str, s._str) < 0);
}

bool String::operator>=(const String &s)
{
    return (std::strcmp(_str, s._str) >= 0);
}

bool String::operator<=(const String &s)
{
    return (std::strcmp(_str, s._str) <= 0);
}

std::ostream& operator<<(std::ostream &out, const String &s)
{
    out << s._str;
    return out;
}
