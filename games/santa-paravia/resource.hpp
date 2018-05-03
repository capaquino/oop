#pragma once

#include "treasury.hpp"

class Resource // should not be constructable at all, look up how to do that.
{
private:
    unsigned m_amount;
public:
    void Buy(unsigned amount);
    void Sell(unsigned amount);
    unsigned price;
    unsigned demand;
};
