#pragma once

#include <cstring>

class String
{
private:
    int _len;
    char* _str;

public:
    // Default
    String() {}

    // Literal, can't remember from thurs if this was inherently broken
    String(const char *s)
    : _len(std::strlen(s)), _str(new char[_len])
    {
        std::strcpy(_str, s);
    }

    // Copy, see Literal
    String(const String& s)
    : _len(s._len), _str(new char[_len])
    {
        std::strcpy(_str, s._str);
    }

    ~String()
    {
        delete[] _str;
    }

    String& operator=(const char* s)
    {
        delete[] _str;
        _len = std::strlen(s);
        _str = new char[_len];
        std::strcpy(_str, s);
        return *this;
    }

    String& operator=(const String &s)
    {
        delete[] _str;
        _len = std::strlen(s._str);
        _str = new char[_len];
        std::strcpy(_str, s._str);
        return *this;
    }

    bool operator==(const String &s)
    {
        return (std::strcmp(_str, s._str) == 0);
    }

    bool operator!=(const String &s)
    {
        return !(*this == s);
    }

    bool operator>(const String &s)
    {
        return (std::strcmp(_str, s._str) > 0);
    }

    bool operator<(const String &s)
    {
        return (std::strcmp(_str, s._str) < 0);
    }

    bool operator>=(const String &s)
    {
        return (std::strcmp(_str, s._str) >= 0);
    }

    bool operator<=(const String &s)
    {
        return (std::strcmp(_str, s._str) <= 0);
    }

    friend std::ostream& operator<<(std::ostream &out, const String &s);
};

std::ostream& operator<<(std::ostream &out, const String &s)
{
    out << s._str;
    return out;
}
