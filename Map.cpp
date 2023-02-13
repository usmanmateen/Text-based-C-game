#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

string hallwayDescriptions[5]={"A dark spooky hallway with cobwebs hanging from the chandlier and ceiling.",
                                "A wide and well lit hallway with mysterious symbols etched in the walls.",
                                "A narrow and maze kind hallway with strange noises.",
                                "A dim lit narrow hallway with cobwebs hanging from the lights.",
                                "Wide and empty hallway with spiders and snakes crawling."};

string forestDescriptions[5]= {"A dark and spooky forest with sense of danger lurking around every corner.",
                                "A magical forest with dense trees and and not light coming through.",
                                "A mystical forest with dense trees and creatures beyond imagination lurking in them.",
                                "A forest where you can hear birds chipring and spring fountains.",
                                "A spooky night in the forest where you can only hear warewolves."};
        
string roomDescriptions[5] = {"A dimly lit room with candles and mysterious symbols etched into the walls.", 
                              "A grand room with intricate carvings and ornate furnishings with high ceilings.", 
                              "A spacious room filled with beautiful artwork and elegant furnishings.",
                              "A rustic room with natural wood accents and a stone fireplace, creating a peaceful and inviting atmosphere.",
                              "A big room with high ceilings and chandliers with a fireplace "};

string patioDescriptions[4] = {"A peaceful outdoor sitting area with a grill and water slides but everything looks spooky and cold.", 
                                "A grand outdoor terrace with a magnificent view of mountains with clouds covering their tips you can hear warewolfs howling afar.", 
                                "A terrace like out of the books of Harry Potter so cold like Dementors have been here and no happiness is left behind",
                                "A field which has no end and looks spooky like a haunted graveyard with Zoomibies"};

string townSquareDescriptions[5]= {"The centre of the town with a wrecked fountain and broken into shops.", 
                                    "An abandoned town square with wind gusts and darkness.",
                                    "A town quare with spooky shops and back alleys.",
                                    "A strange looking alley heading towards town square with darkness.",
                                    "Centre of the town with an abandonded car and multiple vans."};



class Hallway {
    private:
        string name;
        string hDescription;
       
    public:
        Hallway(string n) {
            this->name = n;
            srand(time(0));
            hDescription = hallwayDescriptions[rand()%5];
        }

        string getName() {
            return name;
        }

        string getDescription() {
            return hDescription;
        }
};


class Forest {
    private:
        string name;
        string fDescription;
        

    public:
        Forest(string n)  {
            this->name = n;
            srand(time(0));
            fDescription = forestDescriptions[rand() % 5];
        }

        string getName() {
            return name;
        }

        string getDescription() {
            return fDescription;
        }
};

class Room {
    private:
        string name;
        string rDescription;



    public:
        Room(string n) {
            this->name = n;
            srand(time(0));
            
            rDescription = roomDescriptions[rand() % 5];
        }

        string getName() {
            return name;
        }

        string getDescription() {
            return rDescription;
        }
};

class Patio {
    private:
        string name;
        string pDescription;
        




    public:
        Patio(string n) {
            this->name = n;
            srand(time(0));

            pDescription = patioDescriptions[rand() % 4]; 
        }

        string getName() {
            return name;
        }

        string getDescription() {
            return pDescription;
        }
};

class TownSquare {
    private:
        string name;
        string tDescription;
        


    public:
        TownSquare(string n) {
            this-> name = n;
            srand(time(0));
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
    Room room1("Mysterious Room");
    Hallway hallway1("Spooky Park");
    Forest forest1 ( "Wailing woods");
    Patio patio1("Cold open space");
    TownSquare townSquare("Town Square");

    cout << room1.getName() << ": " << room1.getDescription() << endl;
    cout << hallway1.getName() << ": " << hallway1.getDescription() << endl;
    cout << forest1.getName() << ": " << forest1.getDescription() << endl;
    cout << patio1.getName() << ": " << patio1.getDescription() << endl;
    cout << townSquare.getName() << ": " << townSquare.getDescription() << endl;

    return 0;
}
//Room room1("Living Room", "A cozy living room with a fireplace and comfortable chairs.");

// new
//Room room1("Living Room", "A cozy living room with a fireplace and comfortable chairs.");
//Hallway hallway1("Main Hallway", "A long hallway connecting the various rooms in the house.");
//Forest forest("Mystic Forest", "A dense forest with tall trees and a variety of wildlife.");
//Patio patio("Back Patio", "A peaceful outdoor area with a grill and seating area.");
//TownSquare townSquare("Town Square", "The center of the town with a fountain and shops surrounding it.");
