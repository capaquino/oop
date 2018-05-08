#pragma once

struct Resource // should not be constructable at all, look up how to do that.
{
    int amount;
    int demand;
    float price;
};

struct Revenue
{
    int amount;
};

struct Building
{
    bool purchased;
};

struct People
{
    int amount;
};

struct Events
{
    void Occur() {}
};
