#include "Guarana.h"
#include "Parameters.h"

Guarana::Guarana(World* currentWorld, unsigned posX, unsigned posY, unsigned age)
	: Plant(currentWorld, GUARANA_STRENGTH, GUARANA_INITIATIVE, posX, posY, age)
{
}


void Guarana::draw() const
{
	printf("(G)");
}


string Guarana::getName() const
{
    return "Guarana";
}


Organism* Guarana::createClone(unsigned x, unsigned y) const
{
    return new Guarana(world, x, y);
}


Guarana::~Guarana()
{
}
