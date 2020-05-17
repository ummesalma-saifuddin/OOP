#include "Screen.hpp"
//#include "Game.hpp"

class EndScreen
{
public:
    EndScreen(const char *textureSheet, SDL_Renderer *ren, int x, int y);
    ~EndScreen();
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