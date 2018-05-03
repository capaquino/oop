#pragma once

#include <string>

#include "city.hpp"

typedef std::pair<std::string, int> Title;

class Player
{
public:
    std::string name;
    Title title;
    Player(std::string n, Title t) : name(n), title(t)
private:
    City* p_city;
};
