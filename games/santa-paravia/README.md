# Santa Paravia

Objective of the game is to manage a city state and work your way up to King/Queen, overcoming the other city states.

## Abstractions:

Most if not all abstractions for the game are contained in one struct called *Player*. The abstractions are not separated any further than this, but if I had to convert this to modern object oriented C++, I would likely break it down into the following families of objects.

* Players
    * Associated city

* City
    * Treasury
    * Food
    * City Improvements
    * Justice system
    * Taxes
    * Military
    * Citizens

Up to six players can play the game. The names of the city states assigned to each player are fixed in a cstring array. The same goes for both male and female player titles.

Moving on past variable declarations, we find function prototypes for all the actions that would change the status of a player or a player's city, such as functions for purchasing city improvements and food. Note that all functions have a pointer to a *Player* struct as a parameter (minus main() and Random()). Random() is used to simulate fluctuating food and land prices, as well as determine harvest results and food supply damage due to pesky rats.

## Other

Game difficulty exists.
Instructions and flavor text can be printed.

Contrary to what the instructions say, a map of a player's city state cannot be drawn because the DrawMap() function is not implemented, and returns void.

## Guiding Principle
If you were forced to switch a city's controlling player, you could do so by simply changing a player's city pointer.


* Player Class Brainstorming
    * name
    * title
    * pointer-to-a-city
    * won
    * dead
    * ...

* City Class Brainstorming
private:

public:
    City(name); // gets name from name vector;
    Grain grain;
    Serfs serfs;
    ...
    UpdatePrices()
    {
        grain.UpdatePrice()
        ... other resources.updatePrice()    
    }


## Other Brainstorming

program flow

Number of Players?
create playervector
foreach player p, p.citypointer = & new City() {vector[i]} // set pointer to new city constructed with next name in cityname vector.
enter main
    while everyone isnt dead and while !somebody_won
        foreach player in playervector
            player.Go()
