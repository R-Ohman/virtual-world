#include "Antelope.h"
#include "World.h"

Antelope::Antelope(World* currentWorld, unsigned posX, unsigned posY, unsigned age)
	: Animal(currentWorld, ANTELOPE_STRENGTH, ANTELOPE_INITIATIVE, posX, posY, age)
{
}


void Antelope::draw() const
{
	// Max strength that can be displayed is 99
	string name = "A";
	if (this->strength < 100) {
		name += (strength / 10 + '0');
		name += (strength % 10 + '0');
	}
	else {
		// Antelope has strength 100+
		name = "-A-";
	}
	std::cout << name;
}


string Antelope::getName() const
{
    return "Antelope";
}


Organism* Antelope::createClone(unsigned x, unsigned y) const
{
    return new Antelope(world, x, y);
}


void Antelope::collision(Organism* collidingEntity)
{
	// 50% chance to escape the collision with stronger organism
	if (rand() % 2 && !sameSpecies(*collidingEntity) && collidingEntity->getStrength() > this->strength)
	{
		std::cout << "COLLISION:[ESCAPE] " << this->getName() << " (" << position[0] << "," << position[1] << "), ";
		std::cout << collidingEntity->getName() << " (" << collidingEntity->getX() << "," << collidingEntity->getY() << ").\n";
		
		unsigned* newPosition = getUnoccupiedNeighboringPosition();
		if (newPosition != nullptr)  {
			// If there is unoccupied neighboring position, move there
			
			world->entitiesField[newPosition[0]][newPosition[1]] = this;
			world->entitiesField[getX()][getY()] = nullptr;
			position[0] = newPosition[0];
			position[1] = newPosition[1];
		}
		delete[] newPosition;
	}
	else {
		Animal::collision(collidingEntity);
	}
}


unsigned* Antelope::getNeighboringPosition() const
{
	unsigned* newPosition = new unsigned[2];
	newPosition[0] = getX();
	newPosition[1] = getY();
	
	// Move by X axis
   	if (rand() % 2) {
		do {
			// Move 1 or 2 steps right or left
			newPosition[0] = getX() + (rand() % 2 ? (rand() % 2 ? 1 : -1) : (rand() % 2 ? 2 : -2));
		} while (newPosition[0] < 0 || newPosition[0] >= world->getWidth());
	}
	// Move by Y axis
	else {
		do {
			// Move 1 or 2 steps down or up
			newPosition[1] = getY() + (rand() % 2 ? (rand() % 2 ? 1 : -1) : (rand() % 2 ? 2 : -2));
		} while (newPosition[1] < 0 || newPosition[1] >= world->getHeight());
	}
	
	return newPosition;
}


Antelope::~Antelope()
{
}
