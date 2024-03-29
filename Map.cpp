#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Descriptions.h"
#include <vector>

using namespace std;

class map {
    private:
        string currentLocation;

    public:
        map(string startLocation) {
            currentLocation = startLocation;
        }

        string getLocation() {
            return currentLocation;
        }
        virtual string getDescription() {
            return "Default description";
        }
        virtual string getascii(){
            return "";
        }

        void move() {
            string destination;
            cout << "Enter a location to move to: ";
            cin >> destination;
            currentLocation = destination;
        }
};


class Hallway : public map {
    private:
        string name;
        string hDescription;
        string ascii;
    public:

        Hallway(string n) :map(n) {
            this->name = n;
            
            hDescription = hallwayDescriptions[rand()%5];
            ascii = hallwayAscii[rand()%5];
        }

        string getName() {
            return name;
        }

        string getDescription() {
            return hDescription;
        }
        string getascii(){
            return ascii;
        }
};


class Forest :public map {
    private:
        string name;
        string fDescription;
        string ascii;

    public:
        Forest(string n) :map(n) {
            this->name = n;
            
            fDescription = forestDescriptions[rand() % 5];
            ascii = forestAscii[rand()%5];
        }

        string getName() {
            return name;
        }

        string getDescription() {
            return fDescription;
        }
        string getascii(){
            return ascii;
        }
};

class Room : public map {
    private:
        string name;
        string rDescription;
        string ascii;



    public:
        Room(string n) :map(n){
            this->name = n;
            
            
            rDescription = roomDescriptions[rand() % 5];
            ascii = roomAscii[rand() % 5];
        }

        string getName() {
            return name;
        }

        string getDescription() {
            return rDescription;
        }
        string getascii(){
            return ascii;
        }
};

class Patio :public map {
    private:
        string name;
        string pDescription;
        string ascii;




    public:
        Patio(string n) :map(n){
            this->name = n;
            

            pDescription = patioDescriptions[rand() % 4]; 
            ascii = patioAscii[rand() % 4];
        }

        string getName() {
            return name;
        }

        string getDescription() {
            return pDescription;
        }
        string getascii(){
            return ascii;
        }
};

class TownSquare : public map {
    private:
        string name;
        string tDescription;
        string ascii;


    public:
        TownSquare(string n) :map(n) {
            this-> name = n;
            
            tDescription=townSquareDescriptions[rand() % 5];
            ascii = townSquareAscii[rand() % 5];
        }

        string getName() {
            return name;
        }

        string getDescription() {
            return tDescription;
        }
        string getascii(){
            return ascii;
        }
};


int main() {
    srand(time(0));
    // Create instances of the map locations
    Room room("Room");
    Hallway hallway("Long hallway");
    Forest forest("Sppoky forest");
    Patio patio("Open sapce");
    TownSquare townSquare("TownSquare");

    // Set current location to room to start the game
    map* currentLocation = &room;
    cout << "You are currently in the " << currentLocation->getLocation()<<"."<<endl<<"If at any given time you want to move back to room just type room." << endl;
    cout << "You will have to choose one of the following if you want to change location"<< endl<<endl;
    cout << "hallway"<< endl;
    cout << "townsquare"<<endl;
    cout << "forest"<<endl;
    cout << "patio"<<endl<<endl;  
   

    // Loop to move to a location on user's command
    while (true) {
        cout << "Enter your choice: ";
        string destination;
        cout << "enter a location to move to (or 'quit' to stop): ";
        cin >> destination;
        if (destination == "quit") {
            break;
        }

        // Move to the desired location if it exists
        if (destination == "hallway") {
            currentLocation = &hallway;
        } else if (destination == "forest") {
            currentLocation = &forest;
        } else if (destination == "patio") {
            currentLocation = &patio;
        } else if (destination == "townsquare") {
            currentLocation = &townSquare;
        }else if (destination == "room") {
            currentLocation = &room;    
        } else {
            cout << "Invalid destination." << endl;
            continue;
        }

        // Output the description of the new location
        cout << "You have moved to the " << currentLocation->getLocation() << "." << endl;
        cout << currentLocation->getDescription() << endl;
        cout<< currentLocation->getascii()<<endl;
    }

    return 0;
}





