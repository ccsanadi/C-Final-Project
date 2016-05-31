// Author:  Chris Csanadi
// Professor Smith
// C++ Programming - UMass - Lowell
// Spring 2016
// Final Project - Rolodex
// Rolodex.cpp source file

#include "Rolodex.h"
#include "Card.h"
#include <iostream>
#include <string>

using namespace std;
using std::cout;
using std::endl;

// sort function for class methods
bool lastSort(Card name1Card, Card name2Card) 
{
    string name1LName = name1Card.getLastName(); 
    string name2LName = name2Card.getLastName();
    int i = 0;
    while ((i < name1LName.length()) && (i < name2LName.length()))
    {
        if (tolower(name1LName[i]) < tolower(name2LName[i]))
            return true;
        else if (tolower(name1LName[i]) > tolower(name2LName[i]))
            return false;
        ++i;
    }
    if (name1LName.length() < name2LName.length())
        return true;
    else
        return false;
}
// add card
void Rolodex::addCard(Card card)
{
    roloIt = roloList.begin();
    roloList.insert(roloList.begin(), card);
    roloIt = roloList.begin();
    roloList.sort(lastSort);
    while (roloIt != roloList.end())
    {
        if (!card.getLastName().compare(roloIt->getLastName()))
            return;
        else
            roloIt++;
    }
}
// remove card, if last in list, wrap to beginning
Card Rolodex::removeCard()
{
    Card temp;
    if (roloIt != roloList.end() && nextRoloIt(roloIt) == roloList.end())
    {
        roloList.erase(roloIt);
        roloIt = roloList.begin();
        Card temp = *roloIt;
    }
    else
    {
        list<Card>::iterator next = roloIt;
        next++;
        roloList.erase(roloIt);
        Card temp = *next;
        roloIt = next;
    }
    return temp;
}
// Get current card
Card Rolodex::getCurrentCard()
{
    return *roloIt;
}
// flip to next card
Card Rolodex::flip()
{
    if (roloIt != roloList.end() && nextRoloIt(roloIt) == roloList.end())
    {
        roloIt = roloList.begin();
    }
    else
    {
        ++roloIt;
    }
    return *roloIt;
}
// search for person
bool Rolodex::search(string person)
{
    int i;
    list< Card >::iterator tempit = roloIt;
    roloIt = roloList.begin();
    while (roloIt != roloList.end())
    {
        if (!roloIt->getLastName().compare(person))
            return true;
        else
            roloIt++;
    }
    for (roloIt = roloList.begin(); roloIt != roloList.end(); roloIt++)
    {
        for (i = 0; tolower(roloIt->getLastName()[0]) > tolower(person[0]); i++)
        {
            if (tolower(roloIt->getLastName()[i]) < tolower(person[i]))
                break;
            else if (roloIt->getLastName()[i] == person[i]);
            else if (roloIt->getLastName()[i] > person[i] && !roloIt->getLastName()[0])
                return true;
        }
        cout << "Name not found: " << person << endl << endl;
        return false;
    }
}
// show
void Rolodex::show(ostream& os)
{
    list< Card >::iterator temp = roloIt;
    while (roloIt.operator!= (roloList.end()))
    {
        roloIt->print(os);
        roloIt++;
    }
    roloIt = temp;
}
// function to handle iterator past end of list
std::list<Card>::iterator Rolodex::nextRoloIt(std::list<Card>::iterator iter)
{
    return ++iter;
}
