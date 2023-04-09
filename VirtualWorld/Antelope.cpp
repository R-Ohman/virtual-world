#include "Antelope.h"
#include "World.h"

Antelope::Antelope(World* currentWorld, unsigned posX, unsigned posY, unsigned age)
	: Animal(currentWorld, 4, 4, posX, posY, age)
{
}

void Antelope::draw()
{
	string name = "A";
	name += (strength / 10 + '0');
	name += (strength % 10 + '0');
	std::cout << name;
}

string Antelope::getName()
{
    return "Antelope";
}

Organism* Antelope::createClone(unsigned x, unsigned y)
{
    return new Antelope(world, x, y);
}

void Antelope::collision(Organism* collidingEntity)
{
	// 50% szansy na ucieczke
	if (rand() % 2 && !sameSpecies(*collidingEntity) && collidingEntity->getStrength() > this->strength) {
		unsigned* newPosition = getUnoccupiedNeighboringPosition();
		if (newPosition != nullptr)  {
			// Ucieczka
			std::cout << "COLLISION:[ESCAPE] " << this->getName() << " (" << position[0] << "," << position[1] << "), ";
			std::cout << collidingEntity->getName() << " (" << collidingEntity->getX() << "," << collidingEntity->getY() << ").\n";

			world->entitiesField[newPosition[0]][newPosition[1]] = this;
			world->entitiesField[getX()][getY()] = nullptr;
			position[0] = newPosition[0];
			position[1] = newPosition[1];
		}
		delete[] newPosition;
		// Jeżeli nie ma wolnego miejsza, nie ruszaj się
	}
	else {
		Animal::collision(collidingEntity);
	}
}

unsigned* Antelope::getNeighboringPosition()
{
	unsigned* newPosition = new unsigned[2];
	newPosition[0] = getX();
	newPosition[1] = getY();
   	if (rand() % 2) {
		do {
			// Albo +- 1 albo +- 2 poziomo
			newPosition[0] = getX() + (rand() % 2 ? (rand() % 2 ? 1 : -1) : (rand() % 2 ? 2 : -2));
		} while (newPosition[0] < 0 || newPosition[0] >= world->getWidth());
	}
	else {
		do {
			// Albo +- 1 albo +- 2 pionowo
			newPosition[1] = getY() + (rand() % 2 ? (rand() % 2 ? 1 : -1) : (rand() % 2 ? 2 : -2));
		} while (newPosition[1] < 0 || newPosition[1] >= world->getHeight());
	}
	return newPosition;
}

Antelope::~Antelope()
{
}
