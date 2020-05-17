#pragma once
#include <SDL.h>
#include <SDL_ttf.h>
#include <string.h>
// class Health
// {
// private:
//     int Amount;

// public:
//     virtual void increaseHealth();
//     virtual void decreaseHealth();
// };

class Health
{
private:
    // int Amount;
    //SDL_Rect Bar_health;
    //SDL_Rect outline_bar;
    TTF_Font *font;
    SDL_Rect textrect;
    SDL_Color color;
    SDL_Renderer *renderer;
    SDL_Surface *textsurface;
    SDL_Texture *text;
    int xpos, ypos;

public:
    //Health();
    int Amount;
    Health(TTF_Font *f, SDL_Color c, SDL_Renderer *ren, int xp, int yp);
    // {
    //     Amount=25;
    //     font =f;
    //     renderer=ren;
    //     textrect.x=xp;
    //     textrect.y=yp;
    //     textsurface=TTF_RenderText_Solid(font, "health", color );

    //     text=SDL_CreateTextureFromSurface(renderer, textsurface);

    // }
    ~Health();
    void update_health();
    void render();
};