#include "Counter.hpp"
#include "Game.hpp"

Counter::Counter(TTF_Font *f, SDL_Color c, SDL_Renderer *ren, int xp, int yp)
{
    count = 25;
    font = f;
    renderer = ren;
    textrect.x = xp;
    textrect.y = yp;
    textrect.w = 60;
    textrect.h = 50;
    string str = to_string(count);
    textsurface = TTF_RenderText_Solid(font, str.c_str(), color);

    text = SDL_CreateTextureFromSurface(renderer, textsurface);
}

Counter::~Counter()
{
}
void Counter::increaseCounter()
{
    count = count + 1;
    string str = to_string(count);
    textsurface = TTF_RenderText_Solid(font, str.c_str(), color);

    text = SDL_CreateTextureFromSurface(renderer, textsurface);
}

void Counter::decreaseCounter()
{
    if (count > 0)
    {
        count = count - 0.5;
        string str = to_string(count);
        textsurface = TTF_RenderText_Solid(font, str.c_str(), color);

        text = SDL_CreateTextureFromSurface(renderer, textsurface);
    }
}
int Counter::getCounter()
{
    return count;
}
void Counter::render()
{
    SDL_RenderCopy(renderer, text, NULL, &textrect);
}
