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
    map<string, SDL_Texture *> globalTexture;
    map<string, SDL_Texture *> texture;
    map<string, TTF_Font *> globalFont;
    map<string, TTF_Font *> font;
    map<string, Mix_Chunk *> globalSound;
    map<string, Mix_Chunk *> sound;
    map<string, Mix_Music *> globalMusic;
    map<string, Mix_Music *> music;
    //vector<drawAction> drawActions;
    //vector<string> errors;

    //SDL_Texture * loadImg(string imagePath);
public:
    int globalVolume;
    int sfxVolume;
    int musicVolume;

    WakeEngine(string title, int w, int h);
    void loadGlobalTexture(string name, string filename);
    void loadTexture(string name, string filename);
    void loadGlobalFont(string name, string filename, int size);
    void loadFont(string name, string filename, int size);
    void loadGlobalSound(string name, string filename);
    void loadSound(string name, string filename);
    void loadGlobalMusic(string name, string filename);
    void loadMusic(string name, string filename);

    //void alertErrors();
    //void logErrors(string filename);
    SDL_Texture * getTexture(string texture);
    TTF_Font * getFont(string font);
    Mix_Chunk * getSound(string sound);
    Mix_Music * getMusic(string music);

    void draw(string texture, SDL_Rect* srcrect, SDL_Rect* dstrect, double angle, SDL_Point* center,SDL_RendererFlip flip);
    void draw(string texture, SDL_Rect* srcrect, SDL_Rect* dstrect);
    void draw(string texture, int x, int y);

    void setVolume(int percent);
    void setSFXVolume(int percent);
    void setMusicVolume(int percent);
    //string int2str(int num);
    //int string2int(string num);

};

#endif // WAKEENGINE_H_INCLUDED
