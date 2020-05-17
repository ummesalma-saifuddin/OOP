
#pragma once
class Position
{
private:
    int x, y;

public:
    ~Position();
    Position(int x, int y);
    int getX();
    int getY();
    void setX(int mx);
    void setY(int my);
    void SetRandomPosition();
};