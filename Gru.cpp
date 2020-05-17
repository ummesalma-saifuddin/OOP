#include "Gru.hpp"
#include "LTexture.hpp"

Gru::Gru(const char *textureSheet, SDL_Renderer *ren, int mx, int my)
{
    x = mx;
    y = my;
    renderer = ren;
    sourceRect.x = 0;
    sourceRect.y = 0;
    sourceRect.w = 0;
    sourceRect.h = 0;

    objectTexture = LTexture::LoadTexture(textureSheet, ren);
    // destinationRect.h = h;
    // destinationRect.w = w;
    destinationRect.x = 296;
    destinationRect.y = 296;
}
Gru::~Gru()
{
}
void Gru::render()
{
    //SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, objectTexture, NULL, &destinationRect);
    //SDL_RenderPresent(renderer);
}

void Gru::update()
{
    // x = 0;
    // y = 0;
    destinationRect.h = 297;
    destinationRect.w = 365;

    destinationRect.x = 296 + x;
    destinationRect.y = 296 + y;
}

void Gru::SetPosition(Position *p)
{
    x = p->getX();
    y = p->getY();
}

Position *Gru::GetPosition()
{
    Position *p = new Position(x, y);
    return p;
}

bool Gru::CheckCollision(Enemy *minion)
{
    //The sides of the rectangles
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    //Calculate the sides of rect A
    leftA = destinationRect.x;                       // - 50;
    rightA = destinationRect.x + destinationRect.w;  // - 50; //or 400; //this->GettPosition().w;
    topA = destinationRect.y;                        // - 50;
    bottomA = destinationRect.y + destinationRect.h; //- 10;

    //Calculate the sides of rect B
    leftB = minion->getx();
    rightB = minion->getx() + minion->getW();  // - 50; // GetPosition().w;
    topB = minion->gety();                     // - 50;
    bottomB = minion->gety() + minion->getH(); //GetPosition().h;

    //If any of the sides from A are outside of B
    if (bottomA <= topB)
        return false;
    if (topA >= bottomB)
        return false;
    if (rightA <= leftB)
        return false;
    if (leftA >= rightB)
        return false;
    return true;
}