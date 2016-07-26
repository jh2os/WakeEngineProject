#include "game.h"

int main(int argc, char *argv[]) {
    Game mygame("Hello World", 640, 480);

    const SDL_MessageBoxButtonData buttons[] = {
        {SDL_MESSAGEBOX_BUTTON_ESCAPEKEY_DEFAULT, 0, "No"},
        {SDL_MESSAGEBOX_BUTTON_RETURNKEY_DEFAULT, 2, "Yes"},
    };
        const SDL_MessageBoxColorScheme colorScheme = {
        { /* .colors (.r, .g, .b) */
            /* [SDL_MESSAGEBOX_COLOR_BACKGROUND] */
            { 255,   0,   0 },
            /* [SDL_MESSAGEBOX_COLOR_TEXT] */
            {   0, 255,   0 },
            /* [SDL_MESSAGEBOX_COLOR_BUTTON_BORDER] */
            { 255, 255,   0 },
            /* [SDL_MESSAGEBOX_COLOR_BUTTON_BACKGROUND] */
            {   0,   0, 255 },
            /* [SDL_MESSAGEBOX_COLOR_BUTTON_SELECTED] */
            { 255,   0, 255 }
        }
    };

    const SDL_MessageBoxData messageboxdata = {
        SDL_MESSAGEBOX_INFORMATION,
        NULL,
        "GAME",
        "Good, Would you like to play the game",
        SDL_arraysize(buttons),
        buttons,
        &colorScheme
    };

    int buttonid;

    while (mygame.running) {
        SDL_ShowMessageBox(&messageboxdata, &buttonid);
        if (buttonid == -1) {
            cout << "no selection" << endl;
        }
        else {
            if (buttons[buttonid].text == "No")
                mygame.running = false;
        }

    }
    return 0;
}
