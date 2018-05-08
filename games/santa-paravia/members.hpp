#pragma once

struct Resource // should not be constructable at all, look up how to do that.
{
    int reserve;
    int demand;
    float price;
};

struct Revenue
{
    int rate;
    int incoming;
};

struct Building
{
    int amount;
};

struct People
{
    int population;
};

struct Events
{
    void Occur() {}
};

struct Treasury
{
    int coffers;
};
