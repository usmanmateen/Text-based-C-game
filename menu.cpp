#include <iostream>
#include <string>

using namespace std;

int main()
{
    string title = "RESTER";
    string newGame = "New Game";
    string loadGame = "Load Game";
    string exitGame = "Exit Game";
    string onlinePVP = "Online PVP";
    string systemSpecs = "System Specs";
    string testNetCode = "Test Net Code";

    // ASCII art logo
    cout << "  _______   _____  " << endl;
    cout << " /_  __/ | / /   | " << endl;
    cout << "  / /    |/ / /| | " << endl;
    cout << " / /     |_/ ___ | " << endl;
    cout << "/_/        /_/  |_| " << endl << endl;

    // Title
    cout << "Welcome to " << title << "!" << endl << endl;

    // Menu options
    cout << "Please select an option:" << endl;
    cout << "1. " << newGame << endl;
    cout << "2. " << loadGame << endl;
    cout << "3. " << exitGame << endl;
    cout << "4. " << onlinePVP << endl;
    cout << "5. " << systemSpecs << endl;
    cout << "6. " << testNetCode << endl;

    // User input
    int option;
    cout << endl << "Enter option number: ";
    cin >> option;

    // Option selection
    switch (option)
    {
        case 1:
            cout << "Starting a new game..." << endl;
            break;
        case 2:
            cout << "Loading a saved game..." << endl;
            break;
        case 3:
            cout << "Exiting the game..." << endl;
            break;
        case 4:
            cout << "Connecting to online PVP..." << endl;
            break;
        case 5:
            cout << "Displaying system specifications..." << endl;
            break;
        case 6:
            cout << "Testing network code..." << endl;
            break;
        default:
            cout << "Invalid option selected. Please try again." << endl;
            break;
    }

    return 0;
}
