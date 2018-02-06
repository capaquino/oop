#include "String.hpp"

String::String(const char* s)
: _len(std::strlen(s)), _str(new char[_len+1])
{
    std::strncpy(_str, s, _len);
}

String::String(const String& s)
: _len(s._len), _str(new char[_len+1])
{
    std::strncpy(_str, s._str, _len);
}

String& String::operator=(const char* s)
{
    delete[] _str;
    _len = std::strlen(s);
    _str = new char[_len+1];
    std::strncpy(_str, s, _len);
    return *this;
}

String& String::operator=(const String &s)
{
    delete[] _str;
    _len = s._len+1; // or std::strlen(s._str);
    _str = new char[_len+1];
    std::strncpy(_str, s._str, _len);
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
