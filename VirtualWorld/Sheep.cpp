#include "Sheep.h"

Sheep::Sheep(World* currentWorld, unsigned posX, unsigned posY, unsigned age)
	: Animal(currentWorld, 4, 4, posX, posY, age)
{
}

void Sheep::draw()
{
	printf(" S ");
}

string Sheep::getName()
{
	return "Sheep";
}

Organism* Sheep::createClone(unsigned x, unsigned y)
{
	return new Sheep(world, x, y);
}

Sheep::~Sheep()
{
}
