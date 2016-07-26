#include "game.h"

Game::Game(string windowTitle, int width, int height) {
    e = new WakeEngine(windowTitle, width, height);
    running = true;
}

int Game::load() {
    return 0;
}
