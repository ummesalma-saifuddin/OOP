#include <iostream>
#include <fstream>
#include <string.h>
#include "Game.hpp"
#include "LTexture.hpp"
#include "EndScreen.hpp"
#include "SplashScreen.hpp"
#include "MenuScreen.hpp"
#include "MainScreen.hpp"
#include "Gru.hpp"
#include "Button.hpp"
#include "YellowMinion.hpp"
#include "Position.hpp"
#include "Space.hpp"
#include "LinkedList.hpp"
#include "Enemy.hpp"
#include "randomnum.hpp"
#include "LocationScreen.hpp"
#include "Counter.hpp"
#include <time.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

SplashScreen *s;
EndScreen *e;

LocationScreen *l;
LocationScreen *housel;
LocationScreen *bedrooml;
LocationScreen *outdoorl;
LocationScreen *labl;

MenuScreen *m;
MainScreen *p;

Button *startbutton;
Button *Resume;
Button *ChooseLoc;
Button *Pause;
Button *Resume2;
Button *MinionCounter;
Button *GruHealth;
Button *Quit;
Button *Lab;
Button *Outdoor;
Button *House;
Button *Bedroom;

SDL_Rect sourceRect, destinationRect;

Gru *g;
Gru *gs;
Gru *gl;

Space *sp;

Enemy *ym;
Enemy *ym1;
Enemy *ym2;
Enemy *ym3;
Enemy *ym4;
Enemy *ym5;
Enemy *ym6;
Enemy *ym7;
SDL_Event event;

Health *health;

Counter *mcount;

int death=3;
bool d;
//YellowMinion *enemy;
LinkedList ListOfEnemy;

int x, y;
bool quit;
Position *ms = new Position(0, 0);

Game::Game()
{
    labR = false;
    bedroomR = false;
    houseR = false;
    outdoorR = false;
    housescreen = false;
    bedroomscreen = false;
    labscreen = false;
    outdoorscreen = false;
    changeScreen = false;
    playScreen = false;
    LocScreen = false;
    MScreen = false;
    counter = 0;
    delayTime = 10;
    ResumeButton = false;
    number_of_lines = 0;
}
Game::~Game()
{
}
void Game::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen)
{
    int flags = 0;
    if (fullscreen)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }
    if (TTF_Init() < 0)
    {
        cout << "ERROR" << TTF_GetError() << endl;
    }
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        std::cout << "subsytem initialized!" << endl;
        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if (window)
        {
            cout << "window is created" << endl;
        }
        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer)
        {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            cout << "renderer is created" << endl;
        }
        isRunning = true;
    }
    else
    {
        {
            isRunning = false;
        }
    }
    s = new SplashScreen("assets/Splash.png", renderer, 0, 0);
    m = new MenuScreen("assets/MenuScreen.png", renderer, 0, 0);
    sp = new Space("assets/space.png", renderer, 0, 0);
    p = new MainScreen("assets/Outdoor.png", renderer, 0, 0);
    l = new LocationScreen("assets/Location.jpg", renderer, 0, 0);
    Resume = new Button("assets/Resume.png", renderer, 469.379, 240.405);
    ChooseLoc = new Button("assets/ChooseLocation.png", renderer, 468.879, 322.405);
    g = new Gru("assets/GruKickingRight.png", renderer, 0, 0);
    gs = new Gru("assets/GruStanding2.png", renderer, 0, 0);
    gl = new Gru("assets/GruKicking2.png", renderer, 0, 0);
    Resume2 = new Button("assets/Resume2.png", renderer, 622.89, 24.65);
    Pause = new Button("assets/pause.png", renderer, 696.644, 24.65);
    Quit = new Button("assets/Quit.png", renderer, 546.693, 24.65);
    GruHealth = new Button("assets/GruHealth.png", renderer, 72.429, 24.65);
    MinionCounter = new Button("assets/MinionCounter.png", renderer, 300.082, 24.65);
    Bedroom = new Button("assets/Bedroom.png", renderer, 69, 319);
    House = new Button("assets/House.png", renderer, 300, 59);
    Lab = new Button("assets/Lab.png", renderer, 69, 59);
    Outdoor = new Button("assets/Outdoor.PNG", renderer, 300, 319);
    bedrooml = new LocationScreen("assets/Bedroom.png", renderer, 0, 0);
    labl = new LocationScreen("assets/Lab.png", renderer, 0, 0);
    housel = new LocationScreen("assets/House.png", renderer, 0, 0);
    outdoorl = new LocationScreen("assets/Outdoor.png", renderer, 0, 0);
     health = new Health(TTF_OpenFont("assets/OpenSans-Bold.ttf", 12), {144, 77, 255, 255}, renderer, 230, 20);
    mcount = new Counter(TTF_OpenFont("assets/OpenSans-Bold.ttf", 12), {144, 77, 255, 255}, renderer, 450, 20);
    e = new EndScreen("assets/EndScreen.png", renderer, 0,0);

    srand(time(NULL));
    random a;
    random b;
    random c;
    random d;

    ym = new YellowMinion(renderer, 0, 0, a);
    ym1 = new YellowMinion(renderer, 780, 0, b);
    ym2 = new YellowMinion(renderer, 700, 0, c);
    ym3 = new YellowMinion(renderer, 150, 0, d);
    ym4 = new YellowMinion(renderer, 0, 0, a);
    ym5 = new YellowMinion(renderer, 780, 0, b);
    ym6 = new YellowMinion(renderer, 700, 0, c);
    ym7 = new YellowMinion(renderer, 150, 0, d);

    ListOfEnemy + *ym;
    ListOfEnemy + *ym1;
    ListOfEnemy + *ym2;
    ListOfEnemy + *ym3;
    ListOfEnemy + *ym4;
    ListOfEnemy + *ym5;
    ListOfEnemy + *ym6;
    ListOfEnemy + *ym7;
}
void Game::EventHandler()
{

    SDL_PollEvent(&event);
    
    if (death == 0)
    {
        cout << "gameover" << endl; //gameover works
        d = true;
        e->render();
        //this->clean();
    }
    switch (event.type)
    {
    case SDL_QUIT:
        isRunning = false;
        SDL_Quit();
        break;
    default:
        if ((sp->CheckCollision(ym) & sp->CheckCollision(ym1)) || (sp->CheckCollision(ym2) & sp->CheckCollision(ym3)))
        {
            death = 0;
        }
        
        break;
    case SDL_KEYDOWN:
        if (event.key.keysym.sym == SDLK_LEFT)
        {
            ms->setX(g->GetPosition()->getX() - 10);
            ms->setY(g->GetPosition()->getY());

            g->SetPosition(ms);
            gs->SetPosition(ms);
            sp->SetPosition(ms);
            if (g->CheckCollision(ym) == true)
            {
                ym->resetPositionLeft();
                mcount->decreaseCounter();
                mcount->render();
                health->update_health();
                health->render();
                break;
            }
            if (g->CheckCollision(ym1) == true)
            {
                ym1->resetPositionLeft();
                mcount->decreaseCounter();
                mcount->render();
                health->update_health();
                health->render();
                break;
            }
            if (g->CheckCollision(ym2) == true)
            {
                ym2->resetPositionLeft();
                mcount->decreaseCounter();
                mcount->render();
                health->update_health();
                health->render();
                break;
            }
            if (g->CheckCollision(ym3) == true)
            {
                ym3->resetPositionRight();
                mcount->decreaseCounter();
                mcount->render();
                health->update_health();
                health->render();
                break;
            }
            if (g->CheckCollision(ym4) == true)
            {
                ym4->resetPositionLeft();
                mcount->decreaseCounter();
                mcount->render();
                health->update_health();
                health->render();
                break;
            }
            if (g->CheckCollision(ym5) == true)
            {
                ym5->resetPositionLeft();
                mcount->decreaseCounter();
                mcount->render();
                health->update_health();
                health->render();
                break;
            }
            if (g->CheckCollision(ym6) == true)
            {
                ym6->resetPositionLeft();
                mcount->decreaseCounter();
                mcount->render();
                health->update_health();
                health->render();
                break;
            }
            if (g->CheckCollision(ym7) == true)
            {
                ym7->resetPositionRight();
                mcount->decreaseCounter();
                mcount->render();
                health->update_health();
                health->render();
                break;
            }
        }
        else if (event.key.keysym.sym == SDLK_RIGHT)
        {

            ms->setX(gl->GetPosition()->getX() + 10);
            ms->setY(g->GetPosition()->getY());
            gl->SetPosition(ms);
            gs->SetPosition(ms);
            sp->SetPosition(ms);
            if (gl->CheckCollision(ym) == true)
            {
                ym->resetPositionLeft();
                mcount->decreaseCounter();
                mcount->render();
                health->update_health();
                health->render();
                break;
            }
            if (gl->CheckCollision(ym1) == true)
            {
                ym1->resetPositionLeft();
                mcount->decreaseCounter();
                mcount->render();
                health->update_health();
                health->render();
                break;
            }
            if (gl->CheckCollision(ym2) == true)
            {
                ym2->resetPositionLeft();
                mcount->decreaseCounter();
                mcount->render();
                health->update_health();
                health->render();
                break;
            }
            if (gl->CheckCollision(ym3) == true)
            {
                ym3->resetPositionRight();
                mcount->decreaseCounter();
                mcount->render();
                health->update_health();
                health->render();
                break;
            }
            if (gl->CheckCollision(ym4) == true)
            {
                ym4->resetPositionLeft();
                mcount->decreaseCounter();
                mcount->render();
                health->update_health();
                health->render();
                break;
            }
            if (gl->CheckCollision(ym5) == true)
            {
                ym5->resetPositionLeft();
                mcount->decreaseCounter();
                mcount->render();
                health->update_health();
                health->render();
                break;
            }
            if (gl->CheckCollision(ym6) == true)
            {
                ym6->resetPositionLeft();
                mcount->decreaseCounter();
                mcount->render();
                health->update_health();
                health->render();
                break;
            }
            if (gl->CheckCollision(ym7) == true)
            {
                ym7->resetPositionRight();
                mcount->decreaseCounter();
                mcount->render();
                health->update_health();
                health->render();
                break;
            }
        }
        break;
    case SDL_MOUSEBUTTONUP:
        if (event.button.button == SDL_BUTTON_LEFT)
        {
            MScreen = true;
            if (ChooseLoc->checkSelected())
            {
                LocScreen = true;
            }
            if (House->checkSelected())
            {
                housescreen = true;
            }
            if (Lab->checkSelected())
            {
                labscreen = true;
            }
            if (Outdoor->checkSelected())
            {
                outdoorscreen = true;
            }
            if (Bedroom->checkSelected())
            {
                bedroomscreen = true;
            }
            if (Pause->checkSelected())
            {
                isPaused = true;
                SDL_EventState(SDL_KEYDOWN, SDL_IGNORE);
                SDL_EventState(SDL_KEYUP, SDL_IGNORE);
            }

            if (Resume2->checkSelected())
            {
                isPaused = false;
                SDL_EventState(SDL_KEYDOWN, SDL_ENABLE);
                SDL_EventState(SDL_KEYUP, SDL_ENABLE);
            }
            if (Quit->checkSelected())
            {
                isRunning = false;
                fstream file; //object of fstream class

                //opening file "sample.txt" in out(write) mode
                file.open("GameState.txt", ios::out);

                if (!file)
                {
                    cout << "Error in creating file!!!" << endl;
                }

                cout << "File created successfully." << endl;

                if (!file)
                {
                    cout << "Error in opening file!!!" << endl;
                }

                file << ms->getX() << endl
                     << ms->getY() << endl
                 << health->Amount << endl
                 << mcount->count << endl;
                if (housescreen == true)
                {
                    file << "Location: House" << endl;
                }
                else if (labscreen == true)
                {
                    file << "Location: Lab" << endl;
                }
                else if (outdoorscreen == true)
                {
                    file << "Location: Outdoor" << endl;
                }
                else if (bedroomscreen == true)
                {
                    file << "Location: Bedroom" << endl;
                }

                file.close();
                SDL_Quit();
            }
            if (Resume->checkSelected())
            {
                
                ResumeButton = true;
                fstream file;
                string line;
                file.open("GameState.txt", ios::in);
                getline(file, line);
                int mm = stoi(line);
                cout << mm << endl;
                ms->setX(mm);
                getline(file, line);
                int mn = stoi(line);
                ms->setY(mn);
               getline(file, line);
                int he = stoi(line);
                // health->Amount = he;
                getline(file, line);
                int mini = stoi(line);
                // mcount->count = mini;
getline(file, line);
                if (line == "Location: House")
                {
                    houseR = true;
                    labR = false;
                    outdoorR = false;
                    bedroomR = false;
                    g->SetPosition(ms);
                    ++number_of_lines;
                }
                else if (line == "Location: Bedroom")
                {
                    bedroomR = true;
                    houseR = false;
                    labR = false;
                    outdoorR = false;
                    ++number_of_lines;
                    g->SetPosition(ms);
                }
                else if (line == "Location: Lab")
                {
                    labR = true;
                    bedroomR = false;
                    outdoorR = false;
                    houseR = false;
                    ++number_of_lines;
                    g->SetPosition(ms);
                }
                else if (line == "Location: Outdoor")
                {
                    outdoorR = true;
                    labR = false;
                    bedroomR = false;
                    houseR = false;
                    g->SetPosition(ms);
                    ++number_of_lines;
                }
            }
            break;
        }
    }
}

void Game::update()
{

    counter += 0.1;
    count++;

    if (counter >= delayTime)
    {
        changeScreen = true;
        counter = 0;
    }

    g->update();
    gl->update();
    gs->update();
    sp->update();
     ym1->update(); 
     ym2->update(); 
     ym3->update(); 
     ym4->update();
      ym5->update(); 
      ym6->update(); 
      ym7->update();
    ym->update();
    Bedroom->updateLoc();
    Lab->updateLoc();
    House->updateLoc();
    Outdoor->updateLoc();
    Resume2->updateResize();
    Quit->updateResize();
    Pause->updateResize();
    MinionCounter->update();
    MinionCounter->updatecount();
    GruHealth->update();
    GruHealth->updatecount();
    mcount->render();
    //health->update_health();
    //health->render();

    cout << count << endl;
}
void Game::render()
{
    SDL_RenderClear(renderer);
    if (changeScreen == false)
    {
        s->render();
    }
    else
   { m->render();
    Resume->render();
    ChooseLoc->render();
    if (LocScreen == true)
    {
        l->render();
        Bedroom->render();
        Lab->render();
        House->render();
        Outdoor->render();
        if (housescreen == true)
        {
            housel->render();
            GruHealth->render();
            Pause->render();
            Resume2->render();
            Quit->render();
            MinionCounter->render();
            mcount->render();
            health->render();
            ListOfEnemy.displaylist(renderer);
            if (event.type == SDL_KEYDOWN)
            {
                if (event.key.keysym.sym == SDLK_LEFT)
                {
                    g->render();
                    sp->render();
                }
                else if (event.key.keysym.sym == SDLK_RIGHT)
                {
                    gl->render();
                    sp->render();
                }
            }
            else
            {
                gs->render();
                sp->render();
            }
            if(mcount->count == 0)
            {
                e->render();
                MinionCounter->render();
                GruHealth->render();
                health->render();
                mcount->render();
                
            }
        }
        else if (labscreen == true)
        {
            labl->render();
            GruHealth->render();
            Pause->render();
            Resume2->render();
            Quit->render();
            health->render();
            MinionCounter->render();
            mcount->render();
            ListOfEnemy.displaylist(renderer);
            if (event.type == SDL_KEYDOWN)
            {
                if (event.key.keysym.sym == SDLK_LEFT)
                {
                    g->render();
                    sp->render();
                }
                else if (event.key.keysym.sym == SDLK_RIGHT)
                {
                    gl->render();
                    sp->render();
                }
            }
            else
            {
                gs->render();
                sp->render();
            }
            if(mcount->count == 0)
            {
                e->render();
                MinionCounter->render();
                GruHealth->render();
                health->render();
                mcount->render();
                
            }
        }
        else if (bedroomscreen == true)
        {
            bedrooml->render();
            GruHealth->render();
            Pause->render();
            Resume2->render();
            Quit->render();
            health->render();
            MinionCounter->render();
            mcount->render();
            ListOfEnemy.displaylist(renderer);
            if (event.type == SDL_KEYDOWN)
            {
                if (event.key.keysym.sym == SDLK_LEFT)
                {
                    g->render();
                    sp->render();
                }
                else if (event.key.keysym.sym == SDLK_RIGHT)
                {
                    gl->render();
                    sp->render();
                }
            }
            else
            {
                gs->render();
                sp->render();
            }
            if(mcount->count == 0)
            {
                e->render();
                MinionCounter->render();
                GruHealth->render();
                health->render();
                mcount->render();
                
            }
        }
        else if (outdoorscreen == true)
        {
            outdoorl->render();
            GruHealth->render();
            Pause->render();
            Resume2->render();
            Quit->render();
            health->render();
            MinionCounter->render();
            mcount->render();
            ListOfEnemy.displaylist(renderer);
            if (event.type == SDL_KEYDOWN)
            {
                if (event.key.keysym.sym == SDLK_LEFT)
                {
                    g->render();
                    sp->render();
                }
                else if (event.key.keysym.sym == SDLK_RIGHT)
                {
                    gl->render();
                    sp->render();
                }
            }
            else
            {
                gs->render();
                sp->render();
            }
            if(mcount->count == 0)
            {
                e->render();
                MinionCounter->render();
                GruHealth->render();
                health->render();
                mcount->render();
                
            }
        }
    }
    if (ResumeButton == true)
    {
        if (houseR == true)
        {
            housel->render();
            GruHealth->render();
            Pause->render();
            Resume2->render();
            Quit->render();
            MinionCounter->render();
            mcount->render();
            health->render();
            ListOfEnemy.displaylist(renderer);
            if (event.type == SDL_KEYDOWN)
            {
                if (event.key.keysym.sym == SDLK_LEFT)
                {
                    g->SetPosition(ms);
                    sp->SetPosition(ms);
                    g->render();
                    sp->render();
                }
                else if (event.key.keysym.sym == SDLK_RIGHT)
                {
                    gl->SetPosition(ms);
                    sp->SetPosition(ms);
                    gl->render();
                    sp->render();
                }
            }
            else
            {
                gs->SetPosition(ms);
                sp->SetPosition(ms);
                gs->render();
                sp->render();
            }

        }
        if (labR == true)
        {
            labl->render();
            GruHealth->render();
            Pause->render();
            Resume2->render();
            Quit->render();
            MinionCounter->render();
            mcount->render();
            health->render();
            ListOfEnemy.displaylist(renderer);
            if (event.type == SDL_KEYDOWN)
            {
                if (event.key.keysym.sym == SDLK_LEFT)
                {
                    g->SetPosition(ms);
                    sp->SetPosition(ms);
                    g->render();
                    sp->render();
                }
                else if (event.key.keysym.sym == SDLK_RIGHT)
                {
                    gl->SetPosition(ms);
                    sp->SetPosition(ms);
                    gl->render();
                    sp->render();
                }
            }
            else
            {
                gs->SetPosition(ms);
                sp->SetPosition(ms);
                gs->render();
                sp->render();
            }
        }
        if (bedroomR == true)
        {
            bedrooml->render();
            GruHealth->render();
            Pause->render();
            Resume2->render();
            Quit->render();
            MinionCounter->render();
            mcount->render();
            health->render();
            ListOfEnemy.displaylist(renderer);
            if (event.type == SDL_KEYDOWN)
            {
                if (event.key.keysym.sym == SDLK_LEFT)
                {
                    g->SetPosition(ms);
                    sp->SetPosition(ms);
                    g->render();
                    sp->render();
                }
                else if (event.key.keysym.sym == SDLK_RIGHT)
                {
                    gl->SetPosition(ms);
                    sp->SetPosition(ms);
                    gl->render();
                    sp->render();
                }
            }
            else
            {
                gs->SetPosition(ms);
                sp->SetPosition(ms);
                gs->render();
                sp->render();
            }
        }
        if (outdoorR == true)
        {
            outdoorl->render();
            GruHealth->render();
            Pause->render();
            Resume2->render();
            Quit->render();
            MinionCounter->render();
            mcount->render();
            health->render();
            ListOfEnemy.displaylist(renderer);
            if (event.type == SDL_KEYDOWN)
            {
                if (event.key.keysym.sym == SDLK_LEFT)
                {
                    g->SetPosition(ms);
                    sp->SetPosition(ms);
                    g->render();
                    sp->render();
                }
                else if (event.key.keysym.sym == SDLK_RIGHT)
                {
                    gl->SetPosition(ms);
                    sp->SetPosition(ms);
                    gl->render();
                    sp->render();
                }
            }
            else
            {
                gs->SetPosition(ms);
                sp->SetPosition(ms);
                gs->render();
                sp->render();
            }
        }
    }}

    SDL_RenderPresent(renderer);
}

void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    //TTT_Quit();
    SDL_Quit();
    cout << "game cleaned" << endl;
}

bool Game::running()
{
    return true;
}

void Game::resume(string filename)
{
}
