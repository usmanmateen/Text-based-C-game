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
        string ascii;

        weapon() {
            damage = 0;
            range = 0;
            type = "Unknown";
            bullets = 0; 
            ascii = "";
        }
        weapon(int d, int r, int b, string t, string a) { // added bullets argument
            damage = d;
            range = r;
            type = t;
            bullets = b; 
            ascii = a;
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
        string ascii;

        healing() {
            health = 0;
            type = "Unknown";
            ascii = "";
        }
        healing(int h, string t, string a) {
            health = h;
            type = t;
            ascii = a; 
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
            cout << selectedWeapon.ascii<<endl;

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
    weapons.push_back(weapon(20, 2,10, "Sword", 
          
    "      /| _______________\n"
     "O|===|* >________________>\n"
     "      \\|\n"
));
    weapons.push_back(weapon(60, 10,5, "Shotgun",

" ,______________________________________\n"
"|_________________,----------._ [____]   -=-,__  __....-----=====\n"
"               (_(||||||||||||)___________/   --                |\n"
"                  `----------'        [ ))--,                   |\n"
"                                             `,  _,--....___    |\n"
"                                               `/           I___|\n"
    ));
    weapons.push_back(weapon(30, 15, 45, "SMG",
    "⣀⣤⣤          ⢀⣤\n"
"⣼⣿⣿⣿⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣾⣿\n"
"⣿⣿   ⣿⣿⣿⣿⣿         ⣿⣿⣶⡆\n"
"⣿⣿⣄                 ⣿⣿⣿⣿⣿⣿⣿⣿\n"
"⠈⠻⢿⣷⣦⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣿⣿⠿⠇\n"
"    ⠙⣿⣿⠛⠛⠛⣿⣿⠛⠛⠛⢻⣿⠛⠛\n"
"     ⣿⣿   ⣿⣿\n"
"     ⣿⣿   ⣿⣿\n"
"     ⣿⣿   ⣿⣿\n"
"     ⣿⣿   ⣿⣿\n"
"     ⠛⠛⣿⣿⣿⠛⠛\n"
"        ⣿⣿⣿\n"
"        ⠛⠛⠛\n"
    
    
    
    
    ));
    weapons.push_back(weapon(10, 1, 10, "Melee","[]++++||=======>\n"));
    weapons.push_back(weapon(50, 20,30, "TAQ-56",
             " ___________________| \n"
        "⣿⣿⣿⣿⣿⠿⠿⠛⢻⣿⣿⣿⣿⣿⣿⡿⠿⠿⠿⠿⠿⠿==========\n"
        "⢸⡿⠿⠋⠋    ⣿⡿  ⣿⣿ \n"
        "         ⣼⣿   ⢿⣿⡇\n"
        "                ⡿⠷\n"
    
    ));
    weapons.push_back(weapon(40, 50,60,  "M4",
    
    
   " _______/]_________[/_________\n"
   "|    ____     ___|------------------------|=====\n"
   "|_ /      /  /{}|   |\n"
    "         /_/    |__|\n"
    
    
    ));
    weapons.push_back(weapon(40, 30,15, "Pistol",
                "_  __________=__\n"
                 "\\@([____]_____()\n"
                "/__/|-[____]\n"
               "/   /(( )\n"
              "/____/\n"
             "|____/\n"
    
    ));
    weapons.push_back(weapon(100, 100,8, "Heavy sniper",
    "                                   ____    _     __     _    ____\n"
    "                                 |####`--|#|---|##|---|#|--'##|#|\n"
    "                                 |____I--|#|---|##|---|#|--.__|_|\n"
" _|#)_____________________________________I -'EEEEEEEEEEEEEE'_=-.\n"
"((_____((_________________________,--------[JW](___(____(____(_==)\n     _________\n"
"                               .--|##,----o  o  o  o  o  o  o__|/`---,-,-'=========`=+==.\n"
"                               |##|_Y__,__.-._,__,  __,-.___/ J & .----.#############|##|\n"
"                               |##|              `-.|#|##|#|`===l##&   _&############|##|\n"
"                              =======-===l          |_|__|_|     &##`- __,=======.###|##|\n"
"                                                                  &__,           '======'\n"
    
    ));


    vector<healing> healings;
    healings.push_back(healing(20, "Bandage", 
    " ___________________\n"
    "|                  |\n"
    "|                  |\n"
    "|       __         |\n"
    "|      |  |        |\n"
    "|   ---    ---     |\n"
    "|  |___    ___|    |\n"
    "|      |__|        |\n"
    "|                  |\n"
    "|                  |\n"
    "|__________________|\n"
    ));
    healings.push_back(healing(50, "First Aid Kit",
    "         _____________\n"
    "       /     __      / |\n"
    "      /   __/ /_    / /| \n"
    "     /   /_  __/   / / /\n"
    "    /     /_/     / / /\n"
    "   /_____________/ / /\n"
    "   |______&______|/ /\n"
    "   |_____________|/\n"
        
    
    
    ));
    healings.push_back(healing(100, "Medkit",
    "         ______________\n"
    "        /______&______/|\n"
    "        ||       _    ||\n"
    "        ||    __| |__ ||\n"
    "        ||   |__   __|||\n"
    "        ||      |_|   ||\n"
    "        ||            ||\n"
    "        ||____________||\n"
    "        /(@)   ____   /|\n"
    "       / | |__/    '_/ |\n"
    "      /  []|_/____,^&/ /\n"
    "     /  /  //___/  /  /\n"
    "    /__/|__|____|_/  /\n"
    "    |             | /\n"
    "    |_____________|/\n"

    ));

    char choice = switchItem(weapons, healings);



    int itemIndex;
    
    
    if (choice == 'w') {
        itemIndex = selectWeapon(weapons , healings);
        weapon chosenWeapon = weapons[itemIndex];
        cout << "You have switched to the " << chosenWeapon.type << "!" << endl;
        cout << "Damage: " << chosenWeapon.damage << endl;
        cout << "Range: " << chosenWeapon.range << endl;
        cout << chosenWeapon.ascii<< endl;
    
        chosenWeapon.fire();
        }
        
      else {
        itemIndex = selectHealing(healings);
        healing chosenHealing = healings[itemIndex];
        cout << "You have switched to the " << chosenHealing.type << "!" << endl;
        cout << "Restores: " << chosenHealing.health << " health" << endl;
        cout << chosenHealing.ascii<<endl;
    }   

    return 0;

}