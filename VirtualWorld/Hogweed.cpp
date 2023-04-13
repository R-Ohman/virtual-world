#include "Hogweed.h"
#include "World.h"


Hogweed::Hogweed(World* currentWorld, unsigned posX, unsigned posY, unsigned age)
	: Plant(currentWorld, HOGWEED_STRENGTH, HOGWEED_INITIATIVE, posX, posY, age)
{
}


void Hogweed::draw() const
{
	printf("(H)");
}


string Hogweed::getName() const
{
	return "Hogweed";
}


Organism* Hogweed::createClone(unsigned x, unsigned y) const
{
	return new Hogweed(world, x, y);
}


void Hogweed::action()
{
	// Kill all animals in the neighborhood
	unsigned* const posX = &this->position[0], * const posY = &this->position[1];	// Variables for better readability
	
	// First iteration - check the left and upper positions, second iteration - check the right and lower positions
	for (int i = -1; i < 2; i += 2) {
		
		// Check if the neighboring position is in the bounds
		if (*posX + i >= 0 && *posX + i < world->getWidth()) {
			// Check if the neighboring position is occupied by an animal
			if (world->entitiesField[*posX + i][*posY] != nullptr && dynamic_cast<Animal*>(world->entitiesField[*posX + i][*posY]) != nullptr)
			{
				std::cout << "MURDER: " << getName() << " (" << *posX << ", " << *posY << ") ";
				std::cout << "murdered " << world->entitiesField[*posX + i][*posY]->getName() << " (" << *posX + i << ", " << *posY << ")\n";
				// Delete animal
				world->entitiesList->remove(world->entitiesField[*posX + i][*posY]);
				world->entitiesField[*posX + i][*posY] = nullptr;
			}
		}

		// Check if the neighboring position is in the bounds
		if (*posY + i >= 0 && *posY + i < world->getHeight()) {
			// Check if the neighboring position is occupied by an animal
			if (world->entitiesField[*posX][*posY + i] != nullptr && dynamic_cast<Animal*>(world->entitiesField[*posX][*posY + i]) != nullptr)
			{
				std::cout << "MURDER: " << getName() << " (" << *posX << ", " << *posY << ") ";
				std::cout << "murdered " << world->entitiesField[*posX][*posY + i]->getName() << " (" << *posX << ", " << *posY + i<< ")\n";
				// Delete animal
				world->entitiesList->remove(world->entitiesField[*posX][*posY + i]);
				world->entitiesField[*posX][*posY + i] = nullptr;
			}
		}
	}

	Plant::action();
}


Hogweed::~Hogweed()
{
}
