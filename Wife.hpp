#include "Health.hpp"
#include "Enemy.hpp"
#include <SDL.h>

class Wife : public Health, Enemy
{
public:
    Enemy* clone(); //return new yellowminion
    Wife();
    ~Wife();
    void drawEnemy();
    void randMove();
};