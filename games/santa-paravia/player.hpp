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
    bool invadeMe;
    int year;
    bool isDead;

public:
    Player(std::string n, std::string cityName) : name(n), city(City(cityName))
    {
        title = "default";
        titleNum = 1;
        isBankrupt = false;
        difficulty = 1;
        won = true; // change this to false
        invadeMe = false;
        year = -1;
        isDead = false;
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
    //void BuyGrain(int amount) // different than original
    void BuyGrain()
    {
        char string[256];
        int HowMuch;
        printf("How much grain do you want to buy (0 to specify a total)? ");
        fgets(string, 255, stdin);
        HowMuch = static_cast<int>(atoi(string));
        if(HowMuch == 0)
        {
            printf("How much total grain do you wish? ");
            fgets(string, 255, stdin);
            HowMuch = static_cast<int>(atoi(string));
            HowMuch -= city.grain.reserve;
            if(HowMuch < 0)
            {
                printf("Invalid total amount.\n\n");
                return;
            }
        }

        city.treasury.coffers -= (HowMuch * city.grain.price / 1000);
        city.grain.reserve += HowMuch;
        return;
        // original has UI stuff. Do that in Game class
        // city.grain.reserve += amount;
        // city.treasury.coffers -= city.grain.price * amount / 1000; // what's the 1000 for.
    }

    //void BuyLand(int amount) // different than original
    void BuyLand()
    {
        char string[256];
        int HowMuch;
        printf("How much land do you want to buy? ");
        fgets(string, 255, stdin);
        HowMuch = static_cast<int>(atoi(string));
        city.land.reserve += HowMuch;
        city.treasury.coffers -= static_cast<int>(( static_cast<float>(HowMuch) * city.land.price));
        return;
        // original has UI stuff. Do that in Game class
        // city.land.reserve += amount;
        // city.treasury.coffers -= city.land.price * amount;
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
        city.harvest = (random(5)+random(6)) / 2;
        city.rats.amount = random(50);
        city.grain.reserve = (city.grain.reserve*100 - city.grain.reserve*city.rats.amount) / 100;
    }

    void GenerateIncome()
    {
        float y;
        int revenues = 0;
        char string[256];
        city.justice.incoming = (city.justice.rate * 300 - 500) * titleNum;
        /*switch(city.justice.rate)
        {
            case 1: strcpy(string, "Very Fair"); break;
            case 2: strcpy(string, "Moderate"); break;
            case 3: strcpy(string, "Harsh"); break;
            case 4: strcpy(string, "Outrageous");
        }
        */

        y = 150.0 - static_cast<float>(city.salesTax.rate) - static_cast<float>(city.customsDuty.rate) -
            static_cast<float>(city.incomeTax.rate);
        if(y < 1.0)
            y = 1.0;
        y /= 100.0;
        city.customsDuty.incoming = city.nobles.population * 180 + city.clergy.population * 75 +
                                 city.merchants.population * 20 * y;
        city.customsDuty.incoming += static_cast<int>(city.publicWorks * 100.0);
        city.customsDuty.incoming = static_cast<int>(static_cast<float>(city.customsDuty.rate) / 100.0 *
                                       static_cast<float>(city.customsDuty.incoming));
        city.salesTax.incoming = city.nobles.population * 50 + city.merchants.population * 25 +
                              (int)(city.publicWorks * 10.0);
        city.salesTax.incoming *= (y * (5 - city.justice.rate) * city.salesTax.rate);
        city.salesTax.incoming /= 200;
        city.incomeTax.incoming = city.nobles.population * 250 + (int)(city.publicWorks * 20.0);
        city.incomeTax.incoming += (10 * city.justice.rate * city.nobles.population * y);
        city.incomeTax.incoming *= city.incomeTax.rate;
        city.incomeTax.incoming /= 100;
        revenues = city.customsDuty.incoming + city.salesTax.incoming +
                   city.incomeTax.incoming + city.justice.incoming;

        printf("State revenues %d gold florins.\n", revenues);
        printf("Customs Duty\tSales Tax\tIncome Tax\tJustice\n");
        printf("%d\t\t%d\t\t%d\t\t%d %s\n", city.customsDuty.incoming,
               city.salesTax.incoming, city.incomeTax.incoming,
               city.justice.incoming, string);

    }

    void NewLandAndGrainPrices()
    {
        float x, y, MyRandom;
        int h;

        MyRandom = static_cast<float>((static_cast<float>(rand()) / static_cast<float>(RAND_MAX)));

        x = static_cast<float>(city.land.reserve);
        y = ((static_cast<float>(city.serfs.population) - static_cast<float>(city.mills.amount)) * 100.0) * 5.0;
        if(y < 0.0)
            y = 0.0;
        if(y < x)
            x = y;
        y = static_cast<float>(city.grain.reserve) * 2.0;
        if(y < x)
            x = y;
        y = static_cast<float>(city.harvest) + (MyRandom - 0.5);
        h = static_cast<int>(x * y);
        city.grain.reserve += h;
        city.grain.demand = (city.nobles.population * 100) + (city.cathedrals.amount * 40) +
                          (city.merchants.population * 30);
        city.grain.demand += ((city.soldiers.population * 10) + (city.serfs.population * 5));
        city.land.price = (3.0 * static_cast<float>(city.harvest) + static_cast<float>(random(6)) + 10.0) / 10.0;
        if(h < 0)
            h *= -1;
        if(h < 1)
            y = 2.0;
        else
        {
            y = static_cast<float>(static_cast<float>(city.grain.demand / static_cast<float>(h)));
            if(y > 2.0)
                y = 2.0;
        }
        if(y < 0.8)
            y = 0.8;
        city.land.price *= y;
        if(city.land.price < 1.0) city.land.price = 1.0;
        city.grain.price = static_cast<int>(((6.0 - static_cast<float>(city.harvest) * 3.0 + static_cast<float>(random(5))
                                + static_cast<float>(random(5)) * 4.0 * y)));
        city.rats.amountEffected = h;
    }

    void PrintGrain() // was void
    {
        switch(city.harvest)
        {
            case 0:
            case 1: printf("Drought. Famine Threatens. "); break;
            case 2: printf("Bad Weather. Poor Harvest. "); break;
            case 3: printf("Normal Weather. Average Harvest. "); break;
            case 4: printf("Good Weather. Fine Harvest. "); break;
            case 5: printf("Excellent Weather. Great Harvest! "); break;
        }
        return;
        //return city.harvest; // change return type to int
    } // change to generate harvest string

    int ReleaseGrain()
    {
        double xp, zp;
        float x, z;
        char string[256];
        int HowMuch, Maximum, Minimum;
        bool IsOK;
        IsOK = false;
        Minimum = city.grain.reserve / 5;
        Maximum = (city.grain.reserve - Minimum);
        while(IsOK == false)
        {
            printf("How much grain will you release for consumption?\n");
            printf("1 = Minimum (%d), 2 = Maximum(%d), or enter a value: ",
                   Minimum, Maximum);
            fgets(string, 255, stdin);
            HowMuch = static_cast<int>(atoi(string));
            if(HowMuch == 1)
                HowMuch = Minimum;
            if(HowMuch == 2)
                HowMuch = Maximum;
            if(HowMuch < Minimum)
                printf("You must release at least 20%% of your reserves.\n");
            else if(HowMuch > Maximum)
                printf("You must keep at least 20%%.\n");
            else
                IsOK = true;
        }

        city.soldiers.upkeep = 0;
        city.marketRevenue.incoming = 0;
        city.serfs.incoming = 0;
        city.serfs.dead = 0;
        city.serfs.transplanted = 0;
        city.serfs.fleeing = 0;
        invadeMe = false;
        city.grain.reserve -= HowMuch;
        z = static_cast<float>(HowMuch) / static_cast<float>(city.grain.demand) - 1.0;
        if(z > 0.0)
            z /= 2.0;
        if(z > 0.25)
            z = z / 10.0 + 0.25;
        zp = 50.0 - static_cast<double>(city.customsDuty.rate) - static_cast<double>(city.salesTax.rate) -
             static_cast<double>(city.incomeTax.rate);
        if(zp < 0.0)
            zp *= static_cast<double>(city.justice.rate);
        zp /= 10.0;
        if(zp > 0.0)
            zp += (3.0 - static_cast<double>(city.justice.rate));
        z += (static_cast<float>(zp) / 10.0);
        if(z > 0.5)
            z = 0.5;
        if(HowMuch < (city.grain.demand - 1))
        {
            x = (static_cast<float>(city.grain.demand) - static_cast<float>(HowMuch)) /
                static_cast<float>(city.grain.demand) * 100.0 - 9.0;
            xp = static_cast<double>(x);
            if(x > 65.0)
                x = 65.0;
            if(x < 0.0)
            {
                xp = 0.0;
                x = 0.0;
            }
            SerfsProcreating(3.0);
            SerfsDecomposing(xp + 8.0);
        }
        else
        {
            SerfsProcreating(7.0);
            SerfsDecomposing(3.0);
            if((city.customsDuty.rate + city.salesTax.rate) < 35)
                city.merchants.population += random(4);
            if(city.incomeTax.rate < random(28))
            {
                city.nobles.population += random(2);
                city.clergy.population += random(3);
            }
            if(HowMuch > static_cast<int>((static_cast<float>(city.grain.demand) * 1.3)))
            {
                zp = static_cast<double>(city.serfs.population / 1000.0);
                z = (static_cast<float>(HowMuch) - static_cast<float>(city.grain.demand)) /
                    static_cast<float>(city.grain.demand) * 10.0;
                z *= (static_cast<float>(zp) * static_cast<float>(random(25)));
                z += static_cast<float>(random(40));
                city.serfs.transplanted = static_cast<int>(z);
                city.serfs.population += city.serfs.transplanted;
                printf("%d serfs move to the city\n", city.serfs.transplanted);
                zp = static_cast<double>(z);
                z = (static_cast<float>(zp) * static_cast<float>(rand())) / static_cast<float>(RAND_MAX);
                if(z > 50.0)
                    z = 50.0;
                city.merchants.population += static_cast<int>(z);
                city.nobles.population++;
                city.clergy.population += 2;
            }
        }
        if(city.justice.rate > 2)
        {
            city.justice.incoming = city.serfs.population / 100 * (city.justice.rate - 2) *
                                 (city.justice.rate - 2);
            city.justice.incoming = random(city.justice.incoming);
            city.serfs.population -= city.justice.incoming;
            city.serfs.fleeing = city.justice.incoming;
            printf("%d serfs flee harsh justice\n", city.serfs.fleeing);
        }
        city.marketRevenue.incoming = city.marketplaces.amount * 75;
        if(city.marketRevenue.incoming > 0)
        {
            city.treasury.coffers += city.marketRevenue.incoming;
            printf("Your market earned %d florins.\n", city.marketRevenue.incoming);
        }
        city.millRevenue.incoming = city.mills.amount * (55 + random(250));
        if(city.millRevenue.incoming > 0)
        {
            city.treasury.coffers += city.millRevenue.incoming;
            printf("Your woolen mill earned %d florins.\n", city.millRevenue.incoming);
        }
        city.soldiers.upkeep = city.soldiers.population * 3;
        city.treasury.coffers -= city.soldiers.upkeep;
        printf("You paid your soldiers %d florins.\n", city.soldiers.upkeep);
        printf("You have %d serfs in your city.\n", city.serfs.population);
        printf("(Press ENTER): ");
        fgets(string, 255, stdin);
        if((city.land.reserve / 1000) > city.soldiers.population)
        {
            invadeMe = true;
            return 3;
        }
        if((city.land.reserve / 500) > city.soldiers.population)
        {
            invadeMe = true;
            return 3;
        }
        return 0;
    }

    void SeizeAssets()
    {
        char string[256];
        city.marketplaces.amount = 0;
        city.palaces.amount = 0;
        city.cathedrals.amount = 0;
        city.mills.amount = 0;
        city.land.reserve = 6000;
        city.publicWorks = 1.0;
        city.treasury.coffers = 100;
        isBankrupt = false;
        printf("\n\n%s %s is bankrupt.\n", title.c_str(), name.c_str()); // TODO: Fix these from being C strings.
        printf("\nCreditors have seized much of your assets.\n");
        printf("\n(Press ENTER): ");
        fgets(string, 255, stdin);
    }

    void SellGrain()
    {
        char string[256];
        int HowMuch;
        printf("How much grain do you want to sell? ");
        fgets(string, 255, stdin);
        HowMuch = static_cast<int>(atoi(string));
        if(HowMuch > city.grain.reserve)
        {
            printf("You don't have it.\n");
            return;
        }
        city.treasury.coffers += (HowMuch * city.grain.price / 1000);
        city.grain.reserve -= HowMuch;
        return;
    }

    void SellLand()
    {
        char string[256];
        int HowMuch;
        printf("How much land do you want to sell? ");
        fgets(string, 255, stdin);
        HowMuch = static_cast<int>(atoi(string));
        if(HowMuch > (city.land.reserve - 5000))
        {
            printf("You can't sell that much\n");
            return;
        }
        city.land.reserve -= HowMuch;
        city.treasury.coffers += static_cast<int>((static_cast<float>(HowMuch) * city.land.price));
    }

    void SerfsDecomposing(float MyScale)
    {
        int absc;
        float ord;
        absc = static_cast<int>(MyScale);
        ord = MyScale - static_cast<float>(absc);
        city.serfs.dead = static_cast<int>(((static_cast<float>(random(absc)) + ord) * static_cast<float>(city.serfs.population)) / 100.0);
        city.serfs.population -= city.serfs.dead;
        printf("%d serfs die this year.\n", city.serfs.dead);
    }

    void SerfsProcreating(float MyScale)
    {
        int absc;
        float ord;
        absc = static_cast<int>(MyScale);
        ord = MyScale - static_cast<float>(absc);
        city.serfs.incoming = static_cast<int>(((static_cast<float>(random(absc)) + ord) * static_cast<float>(city.serfs.population)) /
                             100.0);
        city.serfs.population += city.serfs.incoming;
        printf("%d serfs born this year.\n", city.serfs.incoming);
    }

    void BuySellGrain()
    {
        bool Finished;
        char string[256];
        Finished = false;
        while (Finished == false)
        {
            printf("\nYear %d\n", year);
            printf("\n%s %s\n\n", title.c_str(), name.c_str());
            printf("Rats ate %d%% of your grain reserves.\n", city.rats.amount);
            PrintGrain();
            printf("(%d steres)\n\n", city.rats.amountEffected);
            printf("Grain\tGrain\tPrice of\tPrice of\tTreasury\n");
            printf("Reserve\tDemand\tGrain\t\tLand\n");
            printf("%d\t%d\t%d\t\t%.2f\t\t%d\n", city.grain.reserve,
                   city.grain.demand, static_cast<int>(city.grain.price), city.land.price,
                   city.treasury.coffers);
            printf("steres\tsteres\t1000 st.\thectare\t\tgold florins\n");
            printf("\nYou have %d hectares of land.\n", city.land.reserve);
            printf("\n1. Buy grain, 2. Sell grain, 3. Buy land,");
            printf(" 4. Sell land\n(Enter q to continue): ");
            fgets(string, 255, stdin);
            if(string[0] == 'q')
                Finished = true;
            if(string[0] == '1')
                BuyGrain();
            if(string[0] == '2')
                SellGrain();
            if(string[0] == '3')
                BuyLand();
            if(string[0] == '4')
                SellLand();
        }
    }

    void AdjustTax()
    {
        char string[256];
        int val = 1, duty = 0;
        string[0] = '\0';
        while(val != 0 || string[0] != 'q')
        {
            printf("\n%s %s\n\n", title.c_str(), name.c_str());
            GenerateIncome();
            printf("(%d%%)\t\t(%d%%)\t\t(%d%%)",
                   city.customsDuty.rate, city.salesTax.rate,
                   city.incomeTax.rate);
            printf("\n1. Customs Duty, 2. Sales Tax, 3. Wealth Tax, ");
            printf("4. Justice\n");
            printf("Enter tax number for changes, q to continue: ");
            fgets(string, 255, stdin);
            val = static_cast<int>(atoi(string));
            switch(val)
            {
                case 1: printf("New customs duty (0 to 100): ");
                    fgets(string, 255, stdin);
                    duty = static_cast<int>(atoi(string));
                    if(duty > 100) duty = 100;
                    if(duty < 0) duty = 0;
                    city.customsDuty.rate = duty;
                    break;
                case 2: printf("New sales tax (0 to 50): ");
                    fgets(string, 255, stdin);
                    duty = static_cast<int>(atoi(string));
                    if(duty > 50) duty = 50;
                    if(duty < 0) duty = 0;
                    city.salesTax.rate = duty;
                    break;
                case 3: printf("New wealth tax (0 to 25): ");
                    fgets(string, 255, stdin);
                    duty = static_cast<int>(atoi(string));
                    if(duty > 25) duty = 25;
                    if(duty < 0) duty = 0;
                    city.incomeTax.rate = duty;
                    break;
                case 4: printf("Justice: 1. Very fair, 2. Moderate");
                    printf(" 3. Harsh, 4. Outrageous: ");
                    fgets(string, 255, stdin);
                    duty = static_cast<int>(atoi(string));
                    if(duty > 4) duty = 4;
                    if(duty < 1) duty = 1;
                    city.justice.rate = duty;
                    break;
                }
            }

            AddRevenue();
            if(isBankrupt == true)
            {
                SeizeAssets();
            }
    }

    // void DrawMap(); // not even implemented
    void StatePurchases() // (player *, int, player [])
    {
        char string[256];
        int val = 1;
        string[0] = '\0';
        while(val != 0 || string[0] != 'q')
        {
            printf("\n\n%s %s\nState purchases.\n", title.c_str(), name.c_str());
            printf("\n1. Marketplace (%d)\t\t\t\t1000 florins\n",
                   city.marketplaces.amount);
            printf("2. Woolen mill (%d)\t\t\t\t2000 florins\n",
                   city.mills.amount);
            printf("3. Palace (partial) (%d)\t\t\t\t3000 florins\n",
                   city.palaces.amount);
            printf("4. Cathedral (partial) (%d)\t\t\t5000 florins\n",
                   city.cathedrals.amount);
            printf("5. Equip one platoon of serfs as soldiers\t500 florins\n");
            printf("\nYou have %d gold florins.\n", city.treasury.coffers);
            printf("\nTo continue, enter q. To compare standings, enter 6\n");
            printf("Your choice: ");
            fgets(string, 255, stdin);
            val = static_cast<int>(atoi(string));
            switch(val)
            {
                case 1: BuyMarket(); break;
                case 2: BuyMill(); break;
                case 3: BuyPalace(); break;
                case 4: BuyCathedral(); break;
                case 5: BuySoldiers(); break;
                // case 6: ShowStats(MyPlayers, HowMany); // TODO: Determine what to do with this
            }
        }
        return;
    }

    void ImDead() // player *
    {
        char string[256];
        int why;

        printf("\n\nVery sad news.\n%s %s has just died\n", title.c_str(),
               name.c_str());

        if(year > 1450)
            printf("of old age after a long reign.\n");
        else
        {
            why = random(8);
            switch(why)
            {
                case 0:
                case 1:
                case 2:
                case 3: printf("of pneumonia after a cold winter in a drafty castle.\n"); break;
                case 4: printf("of typhoid after drinking contaminated water.\n"); break;
                case 5: printf("in a smallpox epidemic.\n"); break;
                case 6: printf("after being attacked by robbers while travelling.\n"); break;
                case 7:
                case 8: printf("of food poisoning.\n"); break;
            }
        }
        isDead = true;
        printf("\n(Press ENTER): ");
        fgets(string, 255, stdin);
        return;
    }

    bool Won()
    {
        return won;
    }
};
/*
// Game level
int AttackNeighbor(player *, player *);
void PlayGame(player [], int)
void PrintInstructions(void);
void NewTurn(player *, int, player [], player *);
void ShowStats(); // (player [], int)

// Player/City Level
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
