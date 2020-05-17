#pragma once
#include "Screen.hpp"

class MainScreen
{
public:
    MainScreen(const char *textureSheet, SDL_Renderer *ren, int x, int y);
    ~MainScreen();
    void GetScreen();
    void SetScreen();
    void update();
    void render();

private:
    int xpos;
    int ypos;
    SDL_Texture *objectTexture;
    SDL_Rect sourceRect, destinationRect;
    SDL_Renderer *renderer;
};