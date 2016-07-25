#ifndef WAKEENGINE_H_INCLUDED
#define WAKEENGINE_H_INCLUDED

#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <sstream>
//#include <stdio>
#include <string>
#include <cmath>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <map>
#include <fstream>

using namespace std;

class WakeEngine {
private:
    SDL_Window *wakeWindow;
    SDL_Event wakeEvent;
    SDL_Renderer *wakeRender;
    map<string, TTF_Font *> font;
    map<string, Mix_Chunk *> sound;
    map<string, Mix_Music *> music;
    //vector<string> errors;

    //SDL_Texture * loadImg(string imagePath);
public:
    WakeEngine(string title, int w, int h);
    void loadTexture(string name, string filename);
    void loadFont(string name, string filename, int size);
    void loadSound(string name, string filename);
    void loadMusic(string name, string filename);

    //void alertErrors();
    //void logErrors(string filename);
    SDL_Texture texture(string texture);
    TTF_Font font(string font);
    Mix_Chunk sound(string sound);
    Mix_Music music(string music);

    draw(string texture, SDL_Rect* srcrect, SDL_Rect* dstrect, double angle SDL_Point* center,SDL_RendererFlip flip)
    draw(string texture, SDL_Rect* srcrect, SDL_Rect* dstrect);
    draw(string texture, int x, int y);
    //string int2str(int num);
    //int string2int(string num);

};

#endif // WAKEENGINE_H_INCLUDED
