/*
Write a program that features a simple dynamic array of structs. 
The struct definition should itself include a dynamic array as well as other member variables.

Choose a real-world scenario that would be able to be modeled 
by these requirements (keep it simple) and code it.

Keep it simple. Here's an example (and no, you can't use it): 
my application keeps track of people who come to my booksigning. I have a struct to represent a fan. 
There will be a variable number of these struct objects since the number of attendees could vary. 
I ask each attendee for their phone number. That'll be a member variable. 
I ask each attendee for their favorite books of mine. They may have zero, one, two, or more of these favorite books. 
I can store that in a dynamic array within the struct.

Liberally comment your code in your own words to explain what you're coding.

Craft your output to fully exercise your code.
*/

//Eduardo Avila
//COMSC - 210 - 5293
//Lab 11 - Pointers 2

#include <iostream>
#include <string>

using namespace std;

//Will create a dynamic array of structs which are horror movie fans.
//Ask how many fans there are
//Ask their name and age to grab general demographic
//Ask how many other genres they like, then ask what those genres are

//Struct creation and decreation
struct HorrorEnjoyer {

    string name;
    int age;
    int maxGenres;
    string *inputGenres = nullptr;

    //ripped straight from example code
    ~HorrorEnjoyer() {
        if (inputGenres)
            delete[] inputGenres;

        inputGenres = nullptr;
    }
};

//Prototypes
void inputEnjoyer(HorrorEnjoyer *);
//void displayEnjoyer(HorrorEnjoyer *);

int main() {

    //For the input of horror fans
    int maxEnjoyers;

    cout << "How many movie fans love horror?" << endl;
    cin >> maxEnjoyers;
    cin.ignore();

    //Creates dynamic array with the input beforehand
    HorrorEnjoyer *enjoyers = new HorrorEnjoyer[maxEnjoyers];

    //Loop to run the function of inputting data into each fan
    for (int i = 0; i < maxEnjoyers; i++) {
        inputEnjoyer(&enjoyers[i]);
    }



    return 0;
}

//Definitions

//Function for inputting all the fan data
void inputEnjoyer(HorrorEnjoyer *enjoyerPtr){

    //Asks for name and age and stores them in the fan data
    cout << "Name: ";
    getline(cin, enjoyerPtr->name);

    cout << "Age: ";
    cin >> enjoyerPtr->age;
    cin.ignore();

    //Asks how many genres to create a dynamic array of that size
    cout << "How many other genres do you like: " << endl;
    cin >> enjoyerPtr->maxGenres;
    cin.ignore();

    enjoyerPtr->inputGenres = new string[enjoyerPtr->maxGenres];

    for (int i = 0; i < enjoyerPtr->maxGenres; i++) {

        cout << "Genre #" << i + 1 << ": ";
        getline(cin,enjoyerPtr->inputGenres[i]);
    }
}