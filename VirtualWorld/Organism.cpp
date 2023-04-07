#include "Organism.h"

Organism::Organism(World* world, unsigned strength, unsigned initiative, unsigned posX, unsigned posY, unsigned age)
		: world(world), strength(strength), initiative(initiative), position{ posX, posY }, age(age)
{
}

int* Organism::pathFindNewField()
{
	return nullptr;
}

int* Organism::pathFindNewUnoccupiedField()
{
	return nullptr;
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

bool Organism::repulsedAttack(Organism* entity)
{
	return false;
}

Organism::~Organism()
{
}
