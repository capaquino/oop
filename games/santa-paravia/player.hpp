#pragma once

#include <string>

#include "city.hpp"

class Player
{
public:
    Player(std::string n, std::string t) : name(n), title(t)
    {
        // anything else?
    }

    std::string GetName()
    {
        return name;
    }

    std::string GetTitle()
    {
        return title;
    }

    void TakeTurn()
    {
        // Update all city information here. Simulate Santa Paravia
        // ? City->NewTurn()?
    }
private:
    std::string name;
    std::string title;
    unsigned rank;
    City* pCity;
};
