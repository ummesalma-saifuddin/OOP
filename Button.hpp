#pragma once
#include "LTexture.hpp"
#include "Position.hpp"
#include <string>
#include "SDL.h"
using namespace std;

class Button
{

public:
    Button(const char *textureSheet, SDL_Renderer *ren, int x, int y);
    ~Button();
    void render();
    Position *GetPosition();
    void SetPosition(Position *p);
    void update();
    void updateResize();
    void updateLoc();
    bool checkSelected();
    int getW();
    int getH();
        void updatecount();


private:
    int xpos;
    int ypos;
    int x, y;
    bool isSelected;
    SDL_Texture *objectTexture;
    SDL_Rect sourceRect, destinationRect;
    SDL_Renderer *renderer;
};