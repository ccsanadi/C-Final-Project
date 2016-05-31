// Author:  Chris Csanadi
// Professor Smith
// C++ Programming - UMass - Lowell
// Spring 2016
// Final Project - Rolodex
// Card.cpp source file

#include "Card.h"
#include <iostream>
#include <string>

using namespace std;
using std::endl;

// Default ctor
Card::Card()
{
    mFirstName = '\0';
    mLastName = '\0';
    mJob = '\0';
    mAddress = '\0';
    mPhone = '\0';
}
// overloaded ctor
Card::Card(string first, string last, string job, string address, string phone)
{
    mFirstName = first;
    mLastName = last;
    mJob = job;
    mAddress = address;
    mPhone = phone;
}
// Setters
void Card::setFirstName(const string first)
{
    mFirstName = first;
}
void Card::setLastName(const string last)
{
    mLastName = last;
}
void Card::setJob(const string job)
{
    mJob = job;
}
void Card::setAddress(const string address)
{
    mAddress = address;
}
void Card::setPhone(const string phone)
{
    mPhone = phone;
}

// Getters
string Card::getFirstName()
{
    return mFirstName;
}
string Card::getLastName()
{
    return mLastName;
}
string Card::getJob()
{
    return mJob;
}
string Card::getAddress()
{
    return mAddress;
}
string Card::getPhone()
{
    return mPhone;
}

// Show card
void Card::print(ostream& os) {
    os << "\nName: " << getLastName() << ", " << getFirstName()
        << "\nOccupation: " << getJob() << "\nAddress: "
        << getAddress() << "\nPhone Number: " << getPhone() << endl;
}
