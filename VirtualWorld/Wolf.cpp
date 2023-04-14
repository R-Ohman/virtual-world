#include "Wolf.h"
#include "Parameters.h"

Wolf::Wolf(World* currentWorld, unsigned posX, unsigned posY, unsigned age, unsigned strength)
	: Animal(currentWorld, strength, WOLF_INITIATIVE, posX, posY, age)
{
}


void Wolf::draw() const
{
	// Max strength that can be displayed is 99
	string name = "W";
	if (this->strength < 100) {
		name += (strength / 10 + '0');
		name += (strength % 10 + '0');
	}
	else {
		// Antelope has strength 100+
		name = "-W-";
	}
	std::cout << name;
}


string Wolf::getName() const
{
    return "Wolf";
}


Organism* Wolf::createClone(unsigned x, unsigned y) const
{
    return new Wolf(world, x, y);
}


Wolf::~Wolf()
{
}
