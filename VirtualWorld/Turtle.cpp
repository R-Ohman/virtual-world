#include "Turtle.h"
#include "Parameters.h"

Turtle::Turtle(World* currentWorld, unsigned posX, unsigned posY, unsigned age)
	: Animal(currentWorld, TURTLE_STRENGTH, TURTLE_INITIATIVE, posX, posY, age)
{
}


void Turtle::draw() const
{
	// Max strength that can be displayed is 99
	string name = "T";
	if (this->strength < 100) {
		name += (strength / 10 + '0');
		name += (strength % 10 + '0');
	}
	else {
		// Antelope has strength 100+
		name = "-T-";
	}
	std::cout << name;
}


string Turtle::getName() const
{
    return "Turtle";
}


bool Turtle::repulsedAttack(Organism* entity) const
{
	// Turtle repulses attack from every organism with strength less than 5
	return entity->getStrength() < 5;
}


void Turtle::action()
{
    this->age++;

	// Turtle has 25% chance to move
    if (rand() % 100 < 25) {
        Animal::action();
		// Age has been increased twice, so decrease it
		this->age--;
    }
}


Organism* Turtle::createClone(unsigned x, unsigned y) const
{
    return new Turtle(world, x, y);
}


Turtle::~Turtle()
{
}
