#pragma once

#include <string>

class City
{
public:
    City(std::string n) : name(n)
    {
        // Init a city here
    }

    std::string name;
    // treasury
    // building: cathedral, market, mill, palace. bool Purchased();
    // resources: grain, land
    // people: serfs, nobles, soldiers
};


// buildings
// people

/*
Cathedral,
Clergy,
CustomsDuty,
CustomsDutyRevenue,
DeadSerfs;
Difficulty,
FleeingSerfs,
GrainDemand,
GrainPrice,
GrainReserve;
Harvest,
IncomeTax,
IncomeTaxRevenue,
RatsAte;
Justice,
JusticeRevenue,
Land,
Marketplaces,
MarketRevenue;
Merchants,
MillRevenue,
Mills,
NewSerfs,
Nobles,
OldTitle,
Palace;
Rats,
SalesTax,
SalesTaxRevenue,
Serfs,
SoldierPay,
Soldiers,
TitleNum;
TransplantedSerfs,
Treasury,
WhichPlayer,
Year,
YearOfDeath

char City[15], Name[25], Title[15];
float PublicWorks, LandPrice;
boolean InvadeMe, IsBankrupt, IsDead, IWon, MaleOrFemale, NewTitle;
*/
