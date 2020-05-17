#pragma once
#include <time.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
struct random
{
public:
    int a;
    random()
    {
        a = rand() % 275 + 200;
        cout << a << "asdasjdas" << endl;
    }
};