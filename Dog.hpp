#include "Health.hpp"
#include "Enemy.hpp"

class Dog : public Health, Enemy
{
public:
    Enemy* clone(); //return new dog
    Dog();
    ~Dog();
    void drawEnemy(SDL_Renderer *);
    void randMove();
};