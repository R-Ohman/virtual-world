#include "Grass.h"
#include "Parameters.h"

Grass::Grass(World* currentWorld, unsigned posX, unsigned posY, unsigned age, unsigned strength)
	: Plant(currentWorld, strength, GRASS_INITIATIVE, posX, posY, age)
{
}


void Grass::draw() const
{
    printf("(g)");
}


string Grass::getName() const
{
    return "Grass";
}


Organism* Grass::createClone(unsigned x, unsigned y) const
{
    return new Grass(world, x, y);
}


Grass::~Grass()
{
}
