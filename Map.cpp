//
//  Map.cpp
//  consoleGame
//
//  Created by Muhammad Usman on 10/02/2023.
//
#include <iostream>
using namespace std;
class Map{
    public:
     string Room;
     string Hallway;
     string patio;
     string forest;
     string townSquare;
    
};

int main(){
    Map room1;
    room1.Room = "Living Room";
    
    cout << room1.Room << endl;
    return 0;
}


