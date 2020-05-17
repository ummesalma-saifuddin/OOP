#include "Screen.hpp"
#include "SplashScreen.hpp"
#include "LTexture.hpp"

SplashScreen::SplashScreen(const char *textureSheet, SDL_Renderer *ren, int x, int y)
{
    renderer = ren;
    objectTexture = LTexture::LoadTexture(textureSheet, ren);
}
SplashScreen::~SplashScreen()
{
}
void SplashScreen::update()
{
}
void SplashScreen::render()
{
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, objectTexture, NULL, NULL);
    //SDL_RenderPresent(renderer);
}
void SplashScreen::GetScreen()
{
}
void SplashScreen::SetScreen()
{
}