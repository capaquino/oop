#pragma once

#include <string>

#include "members.hpp"

// The player knows about the city, but the city does not know about the player.
// Therefore, the city could be used by any "driver" game.
class City
{
public:
    std::string name;

    // PublicWorks?

    Building cathedral;
    Building marketplace; // coupled with Revenue marketRevenue
    Building mill; // coupled with Revenue millRevenue
    Building palace;

    People clergy;
    People serfs; // dead serfs, fleeing serfs, new serfs, transplanted serfs
    People merchants;
    People nobles;
    People soldiers; // solderPay

    Revenue customsDuty; // x vs xRevenue?
    Revenue incomeTax; // ^
    Revenue justice; // ^, justice special case?
    Revenue marketRevenue;
    Revenue millRevenue;
    Revenue salesTax; // ^

    Resource grain; // harvest?
    Resource land; // float landPrice

    Events rats; // Rats, RatsAte difference?

    City(std::string n) : name(n)
    {
        // Init a city here
    }
};
