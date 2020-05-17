#pragma once
#include "SDL.h"
#include "Game.hpp"
#include <iostream>
using namespace std;

class LTexture
{
private:
    // SDL_Texture *m_texture;
    // void *mPixels;
    // int mPitch;
    // int mwidhth;
    // int mheight;

public:
    LTexture();
    ~LTexture();
    static SDL_Texture *LoadTexture(const char *filename, SDL_Renderer *ren);
    // bool loadFromFile(string);
    // bool loadFromRenderedText(string, SDL_Color);
    // bool createBlank(int, int);
    // void free();
    // void setColor(int, int, int);
    // void setBlendMode(SDL_BlendMode);
    // void setAlpha(int);
    // int getHeight();
    // int getWidth();
};