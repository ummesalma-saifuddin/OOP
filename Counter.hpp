#pragma once
#include <SDL.h>
#include <SDL_ttf.h>
#include <string.h>
class Counter
{
private:
    TTF_Font *font;
    SDL_Rect textrect;
    SDL_Color color;
    SDL_Renderer *renderer;
    SDL_Surface *textsurface;
    SDL_Texture *text;
    int xpos, ypos;

public:
    int count;
    Counter(TTF_Font *f, SDL_Color c, SDL_Renderer *ren, int xp, int yp);
    ~Counter();
    void increaseCounter();
    void decreaseCounter();
    int getCounter();
    void render();
};
