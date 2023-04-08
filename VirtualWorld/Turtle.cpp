#include "Turtle.h"

Turtle::Turtle(World* currentWorld, unsigned posX, unsigned posY, unsigned age)
	: Animal(currentWorld, 2, 1, posX, posY, age)
{
}

void Turtle::draw()
{
    printf(" T ");
}

string Turtle::getName()
{
    return "Turtle";
}

bool Turtle::repulsedAttack(Organism* entity)
{
    return false;
}

Organism* Turtle::createClone(unsigned x, unsigned y)
{
    return new Turtle(world, x, y);
}

Turtle::~Turtle()
{
}
