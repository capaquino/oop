#pragma once

#include <string>

#include "members.hpp"

// The player knows about the city, but the city does not know about the player.
// Therefore, the city could be used by any "driver" game.
class City
{
public:
    std::string name;

    Building cathedrals;
    Building marketplaces; // coupled with Revenue marketRevenue
    Building mills; // coupled with Revenue millRevenue
    Building palaces;
    float publicWorks; // used for what?

    People clergy;
    Serfs serfs; // dead serfs, fleeing serfs, new serfs, transplanted serfs
    People merchants;
    People nobles;
    Soldiers soldiers; // solderPay

    Revenue customsDuty; // x vs xRevenue?
    Revenue incomeTax; // ^
    Revenue justice; // ^, justice special case?
    Revenue marketRevenue;
    Revenue millRevenue;
    Revenue salesTax; // ^

    Resource grain; // harvest?
    Resource land; // float landPrice
    int harvest; // how is this used exactly.

    Events rats; // Rats, RatsAte difference?

    Treasury treasury;

    City(std::string n) : name(n)
    {
        cathedrals.amount = 0;
        clergy.population = 5;
        customsDuty.rate = 25;
        // difficulty goes where = int level;
        grain.price = 25;
        grain.reserve = 5000;
        incomeTax.rate = 5;
        // IsBankrupt = false;
        // IsDead = false;
        // IWon = false;
        justice.rate = 2; // keep an eye out for how this is used.
        land.reserve = 10000;
        land.price = 10;
        // male or female
        marketplaces.amount = 0;
        merchants.population = 25;
        mills.amount = 0;
        nobles.population = 4;
        // old title = 1;
        palaces.amount = 0;
        publicWorks = 1;
        salesTax.rate = 10;
        serfs.population = 2000;
        soldiers.population = 25;
        // titleNum = 1;
        // male or female title assignment
        treasury.coffers = 1000;
        // city assignment
        // current year = int year
        // year of death assignment = int year + 20 + random(35);
    }
};
