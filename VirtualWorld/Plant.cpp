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
			std::cout << "Plant " << this->getName() << " is reproducing to (" << freeField[0] << ", " << freeField[1] << ")." << std::endl;
			createClone(freeField[0], freeField[1]);
		}
	}
	else {
		printf("No free field for plant to reproduce.\n");
	}
}

Plant::~Plant()
{
}
