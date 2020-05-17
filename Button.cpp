#include "Position.hpp"
#include "Button.hpp"
#include "LTexture.hpp"

using namespace std;

Button::Button(const char *filename, SDL_Renderer *ren, int x, int y)
{

    xpos = x;
    ypos = y;
    renderer = ren;
    objectTexture = LTexture::LoadTexture(filename, ren);
    isSelected = false;

    destinationRect.x = x;
    destinationRect.y = y;
    destinationRect.w = 250; //233.976;
    destinationRect.h = 73.19;
}

Button ::~Button()
{
    //SDL_DestroyTexture(objectTexture);
}

void Button::render()
{
    //SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, objectTexture, NULL, &destinationRect);
    //SDL_RenderPresent(renderer);
}

void Button::SetPosition(Position *p)
{
    xpos = p->getX();
    ypos = p->getY();
}

Position *Button::GetPosition()
{
    Position *p = new Position(xpos, ypos);
    return p;
}

bool Button::checkSelected()
{
    SDL_GetMouseState(&x, &y);
    if (x <= this->GetPosition()->getX())
    {
        isSelected = false;
        return false;
    }
    else if (x >= this->GetPosition()->getX() + this->getW())
    {
        isSelected = false;
        return false;
    }
    else if (y <= this->GetPosition()->getY())
    {
        isSelected = false;
        return false;
    }
    else if (y >= this->GetPosition()->getY() + this->getH())
    {
        isSelected = false;
        return false;
    }
    else
    {
        isSelected = true;
        return true;
    }
}
void Button::update()
{
    destinationRect.w = 150.327;
    destinationRect.h = 43.258;
}
void Button::updateResize()
{
    destinationRect.w = 69;
    destinationRect.h = 37;
}

void Button::updateLoc()
{
    destinationRect.w = 200;
    destinationRect.h = 150;
}

void Button::updatecount()
{
    // destinationRect.x = xpos;
    // destinationRect.y = ypos;
    destinationRect.w = 200;
    destinationRect.h = 43;
}

int Button::getW()
{
    return destinationRect.w;
}
int Button::getH()
{
    return destinationRect.h;
}