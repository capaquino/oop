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
    SantaParaviaGame(int numberOfPlayers, std::vector<std::string> playerNames)
    {
        // Populate the game's cities vector
        for (int i=0; i<numberOfPlayers; i++)
        {
            // Ask male or female here.

            players.push_back(Player(playerNames.at(i), cityNames.at(i)));
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
};
