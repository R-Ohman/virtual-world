#include "Dandelion.h"

Dandelion::Dandelion(World* currentWorld, unsigned posX, unsigned posY, unsigned age)
	: Plant(currentWorld, 0, posX, posY, age)
{
}

void Dandelion::draw()
{
    printf("(d)");
}

void Dandelion::action()
{
	for (int i = 0; i < 3; i++)
	{
		Plant::action();
	}
}

string Dandelion::getName()
{
    return "Dandelion";
}

Organism* Dandelion::createClone(unsigned x, unsigned y)
{
    return new Dandelion(world, x, y);
}

Dandelion::~Dandelion()
{
}
