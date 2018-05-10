#pragma once

#include <string>
#include <vector>

#include "player.hpp"

class SantaParaviaGame
{
private:
    // city names from original santa paravia
    const std::vector<std::string> cityNames
    {
        "Santa Paravia",
        "Fiumaccio",
        "Torricella",
        "Molinetto",
        "Fontanile",
        "Romanga",
        "Monterana"
    };

    std::vector<Player> players;

public:
    SantaParaviaGame(int numberOfPlayers, std::vector<std::string> playerNames, int difficulty)
    {
        // Populate the game's cities vector
        for (int i=0; i<numberOfPlayers; i++)
        {
            players.push_back(Player(playerNames.at(i), cityNames.at(i), difficulty));
        }
    }

    int Play()
    {
        while(true)
        {
            for (auto &player : players)
            {

                int i;
                player.GenerateHarvest();
                player.NewLandAndGrainPrices();

                player.BuySellGrain();
                player.ReleaseGrain();

                // This game component is still a little bit broken because of
                // how I abstracted the layers.
                /*if(invadeMe == True)
                {
                    for(i = 0; i < HowMany; i++)
                        if(i != Me->WhichPlayer)
                            if(MyPlayers[i].Soldiers > (Me->Soldiers * 2.4))
                            {
                                AttackNeighbor(&MyPlayers[i], Me);
                                i = 9;
                            }
                    if(i != 9)
                        AttackNeighbor(Baron, Me);
                }*/
                player.AdjustTax();
                //DrawMap(Me); // was never implemented in original, think about implementing it in port.
                player.StatePurchases();
                player.CheckNewTitle();

                player.ProgressOneYear();
                if(player.GetCurrentYear() == player.GetYearOfDeath())
                    player.ImDead();

                if (player.HasWon())
                {
                    return &player - &players[0]; // returns the index
                }
            }
        }
    }
    // Instructions as written in the original
    static void PrintInstructions()
    {
        std::cout << "Santa Paravia and Fiumaccio\n\n";
        std::cout << "You are the ruler of a 15th century Italian city state.\n";
        std::cout << "If you rule well, you will receive higher titles. The\n";
        std::cout << "first player to become king or queen wins. Life expectancy\n";
        std::cout << "then was brief, so you may not live long enough to win.\n";
        std::cout << "The computer will draw a map of your state. The size\n";
        std::cout << "of the area in the wall grows as you buy more land. The\n";
        std::cout << "size of the guard tower in the upper left corner shows\n";
        std::cout << "the adequacy of your defenses. If it shrinks, equip more\n";
        std::cout << "soldiers! If the horse and plowman is touching the top of the wall,\n";
        std::cout << "all your land is in production. Otherwise you need more\n";
        std::cout << "serfs, who will migrate to your state if you distribute\n";
        std::cout << "more grain than the minimum demand. If you distribute less\n";
        std::cout << "grain, some of your people will starve, and you will have\n";
        std::cout << "a high death rate. High taxes raise money, but slow down\n";
        std::cout << "economic growth. (Press ENTER to begin game)\n";
    }
};
