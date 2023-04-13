#include "Organism.h"
#include "World.h"


Organism::Organism(World* world, unsigned strength, unsigned initiative, unsigned posX, unsigned posY, unsigned age)
		: world(world), strength(strength), initiative(initiative), position{ posX, posY }, age(age)
{
	// Add organism to the world
	if (posX < world->getWidth() && posY < world->getHeight()) {
		world->entitiesField[posX][posY] = this;
	}
	world->entitiesList->add(this);
}


// Return a pointer to 2-elements array with x and y coordinates of a neighboring position
unsigned* Organism::getNeighboringPosition() const
{
	unsigned* newPosition = new unsigned[2];
	newPosition[0] = getX();
	newPosition[1] = getY();
	
	// Move by X axis
	if (rand() % 2) {
		do {
			// Move 1 step left or right while it is out of the world bounds
			newPosition[0] = getX() + (rand() % 2 ? 1 : -1);
		} while (newPosition[0] < 0 || newPosition[0] >= world->getWidth());
	}
	// Move by Y axis
	else {
		do {
			// Move 1 step up or down while it is out of the world bounds
			newPosition[1] = getY() + (rand() % 2 ? 1 : -1);
		} while (newPosition[1] < 0 || newPosition[1] >= world->getHeight());
	}
	
	return newPosition;
}


// Return a pointer to 2-elements array with x and y coordinates of a neighboring position that is unoccupied
unsigned* Organism::getUnoccupiedNeighboringPosition() const
{
	bool allOccupied = true;
	for (int i = -1; i < 2; i+=2) {
		if (getX() + i >= 0 && getX() + i < world->getWidth() &&
			world->entitiesField[getX() + i][getY()] == nullptr
			) {
			allOccupied = false;
			break;
		}
		
		if (getY() + i >= 0 && getY() + i < world->getHeight() &&
			world->entitiesField[getX()][getY() + i] == nullptr
			) {
			allOccupied = false;
			break;
		}
	}
	// If all neighboring positions are occupied, return nullptr
	if (allOccupied) {
		return nullptr;
	}
	
	unsigned* unoccupiedPosition;
	do {
		// Get a random neighboring position while it is occupied (100% unoccupied position exists)
		unoccupiedPosition = getNeighboringPosition();
	} while (world->entitiesField[unoccupiedPosition[0]][unoccupiedPosition[1]] != nullptr);
	
	return unoccupiedPosition;
}


unsigned Organism::getStrength() const
{
	return this->strength;
}


unsigned Organism::getInitiative() const
{
	return this->initiative;
}


unsigned Organism::getX() const
{
	return this->position[0];
}


unsigned Organism::getY() const
{
	return this->position[1];
}


unsigned Organism::getAge() const
{
	return this->age;
}


void Organism::setX(unsigned x)
{
	this->position[0] = x;
}


void Organism::setY(unsigned y)
{
	this->position[1] = y;
}


void Organism::setAge(unsigned age)
{
	this->age = age;
}


bool Organism::repulsedAttack(Organism* entity) const
{
	// Turtle is only one organism who can repulse attack
	return false;
}


Organism::~Organism()
{
}
