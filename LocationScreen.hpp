#include "Screen.hpp"
//#include "Game.hpp"

class LocationScreen
{
public:
    LocationScreen(const char *textureSheet, SDL_Renderer *ren, int x, int y);
    ~LocationScreen();
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