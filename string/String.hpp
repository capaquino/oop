#pragma once

#include <cstring>

class String
{
private:
    int _len;
    char* _str;

public:
    String() {}

    String(const char* s)
    : _len(std::strlen(s)), _str(new char[_len+1])
    {
        std::strncpy(_str, s, _len);
    }

    String(const String& s)
    : _len(s._len), _str(new char[_len+1])
    {
        std::strncpy(_str, s._str, _len);
    }

    String& operator=(const char* s)
    {
        delete[] _str;
        _len = std::strlen(s);
        _str = new char[_len+1];
        std::strncpy(_str, s, _len);
        return *this;
    }

    String& operator=(const String &s)
    {
        delete[] _str;
        _len = s._len+1; // or std::strlen(s._str);
        _str = new char[_len+1];
        std::strncpy(_str, s._str, _len);
        return *this;
    }

    ~String()
    {
        delete[] _str;
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
