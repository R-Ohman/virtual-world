#include "Plant.h"

Plant::Plant(World* currentWorld, unsigned strength, unsigned initiative, unsigned posX, unsigned posY, unsigned age)
	: Organism(currentWorld, strength, initiative, posX, posY, age)
{
}


void Plant::action()
{
	this->age++;

	// 20% chance to reproduce
	if (rand() % 100 < 20) {
		unsigned* freeField = this->getUnoccupiedNeighboringPosition();

		// If free field was found, create a clone
		if (freeField != nullptr) {
			std::cout << "REPRODUCING: " << this->getName() << "(" << position[0] << ", " << position[1] << ")";
			std::cout << " is reproducing to (" << freeField[0] << ", " << freeField[1] << ").\n";
			createClone(freeField[0], freeField[1]);
		}
	}
}


Plant::~Plant()
{
}
