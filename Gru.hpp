#pragma once
#include "Health.hpp"
#include "Position.hpp"
#include "Counter.hpp"
#include "Enemy.hpp"
#include <SDL.h>

class Gru
{
    //Counter Grucount;
    static Gru *s_instance;
    int hits;
    SDL_Texture *objectTexture;
    SDL_Rect sourceRect, destinationRect;
    SDL_Renderer *renderer;
    int x;
    int y;

public:
    Gru(const char *textureSheet, SDL_Renderer *ren, int x, int y);
    ~Gru();
    Position *GetPosition();
    void SetPosition(Position *p);
    void render();
    void update();
    void shooter();
    void sdlkeydownevent();
    void walk();
    int GetHits();
    void SetHits();
    //Counter getCounter();
    static Gru *instance();
    bool CheckCollision(Enemy *minion);

    Gru *g;
};