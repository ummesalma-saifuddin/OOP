#include "Health.hpp"
#include "Enemy.hpp"

class Daughter : public Health, Enemy
{
public:
    Enemy* clone(); //return new daughter
    Daughter();
    ~Daughter();
    void drawEnemy(SDL_Renderer *);
    void randMove();
};