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
    Mix_Volume(-1, MIX_MAX_VOLUME);
    Mix_VolumeMusic(MIX_MAX_VOLUME);
}

void WakeEngine::loadGlobalTexture(string title, string filename) {
    SDL_Surface *bmp = SDL_LoadBMP(filename.c_str());
    SDL_SetColorKey(bmp, SDL_TRUE, SDL_MapRGB(bmp->format, 0, 0xFF, 0xFF));
    globalTexture[title] = SDL_CreateTextureFromSurface(wakeRender, bmp);
    SDL_FreeSurface(bmp);
}

void WakeEngine::loadTexture(string title, string filename) {
    SDL_Surface *bmp = SDL_LoadBMP(filename.c_str());
    SDL_SetColorKey(bmp, SDL_TRUE, SDL_MapRGB(bmp->format, 0, 0xFF, 0xFF));
    texture[title] = SDL_CreateTextureFromSurface(wakeRender, bmp);
    SDL_FreeSurface(bmp);
}

void WakeEngine::loadGlobalFont(string name, string filename, int size) {
    globalFont[name] = TTF_OpenFont(filename.c_str(), size);
}

void WakeEngine::loadFont(string name, string filename, int size) {
    font[name] = TTF_OpenFont(filename.c_str(), size);
}

void WakeEngine::loadGlobalSound(string name, string filename) {
    globalSound[name] = Mix_LoadWAV(filename.c_str());
}

void WakeEngine::loadSound(string name, string filename) {
    sound[name] = Mix_LoadWAV(filename.c_str());
}

void WakeEngine::loadGlobalMusic(string name, string filename) {
    music[name] = Mix_LoadMUS(filename.c_str());
}

void WakeEngine::loadMusic(string name, string filename) {
    music[name] = Mix_LoadMUS(filename.c_str());
}

SDL_Texture * WakeEngine::getTexture(string tex) {
    return texture[tex];
}

TTF_Font * WakeEngine::getFont(string name) {
    return font[name];
}

Mix_Chunk * WakeEngine::getSound(string name) {
    return sound[name];
}

Mix_Music * WakeEngine::getMusic(string name) {
    return music[name];
}

SDL_Renderer * WakeEngine::renderer() {
    return wakeRender;
}


void WakeEngine::draw(string texture, SDL_Rect* srcrect, SDL_Rect* dstrect, double angle, SDL_Point* center,SDL_RendererFlip flip) {
    SDL_RenderCopy(wakeRender, getTexture(texture), NULL, NULL);
}

void WakeEngine::draw(string texture, SDL_Rect* srcrect, SDL_Rect* dstrect) {
    SDL_RenderCopy(wakeRender, getTexture(texture), NULL, NULL);
}

void WakeEngine::draw(string texture, int x, int y) {
    SDL_RenderCopy(wakeRender, getTexture(texture), NULL, NULL);
}

SDL_Rect WakeEngine::box(int x, int y, int w, int h) {
    SDL_Rect thebox;
    thebox.x = x;
    thebox.y = y;
    thebox.w = w;
    thebox.h = h;

    return thebox;
}
void WakeEngine::drawBox(int R, int G, int B, int Alpha, int x, int y, int w, int h) {
    SDL_SetRenderDrawColor(wakeRender, R, G, B, Alpha);
    SDL_Rect boxbox = box(x,y,w,h);
    SDL_RenderFillRect(wakeRender, &boxbox);
}
void WakeEngine::display() {
    SDL_RenderPresent(wakeRender);
}
void WakeEngine::setVolume(int percent) {

    percent = (percent > 100) ? 100 : percent;
    percent = (percent < 0) ? 0 : percent;

    float divisor = percent / 100;

    globalVolume = int(SDL_MIX_MAXVOLUME * divisor);
}

void WakeEngine::setSFXVolume(int percent) {

    percent = (percent > 100) ? 100 : percent;
    percent = (percent < 0) ? 0 : percent;

    float divisor = percent / 100;

    sfxVolume = int(globalVolume * divisor);
}

void WakeEngine::setMusicVolume(int percent) {

    percent = (percent > 100) ? 100 : percent;
    percent = (percent < 0) ? 0 : percent;

    float divisor = percent / 100;

    musicVolume = int(globalVolume * divisor);
}



