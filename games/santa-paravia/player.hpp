#pragma once

#include <string>

#include "city.hpp"
#include "title.hpp"

class Player
{
public:
    std::string name;
    Title title;
    Player(std::string n, Title t);// Player(std::string n, Title t) : name(n), title(t) {};
private:
    const City city;
};
