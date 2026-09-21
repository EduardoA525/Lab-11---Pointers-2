//Eduardo Avila
//COMSC - 210 - 5293
//Lab 11 - Pointers 2

#include <iostream>
#include <string>

using namespace std;

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
void displayEnjoyer(HorrorEnjoyer *);

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

    //Cleaner title output
    cout << "\n--- HORROR ENJOYERS DATA ---\n" << endl;

    //Loop to run the function of outputting data from each fan
    for (int i = 0; i < maxEnjoyers; i++) {
        displayEnjoyer(&enjoyers[i]);
    }

    //FREE UP THE SPACE
    delete[] enjoyers;

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

    //Creates dynamic array for each genre
    enjoyerPtr->inputGenres = new string[enjoyerPtr->maxGenres];

    //Loops through each genre until it hits the max size inputted
    for (int i = 0; i < enjoyerPtr->maxGenres; i++) {

        cout << "Genre #" << i + 1 << ": ";
        getline(cin,enjoyerPtr->inputGenres[i]);
    }
}

//Function to display all the horror fans
void displayEnjoyer(HorrorEnjoyer *enjoyerPtr) {

    //Displays name, age, and how many other genres they like
    cout << "Name: " << enjoyerPtr->name << endl;
    cout << "Age: " << enjoyerPtr->age << endl;
    cout << enjoyerPtr->name << " also loves " 
         << enjoyerPtr->maxGenres << " other genres:" << endl;

    //Loop to display each genre
    for (int i = 0; i < enjoyerPtr->maxGenres; i++) {

        cout << "Genre #" << i + 1 << ": "
             << enjoyerPtr->inputGenres[i] << endl;
    }

    cout << "\n--------------------\n" << endl;
}