#include "Sheep.h"
#include "Parameters.h"

Sheep::Sheep(World* currentWorld, unsigned posX, unsigned posY, unsigned age)
	: Animal(currentWorld, SHEEP_STRENGTH, SHEEP_INITIATIVE, posX, posY, age)
{
}


void Sheep::draw() const
{
	// Max strength that can be displayed is 99
	string name = "S";
	if (this->strength < 100) {
		name += (strength / 10 + '0');
		name += (strength % 10 + '0');
	}
	else {
		// Antelope has strength 100+
		name = "-S-";
	}
	std::cout << name;
}


string Sheep::getName() const
{
	return "Sheep";
}


Organism* Sheep::createClone(unsigned x, unsigned y) const
{
	return new Sheep(world, x, y);
}


Sheep::~Sheep()
{
}
