#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class Room {
    private:
        string name;
        string description;
        string roomDescriptions[3] = {"A dimly lit room with mysterious symbols etched into the walls.", 
                                      "A grand room with intricate carvings and ornate furnishings.", 
                                      "A spacious room filled with beautiful artwork and elegant furnishings."};

    public:
        Room(string n) : name(n) {
            srand(time(0));
            int randomIndex = rand() % 3;
            description = roomDescriptions[randomIndex];
        }

        string getName() {
            return name;
        }

        string getDescription() {
            return description;
        }
};

class Hallway {
    private:
        string name;
        string description;
        string hallwayDescriptions[3] = {"A dark and creepy hallway with cobwebs hanging from the ceiling.", 
                                         "A wide and well-lit hallway with beautiful paintings adorning the walls.", 
                                         "A narrow and twisting hallway with strange markings on the floor."};

    public:
        Hallway(string n) : name(n) {
            srand(time(0));
            int randomIndex = rand() % 3;
            description = hallwayDescriptions[randomIndex];
        }

        string getName() {
            return name;
        }

        string getDescription() {
            return description;
        }
};

class Forest {
    private:
        string name;
        string description;
        string forestDescriptions[3] = {"A dense forest with tall trees and a variety of wildlife.", 
                                        "A dark and foreboding forest with a sense of danger lurking around every corner.", 
                                        "A mystical forest filled with enchanted creatures and mysterious magic."};

    public:
        Forest(string n) : name(n) {
            srand(time(0));
            int randomIndex = rand() % 3;
            description = forestDescriptions[randomIndex];
        }

        string getName() {
            return name;
        }

        string getDescription() {
            return description;
        }
};

class Patio {
    private:
        string name;
        string description;
        string patioDescriptions[3] = {"A peaceful outdoor area with a grill and seating area.", 
                                       "A grand outdoor terrace with a magnificent view of the surrounding landscape.", 
                                       "A secluded garden with a tranquil pond and lush vegetation."};

    public:
        Patio(string n) : name(n) {
            srand(time(0));
            int randomIndex = rand() % 3;
            description = patioDescriptions[randomIndex];
        }

        string getName() {
            return name;
        }

        string getDescription() {
            return description;
        }
};

class TownSquare {
    private:
        string name;
        string description;
        string townSquareDescriptions[3] = {"The center of the town with a fountain and shops surrounding it.", 
                                            "A bustling town square with street performers and vendors selling their"};




