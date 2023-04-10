#include "Belladonna.h"
#include "Parameters.h"

Belladonna::Belladonna(World* currentWorld, unsigned posX, unsigned posY, unsigned age)
	: Plant(currentWorld, BELLADONNA_STRENGTH, BELLADONNA_INITIATIVE, posX, posY, age)
{
}

void Belladonna::draw() const
{
    printf("(B)");
}

string Belladonna::getName() const
{
    return "Belladonna";
}

Organism* Belladonna::createClone(unsigned x, unsigned y) const
{
    return new Belladonna(world, x, y);
}

Belladonna::~Belladonna()
{
}
