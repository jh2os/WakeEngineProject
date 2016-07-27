#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "WakeEngine/WakeEngine.h"
#include "WakeEngine/WakeState.h"


class Game {
public:
    bool running;

    // Constructor
    Game(string windowTitle, int width, int height, int fps);

    // Load in engine and other modules
    WakeEngine *e;
    WakeStateManager *gamestate;

    // Load in your global assets
    void loop();
};



#endif // GAME_H_INCLUDED
