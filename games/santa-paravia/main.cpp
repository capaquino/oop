#include <string>
#include <iostream>
#include <sstream>
#include <vector>

#include "game.hpp"

int main(int argc, char const *argv[])
{
    // Introduction
    std::cout << "Santa Paravia and Fiumaccio\n";

    // print instructions
    std::cout << "Do you wish instructions (Y or N)?\n> ";
    std::string input;
    getline(std::cin, input);
    if (input.at(0) == 'y' || input.at(0) == 'Y')
    {
        SantaParaviaGame::PrintInstructions();
    }

    // get number of players
    std::cout << "How many people want to play (1 to 6)?\n> ";
    getline(std::cin, input);
    int number_of_players;
    std::stringstream(input) >> number_of_players;

    // get game difficulty
    std::cout << "What will be the difficulty of this game:\n1. Apprentice\n"
                 "2. Journeyman\n3. Master\n4. Grand Master\n> ";
    getline(std::cin, input);
    int difficulty;
    std::stringstream(input) >> difficulty;

    if (number_of_players > 0 && number_of_players < 7)
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
        auto game = SantaParaviaGame(number_of_players, playerNames, difficulty);

        // play the game
        int winner = game.Play();
        std::cout << "Congrats to " << playerNames.at(winner) << " for winning!\n";

    }
    else
    {
        std::cout << "The number of players entered is invalid. The number of "
        "players must be between 1 and 6." << std::endl << "Exiting." << std::endl;
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
