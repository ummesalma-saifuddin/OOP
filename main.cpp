#include "Game.hpp"

Game *game = nullptr;

int main(int argv, char **args)
{
    const int FPS = 20;
    const int framedelay = 1000 / FPS;

    Uint32 framestart;
    int frametime;

    game = new Game();
    game->init("SaveGru", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 845, 595, false);

    while (game->running())
    {
        framestart = SDL_GetTicks();

        game->EventHandler();
        game->update();
        game->render();

        frametime = SDL_GetTicks() - framestart;

        if (framedelay > frametime)
        {
            SDL_Delay(framedelay - frametime);
        }
    }

    game->clean();
    return 0;
}