#ifndef SPLASHSTATE_H_INCLUDED
#define SPLASHSTATE_H_INCLUDED

#include "game.h"
#include "WakeEngine/WakeEngine.h"
#include "WakeEngine/WakeState.h"

class SplashState : public wakeState {
private:
    WakeEngine *e;
    unsigned int time;
    int fadevar;
    int soundChan;
public:
    SplashState(WakeEngine *engine);
    int load();
    int logic();
    int render();
    int quit();
};


#endif // SPLASHSTATE_H_INCLUDED
