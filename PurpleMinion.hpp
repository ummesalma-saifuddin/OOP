#include "Health.hpp"
#include "Enemy.hpp"
#include <SDL.h>
class PurpleMinion : public Enemy
{
public:
    Enemy* clone(); //return new purpleminion
    PurpleMinion();
    ~PurpleMinion();
    void drawEnemy(SDL_Renderer *);
    void randMove();
};