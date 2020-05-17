#include "Position.hpp"

Position::Position(int _x, int _y)
{
    x = _x;
    y = _y;
}
Position::~Position()
{
}
int Position::getX()
{
    return x;
}
int Position::getY()
{
    return y;
}
void Position::setX(int mx)
{
    x = mx;
}
void Position::setY(int my)
{
    y = my;
}