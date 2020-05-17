#include "LinkedList.hpp"
#include "Enemy.hpp"
#include <iostream>
#include <SDL.h>
using namespace std;
LinkedList::LinkedList()
{
    head = nullptr;
}
LinkedList::~LinkedList()
{
    delete head;
}
void LinkedList::insertathead(Enemy *art)
{
    Node *newnode = new Node();

    if (art == nullptr)
    {
    }

    else
    {
        newnode->data = art;
        newnode->next = head;
        if (head == nullptr)
        {
            head = newnode; //the new node goes in front of head and becomes the head
        }
        else
        {
            newnode->next = head;
            head = newnode;
        }
    }
}

void LinkedList::displaylist(SDL_Renderer *g)
{
    Node *temp = NULL;
    head = this->head;
    RevList(); //called for drawing the shapes on top of each other
    temp = head;
    while (temp)
    {
        temp->data->update();
        temp->data->render();
        temp = temp->next;
    }
    RevList();
}

void LinkedList::deletepop(SDL_Renderer *g)
{
    if (head == NULL)
    {
        cout << "list empty" << endl;
        return;
    }
    Node *h = NULL;
    h = head;
    head = head->next;
    delete h;
}

void LinkedList::RevList() // we will use this function while switching the shapes
{

    if (head != NULL && head->next != NULL)
    {
        Node *previous, *current, *nex;
        previous = head;
        current = previous->next;
        nex = current->next;
        previous->next = NULL;
        while (nex)
        {
            current->next = previous;
            previous = current;
            current = nex;
            nex = nex->next;
        }
        current->next = previous;
        head = current;
    }
}

void LinkedList::deletepos(int pos)
{
    Node *current = new Node;
    Node *previous = new Node;
    current = head;
    for (int i = 1; i < pos; i++)
    {
        previous = current;
        current = current->next;
    }

    previous->next = current->next;
}

Node *LinkedList::gethead()
{
    return head;
}

void LinkedList::operator+(Enemy &minion)
{
    this->insertathead(&(minion));
}