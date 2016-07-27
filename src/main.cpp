#include "game.h"

int main(int argc, char *argv[]) {
    Game mygame("Hello World", 640, 480);


    while (mygame.running) {
        mygame.loop();
    }

    return 0;
}
