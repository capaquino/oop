//#include <cstdio>
#include <iostream>

#include "city.hpp"
#include "grain.hpp"
#include "player.hpp"
#include "treasury.hpp"
#include "game.hpp"

int main(int argc, char const *argv[])
{
    // Print instructions
    std::cout << "Instructions..." << std::endl;
    // Get number of players
    std::cout << "Number of players?\n> ";

    std::string input;
    char input_numberOfPlayers; // this is broken figure out how to get ints
    getline(std::cin, input);
    input_numberOfPlayers = input.at(0);

    SantaParaviaGame(input_numberOfPlayers);

    return 0;
}
