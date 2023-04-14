#include "Dandelion.h"
#include "Parameters.h"

Dandelion::Dandelion(World* currentWorld, unsigned posX, unsigned posY, unsigned age, unsigned strength)
	: Plant(currentWorld, strength, DANDELION_INITIATIVE, posX, posY, age)
{
}


void Dandelion::draw() const
{
    printf("(d)");
}


void Dandelion::action()
{
	// Three tries to spawn a new organism
	for (int i = 0; i < 3; i++)
	{
		Plant::action();
	}
	// Danddelion 3 times got age increase, so decrease it by 2
	this->age -= 2;
}


string Dandelion::getName() const
{
    return "Dandelion";
}


Organism* Dandelion::createClone(unsigned x, unsigned y) const
{
    return new Dandelion(world, x, y);
}


Dandelion::~Dandelion()
{
}
