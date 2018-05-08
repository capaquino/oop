#pragma once

#include <string>

#include "city.hpp"

class Player
{
public:
    std::string name;
    std::string title;
    unsigned rank;

    Player(std::string n, std::string cityName) : name(n), city(City(cityName))
    {
    }

    bool TakeTurn()
    {
        // Update all city information here. Simulate Santa Paravia

        
        return true;
    }

private:
    City city;
};

/*
Difficulty <-- Game?
OldTitle
TitleNum
WhichPlayer <-- Game?
Year <-- Game?
YearOfDeath

boolean
InvadeMe
IsBankrupt
IsDead
IWon
MaleOrFemale
NewTitle
*/
