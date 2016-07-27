#include "game.h"

Game::Game(string windowTitle, int width, int height, int fps) {
    e = new WakeEngine(windowTitle, width, height);
    gamestate = new WakeStateManager(fps);
    running = true;
}


void Game::loop() {
    switch (gamestate->status()) {
        case LOAD: {
            int quit = gamestate->states[gamestate->getState()]->load();
            if (quit)
                running = false;
            break;
        }
        case LOGIC: {
            int quit = gamestate->states[gamestate->getState()]->logic();
            if (quit)
                running = false;
            break;
        }
        case RENDER: {
            int quit = gamestate->states[gamestate->getState()]->render();
            if (quit)
                running = false;
            break;
        }
        case QUIT: {
            int quit = gamestate->states[gamestate->getState()]->quit();
            if (quit)
                running = false;
            break;
        }
        default :
            break;
    }
    gamestate->updateState();
}
