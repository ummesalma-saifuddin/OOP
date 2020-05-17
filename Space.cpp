#include "Space.hpp"
#include "LTexture.hpp"
#include "Position.hpp"
#include "Enemy.hpp"

Space::Space(const char *textureSheet, SDL_Renderer *ren, int mx, int my)
{
    x = mx;
    y = my;
    renderer = ren;
    objectTexture = LTexture::LoadTexture(textureSheet, ren);
    destinationRect.h = 400;
    destinationRect.w = 400;
    destinationRect.x = 230;
    destinationRect.y = 170;
}
Space::~Space()
{
}
void Space::update()
{
    destinationRect.h = 400;
    destinationRect.w = 400;
    destinationRect.x = 230 + x;
    destinationRect.y = 170 + y;
}
void Space::render()
{
    SDL_RenderCopy(renderer, objectTexture, NULL, &destinationRect);
}
void Space::SetPosition(Position *p)
{
    x = p->getX();
    y = p->getY();
}

Position *Space::GetPosition()
{
    Position *p = new Position(x, y);
    return p;
}


bool Space::CheckCollision(Enemy *minion)
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
