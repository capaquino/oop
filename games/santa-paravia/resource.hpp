#pragma once

class Resource // should not be constructable at all, look up how to do that.
{
private:
    unsigned int _amount;

public:
    void Buy(unsigned int amt /* Treasury &t */); // modifies amount and player's gold, best way to access gold
    void Sell(); // modifies amount and player's gold, how to access gold.
};

// also need to think about market prices and how they will fluctuate,
