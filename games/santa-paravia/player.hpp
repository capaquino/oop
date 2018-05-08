#pragma once

#include <string>

#include "city.hpp"

class Player
{
private:
    City city;

    std::string name;
    std::string title;
    unsigned rank;
    int oldTitle;
    int titleNum;
    bool isBankrupt;
    int difficulty;
    bool won;

public:
    Player(std::string n, std::string cityName) : name(n), city(City(cityName))
    {
        titleNum = 1;
        isBankrupt = false;
        difficulty = 1;
        won = false;
    }

    int random(int upperBound)
    {
        std::srand(std::time(NULL)); // okay to do this every time?
        return rand() % upperBound;
    }

    void AddRevenue()
    {
        city.treasury.coffers += city.justice.incoming
            + city.customsDuty.incoming
            + city.incomeTax.incoming
            + city.salesTax.incoming;

        if (city.treasury.coffers < 0)
        {
            city.treasury.coffers = static_cast<int>(static_cast<float>(city.treasury.coffers)*1.5); // those static casts necessary?
        }

        if (city.treasury.coffers < (-10000 * titleNum))
        {
            isBankrupt = true;
        }
    }
    // AttackNeighbor

    void BuyCathedral()
    {
        city.cathedrals.amount++;
        city.clergy.population += random(6);
        city.treasury.coffers -= 5000;
        city.publicWorks++;
    }
    void BuyGrain(int amount) // different than original
    {
        // original has UI stuff. Do that in Game class
        city.grain.reserve += amount;
        city.treasury.coffers -= city.grain.price * amount / 1000; // what's the 1000 for.
    }
    void BuyLand(int amount)
    {
        city.land.reserve += amount;
        city.treasury.coffers -= city.land.price * amount;
    }
    void BuyMarket()
    {
        city.marketplaces.amount++;
        city.merchants.population += 5;
        city.treasury.coffers -= 1000;
        city.publicWorks++;
    }
    void BuyMill()
    {
        city.mills.amount++;
        city.treasury.coffers -= 2000;
        city.publicWorks += 0.25;
    }
    void BuyPalace()
    {
        city.palaces.amount++;
        city.nobles.population += random(2);
        city.treasury.coffers -= 3000;
        city.publicWorks += 0.5;
    }

    void BuySoldiers()
    {
        city.soldiers.population += 20;
        city.serfs.population -= 20;
        city.treasury.coffers -= 500;
    }

    int limit10(int a, int b) // why is this here
    {
        int val = a / b;
        return val > 10 ? 10 : val;
    }
    // add genders
    bool CheckNewTitle()
    {
        int Total;
        Total = limit10(city.marketplaces.amount, 1);
        Total += limit10(city.palaces.amount, 1);
        Total += limit10(city.cathedrals.amount, 1);
        Total += limit10(city.mills.amount, 1);
        Total += limit10(city.treasury.coffers, 5000);
        Total += limit10(city.land.reserve, 6000);
        Total += limit10(city.merchants.population, 50);
        Total += limit10(city.nobles.population, 5);
        Total += limit10(city.soldiers.population, 50);
        Total += limit10(city.clergy.population, 10);
        Total += limit10(city.serfs.population, 2000);
        Total += limit10(static_cast<int>(city.publicWorks * 100), 500);

        titleNum = (Total / difficulty) - city.justice.rate;

        if(titleNum > 7)
        {
            titleNum = 7; // did really well
        }
        if(titleNum < 0)
        {
            titleNum = 0;
        }

        // Improve or do worse?
        if(titleNum > oldTitle)
        {
            oldTitle = titleNum;
            if (titleNum == 7)
            {
                won = true;
            }
            return true; // what are these bool values being used for.
        }
        titleNum = oldTitle;
        return false; // what are these bool values being used for.
    }

    void GenerateHarvest()
    {
        
    }

    void GenerateIncome();
    void ChangeTitle();
    void NewLandAndGrainPrices();
    void PrintGrain();
    int ReleaseGrain();
    void SeizeAssets();
    void SellGrain();
    void SellLand();
    void SerfsDecomposing(); // also had a float param
    void SerfsProcreating(); // also had a float param




    bool Won()
    {
        return won;
    }
};
/*

int AttackNeighbor(player *, player *);

void GenerateHarvest(player *);
void GenerateIncome(player *);
void ChangeTitle(player *);
void NewLandAndGrainPrices(player *);
void PrintGrain(player *);
int ReleaseGrain(player *);
void SeizeAssets(player *);
void SellGrain(player *);
void SellLand(player *);
void SerfsDecomposing(player *, float);
void SerfsProcreating(player *, float);
void PrintInstructions(void);
void PlayGame(player [], int);
void NewTurn(player *, int, player [], player *);
void BuySellGrain(player *);
void AdjustTax(player *);
void DrawMap(player *);
void StatePurchases(player *, int, player []);
void ShowStats(player [], int);
void ImDead(player *);
*/


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
