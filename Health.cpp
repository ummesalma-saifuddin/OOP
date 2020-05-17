#include "Health.hpp"
#include "Game.hpp"

// Health::Health()
// {
//     int x = 250;
//     int y = 20;
//     //Have to get current health of the player while game running which will be done if collision
//     Amount = 25; //just assuming the health
//     barlength = Amount;
//     outline_bar = {x, y, 100, 20};
//     Bar_health = {x, y, barlength, 20};
// }
Health::Health(TTF_Font *f, SDL_Color c, SDL_Renderer *ren, int xp, int yp)
{
    Amount = 1;
    font = f;
    renderer = ren;
    textrect.x = xp;
    textrect.y = yp;
    textrect.w = 40;
    textrect.h = 50;
    string str = to_string(Amount);
    textsurface = TTF_RenderText_Solid(font, str.c_str(), color);

    text = SDL_CreateTextureFromSurface(renderer, textsurface);
}
Health::~Health()
{
}
void Health::update_health()
{
    //if collision, will call the collision from player class
    if (Amount > 0)
    {
        Amount = Amount + 5;
        string str = to_string(Amount);
        textsurface = TTF_RenderText_Solid(font, str.c_str(), color);

        text = SDL_CreateTextureFromSurface(renderer, textsurface);
    }
    else
    {
        cout << "Game over" << endl;
    }
}
void Health::render()
{
    SDL_RenderCopy(renderer, text, NULL, &textrect);
}