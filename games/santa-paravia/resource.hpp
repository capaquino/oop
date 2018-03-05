#pragma once

#include "Treasury.hpp"

class Resource // should not be constructable at all, look up how to do that.
{
private:
    unsigned _amount;
public:
    void Buy(unsigned amount, Treasury &t);
    void Sell(unsigned amount, Treasury &t);
    unsigned GetPrice();
};
