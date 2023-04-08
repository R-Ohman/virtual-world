#include "Grass.h"

Grass::Grass(World* currentWorld, unsigned posX, unsigned posY, unsigned age)
	: Plant(currentWorld, 0, posX, posY, age)
{
}

void Grass::draw()
{
    printf("(g)");
}

string Grass::getName()
{
    return "Grass";
}

Organism* Grass::createClone(unsigned x, unsigned y)
{
    return new Grass(world, x, y);
}

Grass::~Grass()
{
}
