#ifndef GAMESTATE_H_INCLUDED
#define GAMESTATE_H_INCLUDED

#include "WakeEngine/WakeState.h"

class GameState : public wakeState {

public:
    int load();
    int logic();
    int render();
    int quit();
};

#endif // GAMESTATE_H_INCLUDED
