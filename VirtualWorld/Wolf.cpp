#include "Wolf.h"

Wolf::Wolf(World* currentWorld, unsigned posX, unsigned posY, unsigned age)
	: Animal(currentWorld, 9, 5, posX, posY, age)
{
}

void Wolf::draw()
{
    printf(" W ");
}

string Wolf::getName()
{
    return "Wolf";
}

Organism* Wolf::createClone(unsigned x, unsigned y)
{
    return new Wolf(world, x, y);
}

Wolf::~Wolf()
{
}
