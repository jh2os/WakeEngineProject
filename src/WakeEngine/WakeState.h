#ifndef WAKESTATE_H_INCLUDED
#define WAKESTATE_H_INCLUDED

#include <map>
#include <string>
#include <SDL2/SDL.h>

using namespace std;

enum wakeStatus {
    LOAD,
    LOGIC,
    FPSWAIT,
    RENDER,
    QUIT,
};
class wakeState {
public:
    wakeState();
    wakeStatus currentStatus;
    virtual int load();
    virtual int logic();
    virtual int render();
    virtual int quit();
};

class WakeStateManager {
private:
    int FPS;
    int FPSRate;
    float targetTick;
    float secondTick;
    string activeState;
    string pendingState;
public:
    map<string, wakeState*> states;
    WakeStateManager(int FPS);
    wakeStatus status();
    void updateState();
    void registerState(string name, wakeState *state);
    void changeState(string state);
    void setState(string state);
    string getState();

};

#endif // WAKESTATE_H_INCLUDED
