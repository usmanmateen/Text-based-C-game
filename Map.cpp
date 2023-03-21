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
       
    public:

        Hallway(string n) :map(n) {
            this->name = n;
            
            hDescription = hallwayDescriptions[rand()%5];
        }

        string getName() {
            return name;
        }

        string getDescription() {
            return hDescription;
        }
};


class Forest :public map {
    private:
        string name;
        string fDescription;
        

    public:
        Forest(string n) :map(n) {
            this->name = n;
            
            fDescription = forestDescriptions[rand() % 5];
        }

        string getName() {
            return name;
        }

        string getDescription() {
            return fDescription;
        }
};

class Room : public map {
    private:
        string name;
        string rDescription;



    public:
        Room(string n) :map(n){
            this->name = n;
            
            
            rDescription = roomDescriptions[rand() % 5];
        }

        string getName() {
            return name;
        }

        string getDescription() {
            return rDescription;
        }
};

class Patio :public map {
    private:
        string name;
        string pDescription;
        




    public:
        Patio(string n) :map(n){
            this->name = n;
            

            pDescription = patioDescriptions[rand() % 4]; 
        }

        string getName() {
            return name;
        }

        string getDescription() {
            return pDescription;
        }
};

class TownSquare : public map {
    private:
        string name;
        string tDescription;
        


    public:
        TownSquare(string n) :map(n) {
            this-> name = n;
            
            tDescription=townSquareDescriptions[rand() % 5];
        }

        string getName() {
            return name;
        }

        string getDescription() {
            return tDescription;
        }
};


int main() {
    srand(time(0));
    // Create instances of the different map locations
    Room room("Room");
    Hallway hallway("Long hallway");
    Forest forest("Sppoky forest");
    Patio patio("Open sapce");
    TownSquare townSquare("TownSquare");

    // Initialize the current location to the starting location
    map* currentLocation = &room;
    cout << "You are currently in the " << currentLocation->getLocation() << endl;

    // Loop to prompt the user for their desired location and move them there
    while (true) {
        // Prompt the user for their desired location
        string destination;
        cout << "Enter a location to move to (or 'quit' to stop): ";
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
        } else {
            cout << "Invalid destination." << endl;
            continue;
        }

        // Output the description of the new location
        cout << "You have moved to the " << currentLocation->getLocation() << "." << endl;
        cout << currentLocation->getDescription() << endl;
    }

    return 0;
}





