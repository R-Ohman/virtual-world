#include "Belladonna.h"

Belladonna::Belladonna(World* currentWorld, unsigned posX, unsigned posY, unsigned age)
	: Plant(currentWorld, 99, posX, posY, age)
{
}

void Belladonna::draw()
{
    printf("(B)");
}

string Belladonna::getName()
{
    return "Belladonna";
}

Organism* Belladonna::createClone(unsigned x, unsigned y)
{
    return new Belladonna(world, x, y);
}

Belladonna::~Belladonna()
{
}
