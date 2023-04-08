#include "Plant.h"

Plant::Plant(World* currentWorld, unsigned strength, unsigned posX, unsigned posY, unsigned age)
	: Organism(currentWorld, strength, posX, posY, age)
{
}

void Plant::action()
{
	unsigned* freeField = this->getUnoccupiedNeighboringPosition();
	
	if (freeField != nullptr) {
		printf("Plant %s is reproducing to (%d, %d).\n", this->getName().c_str(), freeField[0], freeField[1]);
		createClone(freeField[0], freeField[1]);
	}
	else {
		printf("No free field for plant to reproduce.\n");
	}
}

Plant::~Plant()
{
}
