//
// Created by nad on 1/23/18.
//

#include "Card-bitfield.hpp"

// Rank has thirteen values, so need 4 bits to represent
// Suit has four values so need 2 bits to represent
// xxssrrrr or could do xxrrrrss

Card::Card() : bitfield(0x00)
{
    // Default card is Ace of Hearts
    // Could also make it random if I take the randomizer
    // code in main and put it here.
}

Card::Card(const Card& c) : bitfield(c.bitfield)
{

}

Card::Card(Rank r, Suit s) : bitfield((unsigned)s << 4 | (unsigned)r)
{

}

Card::~Card()
{

}

Rank Card::GetRank() const
{
    return (Rank)(0x0f & bitfield); // 0000 1111
}

Suit Card::GetSuit() const
{
    return (Suit)((0x30 & bitfield) >> 4); // 0011 0000
}

bool Card::operator==(Card c) const
{
    return bitfield == c.bitfield;
}

bool Card::operator!=(Card c) const
{
    return bitfield != c.bitfield;
}

bool Card::operator>(Card c) const
{
    return (bitfield & 0x0f) > (c.bitfield & 0x0f);
}

bool Card::operator<(Card c) const
{
    return (bitfield & 0x0f) < (c.bitfield & 0x0f);
}

bool Card::operator>=(Card c) const
{
    return (bitfield & 0x0f) >= (c.bitfield & 0x0f);
}

bool Card::operator<=(Card c) const
{
    return (bitfield & 0x0f) <= (c.bitfield & 0x0f);
}

// Buddies

std::ostream& operator<<(std::ostream &out, const Card &c)
{
    std::bitset<8> b {c.bitfield};
    out << b;
    return out;
    // Better way to output string representation than
    // doing 52 case switch statement on c.bitfield?
}
