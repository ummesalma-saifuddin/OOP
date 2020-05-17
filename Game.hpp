#pragma once
#include <iostream>
#include "Screen.hpp"
#include "SDL.h"
#include "SDL_image.h"
#include <stdio.h>
#include <SDL_ttf.h>
using namespace std;

class Game
{
public:
    Game();
    ~Game();
    void init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen);
    void EventHandler();
    void update();
    void render();
    void clean();
    bool running();

private:
    int count = 0;
    bool isRunning;
    SDL_Window *window;
    SDL_Renderer *renderer;
    bool ResumeButton;
    int number_of_lines;
    bool isPaused;
    bool housescreen;
    bool labscreen;
    bool outdoorscreen;
    bool bedroomscreen;
    bool changeScreen;
    bool MScreen;
    bool playScreen;
    bool LocScreen;
    float counter;
    float delayTime;
    TTF_Font *font;
    SDL_Rect textrect;
    SDL_Texture *text;
    SDL_Color color;
    bool houseR;
    bool outdoorR;
    bool bedroomR;
    bool labR;
    void resume(string filename);
};