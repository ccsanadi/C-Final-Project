// Author:  Chris Csanadi
// Professor Smith
// C++ Programming - UMass - Lowell
// Spring 2016
// Final Project - Rolodex
// Card.h header file
#pragma once

#include <string>
using namespace std;

class Card 
{
public:
    //ctors
    Card();
    Card(string first, string last, string job, string address, string phone);
    // setters
    void setLastName(const string);
    void setFirstName(const string);
    void setJob(const string);
    void setAddress(const string);
    void setPhone(const string);
    //getters
    string getLastName();
    string getFirstName();
    string getJob();
    string getAddress();
    string getPhone();
    //shows card info
    void print(ostream& os);
private:
    string mLastName;
    string mFirstName;
    string mJob;
    string mAddress;
    string mPhone;
};