
#include "Screen.hpp"
#include "LTexture.hpp"
#include "MainScreen.hpp"
#include "Gru.hpp"
#include "YellowMinion.hpp"
#include "Space.hpp"

MainScreen::MainScreen(const char *textureSheet, SDL_Renderer *ren, int x, int y)
{
    renderer = ren;
    objectTexture = LTexture::LoadTexture(textureSheet, ren);
}
MainScreen::~MainScreen()
{
}

void MainScreen::GetScreen()
{
}
void MainScreen::SetScreen()
{
}
void MainScreen::update()
{
}
void MainScreen::render()
{
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, objectTexture, NULL, NULL);
    //SDL_RenderPresent(renderer);
}
