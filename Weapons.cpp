#include <iostream>
#include <vector> // vector import
#include <string> //import string package

using namespace std;

class backpack {
    public:
        static int size;
        static vector<vector<int> > bag; // Items have sets of attributes.
        static vector<string> itemNames;
        static int item_equiped;
        string name;
        int position;
};

class weapon : public backpack {
    public:
        int damage;
        int range;
        int bullets; // added bullets member variable
        string type;

        weapon() {
            damage = 0;
            range = 0;
            type = "Unknown";
            bullets = 0; // initialize bullets to zero
        }
        weapon(int d, int r, int b, string t) { // added bullets argument
            damage = d;
            range = r;
            type = t;
            bullets = b; // set the initial number of bullets
        }

        

        void reload(int numBullets) {
            if (numBullets > 40) {
                numBullets = 40;
            }
        cout << "Changing to a fresh Mag for " << type << " with " << numBullets << endl;
        bullets += numBullets;

        }
        void fire() {
            if (bullets > 0) {
                bullets--;
                cout << "Bang! Bullets left: " << bullets << endl;
            } else {
                cout << "Click! Out of bullets." << endl;
                
    }
}

};

class healing : public backpack {
    public:
        int health;
        string type;

        healing() {
            health = 0;
            type = "Unknown";
        }
        healing(int h, string t) {
            health = h;
            type = t;
        }
};

int backpack::size = 0;
vector<vector<int> > backpack::bag;
vector<string> backpack::itemNames;
int backpack::item_equiped = 0;

char switchItem(vector<weapon>& weapons, vector<healing>& healings){
    cout << "Do you want to switch to a weapon or healing item? Enter 'w' for weapon or 'h' for healing: ";
    char choice;
    cin >> choice;
    while (choice != 'w' && choice != 'h') {
        cout << "Not a valid choice. Please enter 'w' for weapon or 'h' for healing: ";
        cin >> choice;
    }
    return choice;

}
int selectHealing(vector<healing>& healings){
    cout << "Healing items in backpack:" << endl;
    for (int i = 0; i < healings.size(); ++i ) {
        cout << i+1 << ". " << healings[i].type << endl;
    }
    int choice;
    cout << "Enter the number of the healing item you wish to use: ";
    cin >> choice;

    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    while (choice < 1 || choice > healings.size()) {
        if (cin.fail()) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Invalid choice. Please enter a number between 1 and " << healings.size() << ": ";
            return -1;
        }
        cout << "Invalid choice. Please enter a number between 1 and " << healings.size() << ": ";
        cin >> choice;
    }
    return choice-1;
}

int selectWeapon(vector<weapon>& weapons, vector<healing>& healings) {
    while (true) {
        cout << "Weapons in backpack:" << endl;
        for (int i = 0; i < weapons.size(); ++i ) {
            cout << i+1 << ". " << weapons[i].type << " - Bullets: " << weapons[i].bullets << endl;
        }
        int choice;
        cout << "Enter the number of the weapon you wish to choose, enter 'h' to switch to healing items, or enter 'q' to quit: ";
        cin >> choice;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Invalid choice. Please enter a number between 1 and " << weapons.size() << ", 'h' to switch to healing items, or 'q' to quit: ";
        } else if (choice == 'q') {
            cout << "Quitting weapon selection." << endl;
            return -1;
        } else if (choice == 'h') {
            return -2;
        } else if (choice < 1 || choice > weapons.size()) {
            cout << "Invalid choice. Please enter a number between 1 and " << weapons.size() << ", 'h' to switch to healing items, or 'q' to quit: ";
        } else {
            choice--; // subtract 1 to get the index of the selected weapon
            weapon selectedWeapon = weapons[choice];
            cout << "You have selected the " << selectedWeapon.type << "." << endl;

            while (true) {
                cout << "Enter 'f' to fire or 'r' to reload, or enter 'h' to switch to healing items, or enter 'q' to quit: ";
                char action;
                cin >> action;
                if (action == 'q') {
                    cout << "Quitting weapon action." << endl;
                    return -1;
                } else if (action == 'h') {
                    return -2;
                } else if (action != 'f' && action != 'r') {
                    cout << "No such action in directory. Please enter 'f' to fire or 'r' to reload, or enter 'h' to switch to healing items, or enter 'q' to quit: ";
                } else {
                    if (action == 'r') {
                        int numBullets;
                        cout << "Mag Size ";
                        cin >> numBullets;
                        selectedWeapon.reload(numBullets);
                    } else {
                        selectedWeapon.fire();
                    }
                }
            }
        }
    }
}



int selectHealing(vector<healing>& healings){
    cout << "Healing items in backpack:" << endl;
    for (int i = 0; i < healings.size(); ++i ) {
        cout << i+1 << ". " << healings[i].type << endl;
    }
    int choice;
    cout << "Enter the number of the healing item you wish to use: ";
    cin >> choice;

    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    while (choice < 1 || choice > healings.size()) {
        if (cin.fail()) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Invalid choice. Please enter a number between 1 and " << healings.size() << ": ";
            return -1;
        }
        cout << "Invalid choice. Please enter a number between 1 and " << healings.size() << ": ";
        cin >> choice;
    }
    return choice-1;
}


int main() {

    vector<weapon> weapons;
    weapons.push_back(weapon(20, 2,10, "Sword"));
    weapons.push_back(weapon(60, 10,5, "Shotgun"));
    weapons.push_back(weapon(30, 15, 45, "SMG"));
    weapons.push_back(weapon(10, 1, 10, "Melee"));
    weapons.push_back(weapon(50, 20,30, "TAQ-56"));
    weapons.push_back(weapon(40, 50,60,  "M4"));
    weapons.push_back(weapon(40, 30,15, "Pistol"));
    weapons.push_back(weapon(100, 100,8, "Heavy sniper"));


    vector<healing> healings;
    healings.push_back(healing(20, "Bandage"));
    healings.push_back(healing(50, "First Aid Kit"));
    healings.push_back(healing(100, "Medkit"));

    char choice = switchItem(weapons, healings);



    int itemIndex;
    
    
    if (choice == 'w') {
        itemIndex = selectWeapon(weapons , healings);
        weapon chosenWeapon = weapons[itemIndex];
        cout << "You have switched to the " << chosenWeapon.type << "!" << endl;
        cout << "Damage: " << chosenWeapon.damage << endl;
        cout << "Range: " << chosenWeapon.range << endl;
    
        chosenWeapon.fire();
        }
        
      else {
        itemIndex = selectHealing(healings);
        healing chosenHealing = healings[itemIndex];
        cout << "You have switched to the " << chosenHealing.type << "!" << endl;
        cout << "Restores: " << chosenHealing.health << " health" << endl;
    }   

    return 0;

}