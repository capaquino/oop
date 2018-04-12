#include "UnionCard.hpp"
#include <cassert>

// Rank has thirteen values, so need 4 bits to represent
// Suit has four values so need 2 bits to represent
// xxssrrrr or could do xxrrrrss

NormalCard::NormalCard(const NormalCard& c) : bitfield(c.bitfield)
{

}

NormalCard::NormalCard(Rank r, Suit s) : bitfield((unsigned)s << 4 | (unsigned)r)
{

}

Rank NormalCard::GetRank() const
{
    return (Rank)(0x0f & bitfield); // 0000 1111
}

Suit NormalCard::GetSuit() const
{
    return (Suit)((0x30 & bitfield) >> 4); // 0011 0000
}

bool NormalCard::operator==(NormalCard c) const
{
    return bitfield == c.bitfield;
}

bool NormalCard::operator!=(NormalCard c) const
{
    return bitfield != c.bitfield;
}

bool NormalCard::operator>(NormalCard c) const
{
    return (bitfield & 0x0f) > (c.bitfield & 0x0f);
}

bool NormalCard::operator<(NormalCard c) const
{
    return (bitfield & 0x0f) < (c.bitfield & 0x0f);
}

bool NormalCard::operator>=(NormalCard c) const
{
    return (bitfield & 0x0f) >= (c.bitfield & 0x0f);
}

bool NormalCard::operator<=(NormalCard c) const
{
    return (bitfield & 0x0f) <= (c.bitfield & 0x0f);
}

// Normal Card Buddies

std::ostream& operator<<(std::ostream &out, const NormalCard &c)
{
    std::bitset<8> b {c.bitfield};
    out << b;
    return out;
    // Better way to output string representation than
    // doing 52 case switch statement on c.bitfield?
}

// Joker Card Stuff
// nothing really

// Union Card stuff
Type Card::GetType()
{
    return type;
}

// normal card specific
bool Card::IsNormal()
{
    return type == Type::Normal;
}

NormalCard Card::GetNormal()
{
    assert(IsNormal());
    return details.normal;
}

Rank Card::GetRank()
{
    return details.normal.GetRank();
}

Suit Card::GetSuit()
{
    return details.normal.GetSuit();
}

// joker specific
bool Card::IsJoker()
{
    return type == Type::Joker;
}

JokerCard Card::GetJoker()
{
    assert(IsJoker());
    return details.joker;
}

Color Card::GetColor()
{
    return details.joker.color;
}
