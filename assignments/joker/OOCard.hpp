#pragma once

class BaseCard
{
    // Things common for all cards... card material?
};

class PlayingCard : BaseCard
{
protected:
    Rank rank;
    Suit suit;
public:
    Rank GetRank();
    Suit GetSuit();
};

class JokerCard : BaseCard
{
protected:
    enum Color
    {
        Red,
        Black
    } color;
public:
    Color GetColor();
};

class SnickeringJokerCard : oopJokerCard
{
public:
    bool snickering;
};

// More fun stuff

class MagicCard : BaseCard
{
protected:
    bool foil;
public:
    bool IsFoil(); // ... const bool foil ㅇㅋ?
};

class CreatureCard : MagicCard
{
public:
    int power;
    int toughness;
};
