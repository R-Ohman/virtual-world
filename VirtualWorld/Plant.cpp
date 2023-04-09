#include "Plant.h"

Plant::Plant(World* currentWorld, unsigned strength, unsigned posX, unsigned posY, unsigned age)
	: Organism(currentWorld, strength, 0, posX, posY, age)
{
}

void Plant::action()
{
	unsigned* freeField = this->getUnoccupiedNeighboringPosition();
	
	if (freeField != nullptr) {
		// szansa 20% na rozmnozenie
		if (rand() % 100 < 20) {
			std::cout << "REPRODUCING: " << this->getName() << "(" << position[0] << ", " << position[1] << ")";
			std::cout << " is reproducing to (" << freeField[0] << ", " << freeField[1] << ").\n";
			createClone(freeField[0], freeField[1]);
		}
	}
}

Plant::~Plant()
{
}
