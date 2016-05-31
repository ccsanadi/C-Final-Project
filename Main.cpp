// Author:  Chris Csanadi
// Professor Smith
// C++ Programming - UMass - Lowell
// Spring 2016
// Final Project - Rolodex
// main.cpp source file

#include "Card.h"
#include "Rolodex.h"
#include <iostream>
#include <cstdlib>

using namespace std;
using std::getline;
using std::cout;
using std::cin;
using std::endl;

//(interactive) functions for main
void addCard(Rolodex &temp) 
{
    Card tempCard;
    string answer;

    cout << "Enter the first name: ";
    cin >> answer;
    tempCard.setFirstName(answer);

    cout << "Enter the last name: ";
    cin >> answer;
    tempCard.setLastName(answer);

    cout << "Enter person's job: ";
    cin >> answer;
    tempCard.setJob(answer);

    cin.ignore(); // clear newline from buffer

    cout << "Enter address w/ city, state, zip(if available):\n";
    getline(cin, answer);
    tempCard.setAddress(answer);

    cout << "Enter phone number: ";
    getline(cin, answer);
    tempCard.setPhone(answer);

    temp.addCard(tempCard); // Rolodex::addCard
}

void deleteCard(Rolodex &temp) 
{
    temp.removeCard();
}

void search(Rolodex &temp) 
{
    string lastName;

    cout << "\nEnter the last name: ";
    cin >> lastName;
    if (temp.search(lastName))
        temp.getCurrentCard().print(cout);
    else
        return;
}

void view(Rolodex &temp) 
{
    temp.getCurrentCard().print(cout);
}

void flipCard(Rolodex &temp) 
{
    temp.flip();
}

void listRolodex(Rolodex &temp) 
{
    temp.show(cout);
}

int main(void)
{
    Rolodex rolodex;  //create Rolodex object
    int i;
    int flag = 0;
    Card card[10];  //create list of 10 cards

    //hard code first 10 entries
    card[0].setFirstName("Tony");
    card[0].setLastName("Hanson");
    card[0].setAddress("12 E. St., NY, NY 33333");
    card[0].setJob("Writer");
    card[0].setPhone("555-9999");
    card[1].setFirstName("Jon");
    card[1].setLastName("Smyth");
    card[1].setAddress("CMU Computer Services, Pittsburg, PA");
    card[1].setJob("Computer Hardware");
    card[1].setPhone("555-1324");
    card[2].setFirstName("Alonza");
    card[2].setLastName("Heard");
    card[2].setAddress("123 Anyplace Ave, Malden, MA");
    card[2].setJob("Mechanic");
    card[2].setPhone("555-5678");
    card[3].setFirstName("Jen");
    card[3].setLastName("Reyes");
    card[3].setAddress("325 Oak Rd, Wilmington, MA");
    card[3].setJob("Graphic Artist");
    card[3].setPhone("555-4950");
    card[4].setFirstName("Alan");
    card[4].setLastName("Lupine");
    card[4].setAddress("1 Bigelow Ave., Lawrence, MA");
    card[4].setJob("Vet");
    card[4].setPhone("555-7654");
    card[5].setFirstName("Jewel");
    card[5].setLastName("Proverb");
    card[5].setAddress("34 Washington St., Waltham, MA");
    card[5].setJob("Landscaper");
    card[5].setPhone("555-3333");
    card[6].setFirstName("Paul");
    card[6].setLastName("Revere");
    card[6].setAddress("45 Commonwealth Ave., Boston, MA");
    card[6].setJob("Radical Revolutionary");
    card[6].setPhone("555-1776");
    card[7].setFirstName("Adolf");
    card[7].setLastName("Coors");
    card[7].setAddress("Boston, MA");
    card[7].setJob("Beer Manufacturer");
    card[7].setPhone("555-2337");
    card[8].setFirstName("Seymour");
    card[8].setLastName("Papert");
    card[8].setAddress("MIT");
    card[8].setJob("Lego Professor");
    card[8].setPhone("555-1111");
    card[9].setFirstName("Fred");
    card[9].setLastName("Milton");
    card[9].setAddress("12 Freedom Way, Nashua, NH");
    card[9].setJob("Sales");
    card[9].setPhone("555-9981");

    for (i = 0; i < 10; i++)
    {
        rolodex.addCard(card[i]);
    }

    rolodex.getCurrentCard();

    while (flag == 0)
    {
        cin.exceptions(ios_base::failbit);
        try
        {
            cout << "\n0...Add card" << endl;
            cout << "1...Delete card" << endl;
            cout << "2...Search cards" << endl;
            cout << "3...View current card" << endl;
            cout << "4...Flip to next card" << endl;
            cout << "5...List cards of current Rolodex" << endl;
            cout << "6...Done" << endl;
            cout << "\nEnter your selection: " << endl;
            
        
            int option;
            cin >> option;

            if (option == 0)
            {
                addCard(rolodex);
                flag = 0;
            }
            else if (option == 1)
            {
                deleteCard(rolodex);
                flag = 0;
            }
            else if (option == 2)
            {
                search(rolodex);
                flag = 0;
            }
            else if (option == 3)
            {
                view(rolodex);
                flag = 0;
            }
            else if (option == 4)
            {
                flipCard(rolodex);
                flag = 0;
            }
            else if (option == 5)
            {
                listRolodex(rolodex);
                flag = 0;
            }
            else if (option == 6)
            {
                cout << "Goodbye." << endl;
                flag = 1;
                break;
            }
        }
        catch (const ios_base::failure& e)
        {
            cout << "Come again?" << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
            flag = 0;
            continue;
        }   
    }
    return 0;
}