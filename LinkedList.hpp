#pragma once
#ifdef __APPLE__
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#else
#include <SDL.h>
#include <SDL_image.h>
#endif
class Enemy;
struct Node
{
    Enemy *data; //stores the shape
    Node *next;  //points to the next node

    Node()
    {
        next = nullptr;
        data = nullptr;
    }
    ~Node()
    {
    }
};
class LinkedList
{
public:
    Node *head; //points to the first node

    LinkedList();
    ~LinkedList();
    void insertathead(Enemy *);       //inserts at head of the linked list
    void displaylist(SDL_Renderer *); //displays the entire list
    void deletepop(SDL_Renderer *);   //deletes the last drawn shape
    void RevList();                   //reverses the order of drawing
    void deletepos(int pos);
    Node *gethead();
    void operator+(Enemy &minion);
};