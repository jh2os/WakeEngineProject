#include "game.h"
#include "MainMenuState.h"
#include "GameState.h"
#include "SplashState.h"

#define HEIGHT 480
#define WIDTH 640
#define FPS 32

int main(int argc, char *argv[]) {
    Game mygame("Hello World", WIDTH, HEIGHT, FPS);
    mygame.gamestate->registerState("splash", new SplashState(mygame.e));
    mygame.gamestate->setState("splash");

    while (mygame.running) {
        mygame.loop();
    }

    return 0;
}
