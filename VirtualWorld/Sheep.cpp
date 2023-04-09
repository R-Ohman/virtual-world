#include "Sheep.h"

Sheep::Sheep(World* currentWorld, unsigned posX, unsigned posY, unsigned age)
	: Animal(currentWorld, 4, 4, posX, posY, age)
{
}

void Sheep::draw()
{
	string name = "S";
	name += (strength / 10 + '0');
	name += (strength % 10 + '0');
	std::cout << name;
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
