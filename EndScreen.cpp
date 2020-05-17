#include "EndScreen.hpp"
#include "Screen.hpp"
#include "LTexture.hpp"

EndScreen::EndScreen(const char *textureSheet, SDL_Renderer *ren, int x, int y)
{
    renderer = ren;
    objectTexture = LTexture::LoadTexture(textureSheet, ren);
}
EndScreen::~EndScreen()
{
}
void EndScreen::update()
{
}
void EndScreen::render()
{
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, objectTexture, NULL, NULL);
    //SDL_RenderPresent(renderer);
}
void EndScreen::GetScreen()
{
}
void EndScreen::SetScreen()
{
}