#include "SDL.h"
#include "LTexture.hpp"
#include <iostream>
using namespace std;

LTexture::LTexture()
{
}
LTexture::~LTexture()
{
}
SDL_Texture *LTexture::LoadTexture(const char *texture, SDL_Renderer *ren)
{
    // SDL_Surface *tempSurface = IMG_Load(texture);
    // SDL_Texture *tex = SDL_CreateTextureFromSurface(ren, tempSurface);
    // SDL_FreeSurface(tempSurface);
    // return tex;
    SDL_Surface *temp = IMG_Load(texture);
    SDL_Texture *tex = SDL_CreateTextureFromSurface(ren, temp);
    SDL_FreeSurface(temp);
    return tex;
}
// bool LTexture::loadFromFile(string)
// {
// }
// bool LTexture::loadFromRenderedText(string, SDL_Color)
// {
// }
// bool LTexture::createBlank(int, int)
// {
// }
// void LTexture::free()
// {
// }
// void LTexture::setColor(int, int, int)
// {
// }
// void LTexture::setBlendMode(SDL_BlendMode)
// {
// }
// void LTexture::setAlpha(int)
// {
// }
// int LTexture::getHeight()
// {
// }
// int LTexture::getWidth()
// {
// }
