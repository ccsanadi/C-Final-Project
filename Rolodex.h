// Author:  Chris Csanadi
// Professor Smith
// C++ Programming - UMass - Lowell
// Spring 2016
// Final Project - Rolodex
// Rolodex.h header file

#pragma once

#include "Card.h"
#include <string>
#include <list>
#include <iterator>
#include <algorithm>

using namespace std;

class Rolodex
{
public:
    void addCard(Card);
    Card removeCard();
    bool search(string);
    Card getCurrentCard();
    Card flip();    
    void show(ostream& os);
    //public function
    std::list<Card>::iterator nextRoloIt(std::list<Card>::iterator);
private:
    list< Card > roloList;
    list< Card >::iterator roloIt;
};
