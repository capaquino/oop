//
// Created by nad on 1/23/18.
//
#pragma once

#include <iostream>
#include <bitset>

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

enum Suit
{
    Hearts = 0,
    Diamonds,
    Spades,
    Clubs
};

class Card
{
private:
    unsigned char bitfield;

public:
    //Card() = default;
    Card();
    Card(const Card&);
    Card(Rank, Suit);
    ~Card();
    Rank GetRank() const;
    Suit GetSuit() const;
    bool operator==(Card) const;
    bool operator!=(Card) const;
    bool operator>(Card) const;
    bool operator<(Card) const;
    bool operator>=(Card) const;
    bool operator<=(Card) const;
    friend std::ostream& operator<<(std::ostream &out, const Card&);
};
