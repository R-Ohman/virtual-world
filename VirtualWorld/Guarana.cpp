#include "Guarana.h"

Guarana::Guarana(World* currentWorld, unsigned posX, unsigned posY, unsigned age)
	: Plant(currentWorld, 0, posX, posY, age)
{
}

void Guarana::draw()
{
	printf("(G)");
}

string Guarana::getName()
{
    return "Guarana";
}

Organism* Guarana::createClone(unsigned x, unsigned y)
{
    return new Guarana(world, x, y);
}

Guarana::~Guarana()
{
}
