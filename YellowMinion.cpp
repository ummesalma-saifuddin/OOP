#include "YellowMinion.hpp"
#include "LTexture.hpp"
#include "Game.hpp"
#include <cmath>
#include "randomnum.hpp"

//YellowMinion *y;

YellowMinion::YellowMinion(SDL_Renderer *ren, int yx, int yy, random a)
{
    x = yx;
    y = yy;
    ran = a.a;
    renderer = ren;
    endreached = false;
    objectTexture = LTexture::LoadTexture("assets/MinionSpriteSheet.png", ren);
    destinationRect.h = 85;
    destinationRect.w = 78;
    destinationRect.x = yx;
    destinationRect.y = yy;
    frame = 0;
    sRect = new SDL_Rect[16];
}
YellowMinion::~YellowMinion()
{
}

void YellowMinion::update()
{
    frame += 1;
    //1 frame
    sRect[0].x = 17;
    sRect[0].y = 14;
    sRect[0].w = 21;
    sRect[0].h = 21;

    //2 frame
    sRect[1].x = 44;
    sRect[1].y = 14;
    sRect[1].w = 21;
    sRect[1].h = 21;

    //3 frame
    sRect[2].x = 73;
    sRect[2].y = 14;
    sRect[2].w = 21;
    sRect[2].h = 21;

    //4 frame
    sRect[3].x = 96;
    sRect[3].y = 14;
    sRect[3].w = 21;
    sRect[3].h = 21;

    //5 frame
    sRect[4].x = 121;
    sRect[4].y = 14;
    sRect[4].w = 21;
    sRect[4].h = 21;

    //6 frame
    sRect[5].x = 146;
    sRect[5].y = 14;
    sRect[5].w = 21;
    sRect[5].h = 21;

    //7 frame
    sRect[6].x = 168;
    sRect[6].y = 14;
    sRect[6].w = 21;
    sRect[6].h = 21;

    //8 frame
    sRect[7].x = 192;
    sRect[7].y = 14;
    sRect[7].w = 21;
    sRect[7].h = 21;

    //9 frame
    sRect[8].x = 219;
    sRect[8].y = 14;
    sRect[8].w = 21;
    sRect[8].h = 21;

    //10 frame
    sRect[9].x = 247;
    sRect[9].y = 14;
    sRect[9].w = 21;
    sRect[9].h = 21;

    //11 frame
    sRect[10].x = 276;
    sRect[10].y = 14;
    sRect[10].w = 21;
    sRect[10].h = 21;

    //12 frame
    sRect[11].x = 300;
    sRect[11].y = 14;
    sRect[11].w = 21;
    sRect[11].h = 21;

    //13 frame
    sRect[12].x = 325;
    sRect[12].y = 14;
    sRect[12].w = 21;
    sRect[12].h = 21;

    //14 frame
    sRect[13].x = 350;
    sRect[13].y = 14;
    sRect[13].w = 21;
    sRect[13].h = 21;

    //15 frame
    sRect[14].x = 373;
    sRect[14].y = 14;
    sRect[14].w = 21;
    sRect[14].h = 21;

    //16 frame
    sRect[15].x = 396;
    sRect[15].y = 14;
    sRect[15].w = 21;
    sRect[15].h = 21;

    destinationRect.h = 16.161 * 4;
    destinationRect.w = 15.536 * 4;

    if (destinationRect.y >= ran && endreached == false)
    {
        destinationRect.x = destinationRect.x + 2;
        if (destinationRect.x == 790)
        {
            endreached = true;
        }
    }
    else if (destinationRect.y <= ran)
    {
        destinationRect.y += 2;
    }
    else if (endreached)
    {
        destinationRect.x = destinationRect.x - 2;
        if (destinationRect.x <= 0)
        {
            endreached = false;
        }
    }
}

void YellowMinion::render()
{
    //SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, objectTexture, &sRect[frame % 16], &destinationRect);
}
void YellowMinion::SetPosition(Position *p)
{
    x = p->getX();
    y = p->getY();
}

Position *YellowMinion::GetPosition()
{
    Position *p = new Position(x, y);
    return p;
}

int YellowMinion::getH()
{
    return destinationRect.h;
}
int YellowMinion::getW()
{
    return destinationRect.w;
}
int YellowMinion::getx()
{
    return destinationRect.x;
}
int YellowMinion::gety()
{
    return destinationRect.y;
}

void YellowMinion::resetPositionLeft()
{
    destinationRect.x = 0;
    destinationRect.y = 0;
}

void YellowMinion::resetPositionRight()
{
    destinationRect.x = 790;
    destinationRect.y = 0;
}
