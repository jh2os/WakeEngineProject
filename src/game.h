#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "WakeEngine/WakeEngine.h"

class Game {
public:
    Game(string windowTitle, int width, int height);
    // Load in engine and other modules
    WakeEngine *e;
    //WakeMenu m;

    // Load in your global assets
    int load();

    // Functions for when you are in different states
    void mainMenu();
    void game();

};



#endif // GAME_H_INCLUDED
