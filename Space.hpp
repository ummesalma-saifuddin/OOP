#include "Gru.hpp"
#include "Enemy.hpp"
#include <SDL.h>

class Space
{
private:
    SDL_Texture *objectTexture;
    SDL_Rect sourceRect, destinationRect;
    SDL_Renderer *renderer;
    int x;
    int y;
public:
    Space(const char *textureSheet, SDL_Renderer *ren, int x, int y);
    ~Space();
    void update();
    void render();
    Position *GetPosition();
    void SetPosition(Position *p);
    bool CheckCollision(Enemy *minion);

};
