#include "Fox.h"

Fox::Fox(World* currentWorld, unsigned posX, unsigned posY, unsigned age)
	: Animal(currentWorld, 3, 7, posX, posY, age)
{
}

void Fox::draw()
{
    printf(" F ");
}

string Fox::getName()
{
    return "Fox";
}

Organism* Fox::createClone(unsigned x, unsigned y)
{
    return new Fox(world, x, y);
}

Fox::~Fox()
{
}
