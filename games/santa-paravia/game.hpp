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
            players.push_back(Player(playerNames.at(i), cityNames.at(i)));
        }
    }

    int Play()
    {
        while(true)
        {
            for (auto &player : players)
            {
                bool playerWon = player.TakeTurn();
                if (playerWon)
                {
                    return &player - &players[0]; // returns the index
                }
            }
        }
    }
};
