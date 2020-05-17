#pragma once
#include <SDL.h>
#include "Position.hpp"
#include "LinkedList.hpp"
class Enemy
{
private:
  //SDL_Renderer *renderer;

public:
  Enemy();
  virtual ~Enemy() = 0;
  virtual void render() = 0;
  virtual void update() = 0;
  virtual Position *GetPosition() = 0;
  virtual void SetPosition(Position *p) = 0;
  virtual int getW() = 0;
  virtual int getH() = 0;
  virtual int getx() = 0;
  virtual int gety() = 0;
  virtual void resetPositionLeft() = 0;
  virtual void resetPositionRight() = 0;
};