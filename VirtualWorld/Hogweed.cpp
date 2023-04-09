#include "Hogweed.h"
#include "World.h"

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

void Hogweed::action()
{
	unsigned* posX = &this->position[0], * posY = &this->position[1];
	std::cout << "MURDER:" << getName() << " at (" << *posX << ", " << *posY << ") kills all animals-neighbours" << std::endl;
	for (int i = -1; i < 2; i += 2) {
		if (*posX + i >= 0 && *posX + i < world->getWidth()) {
			if (world->entitiesField[*posX + i][*posY] != nullptr && dynamic_cast<Animal*>(world->entitiesField[*posX + i][*posY]) != nullptr) {
				std::cout << "\t" << getName() << " murdered " << world->entitiesField[*posX + i][*posY]->getName() << " (" << *posX + i << ", " << *posY << ")" << std::endl;
				world->entitiesList->remove(world->entitiesField[*posX + i][*posY]);
				world->entitiesField[*posX + i][*posY] = nullptr;
			}
		}

		if (*posY + i >= 0 && *posY + i < world->getHeight()) {
			if (world->entitiesField[*posX][*posY + i] != nullptr && dynamic_cast<Animal*>(world->entitiesField[*posX][*posY + i]) != nullptr) {
				std::cout << "\t" << getName() << " murdered " << world->entitiesField[*posX][*posY + i]->getName() << " (" << *posX<< ", " << *posY + i << ")" << std::endl;
				world->entitiesList->remove(world->entitiesField[*posX][*posY + i]);
				world->entitiesField[*posX][*posY + i] = nullptr;
			}
		}
	}

	Plant::action();
}

Organism* Hogweed::createClone(unsigned x, unsigned y)
{
	return new Hogweed(world, x, y);
}

Hogweed::~Hogweed()
{
}
