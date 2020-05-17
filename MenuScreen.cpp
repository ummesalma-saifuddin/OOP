#include "Screen.hpp"
#include "LTexture.hpp"
#include "MenuScreen.hpp"

MenuScreen::MenuScreen(const char *textureSheet, SDL_Renderer *ren, int x, int y)
{
    renderer = ren;
    objectTexture = LTexture::LoadTexture(textureSheet, ren);
}

MenuScreen::~MenuScreen()
{
}

void MenuScreen::render()
{
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, objectTexture, NULL, NULL);
    //SDL_RenderPresent(renderer);
}
