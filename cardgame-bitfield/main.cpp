#include <iostream>
#include <cstdlib>  // srand, rand
#include <ctime>    // time
#include <cassert>

#include "Card-bitfield.hpp"

int main()
{
    Card c_default; // Default Constructor

    // Generate random card
    std::srand(std::time(NULL));
    int randomRank = std::rand() % 13;
    int randomSuit = std::rand() % 4;
    Rank r = (Rank)randomRank;
    Suit s = (Suit)randomSuit;


    Card c1 {r, s}; // Normal Constructor
    Card c2 = c1;   // Copy Constructor
    assert(c1.GetRank() == r); // Member verification
    assert(c1.GetSuit() == s); // ^
    assert(c2 == c1); // operator== verification

    c2 = c_default;
    assert(c2 != c1); // operator!= verification

    // operators > < >= <= verification
    // Ace is low
    // Suit doesn't matter. https://en.wikipedia.org/wiki/High_card_by_suit
    c1 = {Rank::Ace, Suit::Spades};
    c2 = {Rank::Queen, Suit::Diamonds};
    assert(c2 > c1);
    assert(c1 < c2);
    assert(c2 >= c1);
    assert(c1 <= c2);

    // operators >= <= additional verification on in case of ==
    c1 = c2;
    assert(c1 >= c2);
    assert(c1 <= c2);

    // friend operator<< verification, bitfields will be the same.
    std::cout << "c1.bitfield: " << c1 << std::endl;
    std::cout << "c2.bitfield: " << c2 << std::endl;

    return 0;
}
