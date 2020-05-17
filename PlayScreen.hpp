#include "Screen.hpp"
#include "LTexture.hpp"
class PlayScreen : public Screen
{
public:
    PlayScreen(LTexture *);
    ~PlayScreen();
    Screen *GetScreen();
    void SetScreen();

private:
    SDL_Texture *objectTexture;
    SDL_Rect sourceRect, destinationRect;
    SDL_Renderer *renderer;
};