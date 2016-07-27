#include "WakeState.h"

wakeState::wakeState() {
    currentStatus = LOAD;
}

WakeStateManager::WakeStateManager(int fps) {
    FPS = fps;
    FPSRate = 1000.0f/fps;
}
wakeStatus WakeStateManager::status() {
    return states[activeState]->currentStatus;
}

int wakeState::load() {return 0;}

int wakeState::logic() {return 0;}

int wakeState::render() {return 0;}

int wakeState::quit() { return 0;}

void WakeStateManager::updateState() {
    if (states[activeState]->currentStatus == LOAD) {
        states[activeState]->currentStatus = LOGIC;
    } else if (states[activeState]->currentStatus == LOGIC) {
        states[activeState]->currentStatus = FPSWAIT;
    } else if (states[activeState]->currentStatus == FPSWAIT) {
        if ( SDL_GetTicks() >= (unsigned int)targetTick && SDL_GetTicks() < (unsigned int)secondTick){
            states[activeState]->currentStatus = RENDER;
            targetTick += FPSRate;
            secondTick += FPSRate;
        } else if (SDL_GetTicks() > secondTick) {
            targetTick = secondTick + FPSRate;
            secondTick = targetTick + FPSRate;
            states[activeState]->currentStatus = LOGIC;
        }
    } else if(states[activeState]->currentStatus == RENDER) {
        states[activeState]->currentStatus = LOGIC;
    } else if( pendingState != activeState) {
        states[activeState]->currentStatus = QUIT;
    } else if (states[activeState]->currentStatus == QUIT) {
        activeState = pendingState;
        states[activeState]->currentStatus = LOAD;
    }
}

void WakeStateManager::registerState(string name, wakeState * state) {
    states[name] = state;
}

void WakeStateManager::changeState(string name) {
    pendingState = name;
}

void WakeStateManager::setState(string name) {
    activeState = name;
    states[name]->currentStatus = LOAD;
}

string WakeStateManager::getState() {
    return activeState;
}
