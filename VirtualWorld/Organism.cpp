#include "Organism.h"
#include "World.h"

Organism::Organism(World* world, unsigned strength, unsigned initiative, unsigned posX, unsigned posY, unsigned age)
		: world(world), strength(strength), initiative(initiative), position{ posX, posY }, age(age)
{
	if (posX < world->getWidth() && posY < world->getHeight()) {
		world->entitiesField[posX][posY] = this;
	}
	world->entitiesList->add(this);
}

unsigned* Organism::getNeighboringPosition()
{
	unsigned* newPosition = new unsigned[2];
	newPosition[0] = getX();
	newPosition[1] = getY();
	if (rand() % 2) {
		do {
			newPosition[0] = getX() + (rand() % 2 ? 1 : -1);
		} while (newPosition[0] < 0 || newPosition[0] >= world->getWidth());
	}
	else {
		do {
			newPosition[1] = getY() + (rand() % 2 ? 1 : -1);
		} while (newPosition[1] < 0 || newPosition[1] >= world->getHeight());
	}
	return newPosition;
}

unsigned* Organism::getUnoccupiedNeighboringPosition()
{
	bool allOccupied = true;
	// check if the is any unoccupied neighboring position (up, left, right, down, world->entitiesField)
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
	if (allOccupied) {
		return nullptr;
	}
	// Generuje dopóki nie znajdzie wolnego sąsiada
	unsigned* unoccupiedPosition;
	do {
		unoccupiedPosition = getNeighboringPosition();
	} while (world->entitiesField[unoccupiedPosition[0]][unoccupiedPosition[1]] != nullptr);
	
	return unoccupiedPosition;
}

unsigned Organism::getStrength()
{
	return strength;
}

unsigned Organism::getInitiative()
{
	return initiative;
}

void Organism::setX(unsigned x)
{
	this->position[0] = x;
}

void Organism::setY(unsigned y)
{
	this->position[1] = y;
}

unsigned Organism::getX()
{
	return this->position[0];
}

unsigned Organism::getY()
{
	return this->position[1];
}

unsigned Organism::getAge()
{
	return this->age;
}

void Organism::setAge(unsigned age)
{
	this->age = age;
}

bool Organism::repulsedAttack(Organism* entity)
{
	return false;
}

Organism::~Organism()
{
}
