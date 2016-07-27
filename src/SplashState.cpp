#include "SplashState.h"

SplashState::SplashState( WakeEngine * engine) {
    e = engine;
}

int SplashState::load() {
    e->loadTexture("splash", "./assets/fearthesun.bmp");
    e->loadSound("sizzle", "./assets/sizzle.wav");
    e->loadMusic("splash", "./assets/splash.wav");

    time = SDL_GetTicks() + 4000;
    fadevar = 0;
    soundChan = Mix_PlayChannel(-1, e->getSound("sizzle"), 0);
    Mix_Volume(soundChan, MIX_MAX_VOLUME * 0.3f);
    Mix_PlayMusic(e->getMusic("splash"), 0);

    return 0;
}

int SplashState::logic() {
    if ( time < SDL_GetTicks()) {
        return 1;
    } else {

        // Fade Logo maths
        if (time - SDL_GetTicks()  < 2000)
            fadevar = (fadevar > 255) ? 255 : fadevar + 3;
        else if ( time - SDL_GetTicks() > 2000)
            fadevar = (fadevar > 0) ? 0 : fadevar - 3;
    }
    return 0;
}

int SplashState::render() {
    e->draw("splash", NULL, NULL);
    e->drawBox(0,0,0,fadevar,0,0,640,480);
    e->display();
    return 0;
}

int SplashState::quit() {
    return 0;
}
