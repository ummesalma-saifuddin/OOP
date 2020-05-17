#pragma once

#include "Button.hpp"
class Screen
{
    // Button mButton;
    int width;
    int height;

public:
    Screen();
    virtual ~Screen();
    virtual Screen *GetScreen();
    virtual void SetScreen();
};