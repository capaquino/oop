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

struct Serfs : People
{
    int incoming;
    int dead;
    int fleeing;
    int transplanted;
};

struct Soldiers : People
{
    int upkeep;
};

struct Events
{
    int amount;
    int amountEffected;
};

struct Treasury
{
    int coffers;
};
