#include <iostream>
#include <string>
#include <vector>
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

string roomAscii[5] = {
    " __________________\n"
    "|                  |\n"
    "|      Room        >\n"                
    "| _________________|\n",

    " ________________ \n"
    "|                 |\n"
    "<   Living Room   |\n"                
    "| ________________|\n",

    " _____________\n"
    "|            |\n"
    "|   Kitchen  |\n"                
    "| ___________>\n",

    " _________________________\n"
    "|                         |\n"
    "|   Bedroom               |\n"                
    "| ________________________>\n",

    " ______________\n"
    "<             |\n"
    "|   Bathroom  |\n"                
    "| ____________|\n"
};



string hallwayAscii [5]= {
    "----------------------------------------------------------- Paintings on wall|\n"
    "|                      cobwebs                                               |\n"
    "|      Hallway                                                      Chandlier|\n"                
    "|-----------------------------------------------------------fireplace--------|\n",

    "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n"
    "|                                                      Big round table                       |\n"
    "|             Hallway                                                    Skulls in a wardrobe|\n"
    "|                                                      Cracked windows                       |\n"
    "||||||||||||||||||||||||||||||||||||||||||||||||||fire place||||||||||||||||||||||||||||||||||\n",

    "..............................................................................................\n"
    "|                                                                                            |\n"
    "|                           Hallway                                                          |\n"
    "|                                                                                            |\n"
    ".............................................................................................\n",

    ".......................................................\n"
    "|                         |||                         |\n"
    "|                         |||                         |\n"
    "|                         |||                         |\n"
    ".......................................................\n",

    "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n"
    "|                        |                                |\n"
    "|        Hallway       |                                  |\n"
    "|                        |                                |\n"
    "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n"
};

string forestAscii[5] ={
    "              /\\\n"
    "             //\\\\\n"
    "            ///\\\\\\\n"
    "           ////\\\\\\\\\n"
    "          /////\\\\\\\\\\\n"
    "         //////\\\\\\\\\\\\\n"
    "        ///////\\\\\\\\\\\\\\\n"
    "       ////////\\\\\\\\\\\\\\\\\n"
    "      /////////\\\\\\\\\\\\\\\\\\\n"
    "            ||||\n"
    "            ||||\n"
    "            ||||\n"
    "            ||||\n"
    "            ||||\n"
    "            ||||\n"
    "            ||||\n"
    "            ||||\n"
    "            ||||\n"
    "            ||||\n"
    "            ||||\n"
    "            ||||\n",

    "    /\\          \n"
    "   //\\\\       \n"
    "  //  \\\\\\     \n"
    " //    \\\\\\    \n"
    "//  /\\  \\\\\\  \n"
    "/____\\/_\\\\\\/\n"
    "\\      /   /\n"
    " \\____/___/ \n"
    " // \\\\ \\\n"
    "//   \\\\\\\n"
    "/     \\\\\\\n"
    "        \\\\\\\n"
    "        //\\\\\n"
    "       //  \\\\\\\n"
    "      // /\\\\ \\\\\\\n"
    "     //      \\\\\\\n"
    "            \n"
    "            \n"
    "            \n"
    "            \n"
    "            \n"
    "            \n",

    "                   ;,_            ,\n"
    "                 _uP~'b          d'u,\n"
    "                dP'   'b       ,d'  b,\n"
    "               d'    , `b     d''   `b\n"
    "              l] [    ] [   ]'      |\n"
    "              Ol ?    ?    p   R    ;\n"
    "               `l '._`-'_.'`._ d' `u   ,\n"
    "                `~'  `~~'`     nnmmn\n",
    
    "        /\\    /\\ \n"
    "      //\\\\_//\\\\\n"
    "     //   _   \\\\\n"
    "    //  // \\   \\\\\n"
    "   //  //   \\   \\\\\n"
    "  //  //     \\   \\\\\n"
    " //  //       \\   \\\\\n"
    "           \n"
    "           \n"
    "     /|||\\ \n"
    "    ( 0 0 )\n"
    "      ---   \n"
    "           \n"
    "           \n"
    "           \n"
    "           \n"
    "           \n"
    "           \n"
    "           \n"
    "           \n"
    "           \n",

    "           /\n"
    "          <  >\n"
    "           \\/\n"
    "           /\\\n"
    "          /  \\\n"
    "         /++++\\\n"
    "        /  ()  \\\n"
    

};


string patioAscii[5] = {
    "              .-~~~-.\n"
    "  .- ~ ~-(       )_)\n"
    " /                     \\\n"
    "(           ______     )\n"
    " \\         /      \\   /\n"
    "  \\     /~\\  ~~   /  \\\n"
    "   ;     _\\/_)    ;   ;\n"
    "   |         |   ;    ;\n"
    "   |  -   - /         |\n"
    " /          \\_         ;\n"
    "(          /  )        )\n"
    " \\        (   )       /\n"
    "  `~~`~\\ `--' /--'~`~'\n"
    "          ~~~",

    "               ,:/+/.\n"
    "           .:/--'\"\"-\\\\,\n"
    "         .:\"'         \\\\;\n"
    "      .:\"\"          .:/;.\n"
    "    .\"             /:/  \\\n"
    "   /               .\"    \\\n"
    "  .;                  \\    ;\n"
    "  ::                   ;   :\n"
    "  ::;                   ;  :\n"
    "  `:::                   ; ;\n"
    "   `:::                   ;:\n"
    "    `:::;                ;\"\n"
    "      `\"\"\"---...__...---\"\"`",

    "     ___________________________________\n"
    "    /                          \\      /   \\\n"
    "   |                             |  /      \\\n"
    "   |                             |/         |\n"
    "   |                             /           \\\n"
    "   |                            /             |\n"
    "   |                           /              |\n"
    "   |                           \\             |\n"
    "   |                             \\           /\n"
    "   |                              \\________/\n"
    "   |                                 |     |      \n"
    "   |                                 |     |    \n"
    "    \\                                 \\__/\n"
    "     \\                                |    | \n"
    "      \\__________________|    |_________/", 


    "   .-^-.\n"
    "  /_/__\\\\n"
    " ' ' | ` `\n"
    "    \\|\n"
    "    |`\n"
    "    | \n"
    "    | \n"
    "   / \\\n"

};



string townSquareAscii[5] = {
    "                 /\\                              \n"
    "                /  \\                             \n"
    "      ________/____\\________                    \n"
    "      |____________________|                     \n"
    "        |  |                     |  |            \n"
    "        |__|                     |__|            \n",

    "                    .-^-._    .-'/_\\`-.\n"
    "                  .'      `\\/`     \\  `.\n"
    "                 /     _    \\        `\\ \n"
    "                 |    (@)   /        |\n"
    "                 \\         /         /\n"
    "                  `\\__`-` /        /\n"
    "                        `  _  ' `    \n",

    "      ______\n"
    "     /      \\            /|\n"
    "    /        \\          //|\n"
    "   /__________\\________/__|_\n"
    "   |                        |\n"
    "   | [] [] [] [] [] [] [] [] |        \n"
    "   | [] [] [] [] [] [] [] [] |          \n"
    "   |                        |          \n",

    "        ________                   ________        \n"
    "       |        |                 |        |      \n"
    "       |________|________________|________|     \n"
    "      / / / / / / / / / / / / / / / / / / / /\\   \n"
    "     / / / / / / / / / / / / / / / / / / / / /\\ \n"
    "    |_________________________________________|\n",

    "               ____     _____\n"
    "             /     \\  /      \\  \n"
    "            /        /        \\ \n"
    "           /________/_________\\\n"
    "          /   _____________    \\\n"
    "         /   /             \\    \\ \n"
    "        /   /               \\    \\\n"
    "       /__/                 \\___\\\n"
};
