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
        string type;

        
        weapon() {
            damage = 0;
            range = 0;
            type = "Unknown";
        }
        weapon(int d, int r, string t) {
            damage = d;
            range = r;
            type = t;
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

int selectWeapon(vector<weapon>& weapons) {
    cout << "Weapons in bagpack:" << endl;
    for (int i = 0; i < weapons.size(); ++i ) {
        cout << i+1 << ". " << weapons[i].type << endl;
    }
    int choice;
    cout << "Enter the number of the weapon you wish to choose: ";
    cin >> choice;
    while (choice < 1 || choice > weapons.size()) {
        cout << "Void choice. Please enter a number between 1 and " << weapons.size() << ": ";
        cin >> choice;
    }
    return choice-1;
}
int selectHealing(vector<healing>& healings) {
    cout << "Healing items in backpack:" << endl;
    for (int i = 0; i < healings.size(); ++i ) {
        cout << i+1 << ". " << healings[i].type << endl;
    }
    int choice;
    cout << "Enter the number of the healing item you wish to use: ";
    cin >> choice;

    while (choice < 1 || choice > healings.size()) {
        cout << "Invalid choice. Please enter a number between 1 and " << healings.size() << ": ";
        cin >> choice;
    }
    return choice-1;
}

char switchItem(vector<weapon>& weapons, vector<healing>& healings){
    cout << "Do you want to switch to a weapon or healing item? Enter 'w' for weapon or 'h' for healing: ";
    char choice;
    cin >> choice;
    while (choice != 'w' && choice != 'h') {
        cout << "Invalid choice. Please enter 'w' for weapon or 'h' for healing: ";
        cin >> choice;
    }
    return choice;
}

int main() {


    
    vector<weapon> weapons;
    weapons.push_back(weapon(20, 2, "Sword"));
    weapons.push_back(weapon(60, 10, "Shotgun"));
    weapons.push_back(weapon(30, 15, "SMG"));
    weapons.push_back(weapon(10, 1, "Melee"));
    weapons.push_back(weapon(50, 20, "TAQ-56"));
    weapons.push_back(weapon(40, 50, "M4"));
    weapons.push_back(weapon(40, 30, "Pistol"));
    weapons.push_back(weapon(100, 100, "Heavy sniper"));


    vector<healing> healings;
    healings.push_back(healing(20, "Bandage"));
    healings.push_back(healing(50, "First Aid Kit"));
    healings.push_back(healing(100, "Medkit"));

    char choice = switchItem(weapons, healings);



    int itemIndex;
    if (backpack::item_equiped == 0) {
        itemIndex = selectWeapon(weapons);
        weapon chosenWeapon = weapons[itemIndex];
        cout << "You have chosen the " << chosenWeapon.type << "!" << endl;
        cout << "Damage: " << chosenWeapon.damage << endl;
        cout << "Range: " << chosenWeapon.range << endl;
    } else {
        itemIndex = selectHealing(healings);
        healing chosenHealing = healings[itemIndex];
        cout << "You have chosen the " << chosenHealing.type << "!" << endl;
        cout << "Restores: " << chosenHealing.health << " health" << endl;
    }

   


    if (choice == 'w') {
        int itemIndex = selectWeapon(weapons);
        weapon chosenWeapon = weapons[itemIndex];
        cout << "You have switched to the " << chosenWeapon.type << "!" << endl;
        cout << "Damage: " << chosenWeapon.damage << endl;
        cout << "Range: " << chosenWeapon.range << endl;
        
    } else {
        int itemIndex = selectHealing(healings);
        healing chosenHealing = healings[itemIndex];
        cout << "You have switched to the " << chosenHealing.type << "!" << endl;
        cout << "Restores: " << chosenHealing.health << " health" << endl;
    }
    


    return 0;

}