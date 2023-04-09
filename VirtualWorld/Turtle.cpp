#include "Turtle.h"

Turtle::Turtle(World* currentWorld, unsigned posX, unsigned posY, unsigned age)
	: Animal(currentWorld, 2, 1, posX, posY, age)
{
}

void Turtle::draw()
{
    string name = "T";
    name += (strength / 10 + '0');
    name += (strength % 10 + '0');
    std::cout << name;
}

string Turtle::getName()
{
    return "Turtle";
}

bool Turtle::repulsedAttack(Organism* entity)
{
	return entity->getStrength() < 5;
}

void Turtle::action()
{
    this->age++;
    if (rand() % 100 < 25) {
        this->age--;
        Animal::action();
    }
}

Organism* Turtle::createClone(unsigned x, unsigned y)
{
    return new Turtle(world, x, y);
}

Turtle::~Turtle()
{
}
