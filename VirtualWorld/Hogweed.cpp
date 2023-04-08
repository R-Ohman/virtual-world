#include "Hogweed.h"

Hogweed::Hogweed(World* currentWorld, unsigned posX, unsigned posY, unsigned age)
	: Plant(currentWorld, 10, posX, posY, age)
{
}

void Hogweed::draw()
{
    printf("(H)");
}

string Hogweed::getName()
{
    return "Hogweed";
}

Organism* Hogweed::createClone(unsigned x, unsigned y)
{
    return new Hogweed(world, x, y);
}

Hogweed::~Hogweed()
{
}
