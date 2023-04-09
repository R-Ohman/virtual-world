#include "Wolf.h"

Wolf::Wolf(World* currentWorld, unsigned posX, unsigned posY, unsigned age)
	: Animal(currentWorld, 9, 5, posX, posY, age)
{
}

void Wolf::draw()
{
	string name = "W";
	name += (strength / 10 + '0');
	name += (strength % 10 + '0');
	std::cout << name;
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
