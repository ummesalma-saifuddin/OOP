#pragma once
#include "Screen.hpp"
#include "LTexture.hpp"

class MenuScreen : public Screen
{
public:
    MenuScreen(const char *textureSheet, SDL_Renderer *ren, int x, int y);
    ~MenuScreen();
    // void GetScreen();
    // void SetScreen();
    void update();
    void render();

private:
    int xpos;
    int ypos;
    SDL_Texture *objectTexture;
    SDL_Rect sourceRect, destinationRect;
    SDL_Renderer *renderer;
};