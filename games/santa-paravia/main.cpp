#include <string>
#include <iostream>
#include <sstream>
#include <vector>

#include "game.hpp"

int main(int argc, char const *argv[])
{
    // print instructions
    std::cout << "Instructions..." << std::endl;

    // get number of players
    std::cout << "Number of players?\n> ";
    std::string input;
    getline(std::cin, input);
    int number_of_players;
    std::stringstream(input) >> number_of_players;

    if (number_of_players > 0 && number_of_players <= 7)
    {
        std::vector<std::string> playerNames;

        for (int i=0; i<number_of_players; i++)
        {
            std::cout << "Player " << i+1 << "'s name?\n> ";
            std::string playerNameInput;
            getline(std::cin, playerNameInput);
            playerNames.push_back(playerNameInput);
            std::cout << std::endl;
        }

        // begin the game
        auto game = SantaParaviaGame(number_of_players, playerNames);

        // play the game
        int winner = game.Play();
        std::cout << "Congrats to " << playerNames.at(winner) << " for winning!\n";

    }
    else
    {
        std::cout << "The number of players entered is invalid. The number of "
        "players must be between 1 and 7." << std::endl << "Exiting." << std::endl;
        exit(1);
    }



    return 0;
}


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
