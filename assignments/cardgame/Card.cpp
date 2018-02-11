//
// Created by nad on 1/23/18.
//

#include "Card.hpp"

Card::Card(Suit s, Rank r) : rank(r), suit(s) {}

std::string Card::GetSuitString()
{
    switch (this->suit) {
        case Suit::Hearts:      return "Hearts";
        case Suit::Diamonds:    return "Diamonds";
        case Suit::Spades:      return "Spades";
        case Suit::Clubs:       return "Clubs";
        default:                return "Undefined";
    }
}

std::string Card::GetRankString()
{
    switch (this->rank) {
        case Rank::Ace:     return "Ace";
        case Rank::Two:     return "2";
        case Rank::Three:   return "3";
        case Rank::Four:    return "4";
        case Rank::Five:    return "5";
        case Rank::Six:     return "6";
        case Rank::Seven:   return "7";
        case Rank::Eight:   return "8";
        case Rank::Nine:    return "9";
        case Rank::Ten:     return "10";
        case Rank::Jack:    return "Jack";
        case Rank::Queen:   return "Queen";
        case Rank::King:    return "King";
        default:            return "Undefined";
    }
}
