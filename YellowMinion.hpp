#pragma once
//#include "Health.hpp"
#include "Enemy.hpp"
#include "Position.hpp"
#include "Gru.hpp"
#include "randomnum.hpp"
#include <SDL.h>

class YellowMinion : public Enemy
{
private:
    SDL_Texture *objectTexture;
    SDL_Rect sourceRect, destinationRect;
    SDL_Renderer *renderer;
    SDL_Rect *sRect;
    int x;
    int y;
    bool endreached;
    int frame;
    int ran;

public:
    // Enemy *clone(); //return new yellowminion
    YellowMinion(SDL_Renderer *ren, int x, int y, random a);
    ~YellowMinion();
    void update();
    void render();
    Position *GetPosition();
    void SetPosition(Position *p);
    int getW();
    int getH();
    int getx();
    int gety();
    void resetPositionLeft();
    void resetPositionRight();

    //   YellowMinion *cpyMinion(YellowMinion &other);
    //  SDL_Renderer *getRend();
};