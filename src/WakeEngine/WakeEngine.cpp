#include "WakeEngine.h"

WakeEngine::WakeEngine(string title, int w, int h) {
    SDL_Init(SDL_INIT_EVERYTHING);
    wakeWindow = SDL_CreateWindow(title.c_str(),
                                  SDL_WINDOWPOS_UNDEFINED,
                                  SDL_WINDOWPOS_UNDEFINED,
                                  w,
                                  h,
                                  SDL_WINDOW_OPENGL);
    wakeRender = SDL_CreateRenderer(wakeWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    SDL_SetRenderDrawBlendMode(wakeRender, SDL_BLENDMODE_BLEND);
    TTF_Init();
    int flags = 0;
    Mix_Init(flags);
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096);
}


