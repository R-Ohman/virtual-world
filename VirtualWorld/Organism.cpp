#include "Organism.h"

Organism::Organism(World* currentWorld, int strength, int initiative, int pos_x, int pos_y, int age, bool newBorn)
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

int Organism::getStrength()
{
	return 0;
}

int Organism::getInitiative()
{
	return 0;
}

void Organism::setX(int x)
{
}

void Organism::setY(int y)
{
}

int Organism::getX()
{
	return 0;
}

int Organism::getY()
{
	return 0;
}

int Organism::getAge()
{
	return 0;
}

bool Organism::getNewBorn()
{
	return false;
}

bool Organism::reflected(Organism* entity)
{
	return false;
}

Organism::~Organism()
{
}
