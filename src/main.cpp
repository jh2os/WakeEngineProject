#include "game.h"

int main(int argc, char *argv[]) {
    Game mygame("Hello World", 640, 480);

    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION,
                         "SDL Window creation success",
                         "The window has been successfully created. Click ok to close the program",
                         NULL);

    return 0;
}
