//
// Created by nad on 1/23/18.
//
#pragma once

#include <iostream>

enum Suit
{
    Hearts = 0,
    Diamonds,
    Spades,
    Clubs
};

enum Rank
{
    Ace = 0,
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King
};

class Card
{
private:
    Suit suit;
    Rank rank;

public:
    Card(Suit,Rank);
    std::string GetSuitString();
    std::string GetRankString();
};
