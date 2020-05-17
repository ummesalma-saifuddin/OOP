#include "LocationScreen.hpp"
#include "Screen.hpp"
#include "LTexture.hpp"

LocationScreen::LocationScreen(const char *textureSheet, SDL_Renderer *ren, int x, int y)
{
    renderer = ren;
    objectTexture = LTexture::LoadTexture(textureSheet, ren);
}
LocationScreen::~LocationScreen()
{
}
void LocationScreen::update()
{
}
void LocationScreen::render()
{
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, objectTexture, NULL, NULL);
    //SDL_RenderPresent(renderer);
}
void LocationScreen::GetScreen()
{
}
void LocationScreen::SetScreen()
{
}