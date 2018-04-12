#pragma once

// Normal Card
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

enum Type { Normal, Joker };

enum Color { Red, Black };

class NormalCard
{
private:
    unsigned char bitfield;

public:
    NormalCard() = default;
    NormalCard(const NormalCard&);
    NormalCard(Rank, Suit);
    Rank GetRank() const;
    Suit GetSuit() const;
    bool operator==(NormalCard) const;
    bool operator!=(NormalCard) const;
    bool operator>(NormalCard) const;
    bool operator<(NormalCard) const;
    bool operator>=(NormalCard) const;
    bool operator<=(NormalCard) const;
    friend std::ostream& operator<<(std::ostream &out, const NormalCard&);
};

class JokerCard
{
private:
public:
    Color color;
    JokerCard() = default;
    JokerCard(Color c) : color(c) {}
};

class Card
{
private:
    Type type;
    union Details
    {
        NormalCard normal;
        JokerCard joker;
        Details(NormalCard n) : normal(n) {}
        Details(JokerCard j) : joker(j) {}
    } details;

public:
    Card() = default;
    Card(NormalCard n) : type(Type::Normal), details(n) {}
    Card(JokerCard j) : type(Type::Joker), details(j) {}

    Type GetType();

    // normal card specific
    bool IsNormal();
    NormalCard GetNormal();
    Rank GetRank();
    Suit GetSuit();

    // joker specific
    bool IsJoker();
    JokerCard GetJoker();
    Color GetColor();



};
