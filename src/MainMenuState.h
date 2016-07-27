#ifndef MAINMENUSTATE_H_INCLUDED
#define MAINMENUSTATE_H_INCLUDED

#include "WakeEngine/WakeState.h"

class MainMenuState : public wakeState {

public:
    int load();
    int logic();
    int render();
    int quit();
};


#endif // MAINMENUSTATE_H_INCLUDED
