#pragma once

#include "Treasury.hpp"

class Resource // should not be constructable at all, look up how to do that.
{
private:
    unsigned _amount;
    unsigned _price;
public:
    void Buy(unsigned amt, Treasury &t);
    void Sell(unsigned amt, Treasury &t);
    unsigned GetPrice();
};
// whats the best way to access gold?

// also need to think about market prices and how they will fluctuate,
