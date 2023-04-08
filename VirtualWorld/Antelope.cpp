#include "Antelope.h"

Antelope::Antelope(World* currentWorld, unsigned posX, unsigned posY, unsigned age)
	: Animal(currentWorld, 4, 4, posX, posY, age)
{
}

void Antelope::draw()
{
    printf(" A ");
}

string Antelope::getName()
{
    return "Antelope";
}

Organism* Antelope::createClone(unsigned x, unsigned y)
{
    return new Antelope(world, x, y);
}

Antelope::~Antelope()
{
}
