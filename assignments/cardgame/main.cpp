#include <iostream>
#include <cstdlib>  // srand, rand
#include <ctime>    // time
#include "Card.hpp"

int main()
{
    std::srand(std::time(NULL));
    int randomSuit = std::rand() % 4;
    int randomRank = std::rand() % 13;
    Suit s = (Suit)randomSuit;
    Rank r = (Rank)randomRank;
    Card c {s, r};
    std::cout << "This card is a(n) " << c.GetRankString() << " of " << c.GetSuitString() << std::endl;
    return 0;
}
