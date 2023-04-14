#include "Fox.h"
#include "World.h"

Fox::Fox(World* currentWorld, unsigned posX, unsigned posY, unsigned age, unsigned strength)
	: Animal(currentWorld, strength, FOX_INITIATIVE, posX, posY, age)
{
}


void Fox::draw() const
{
    // Max strength that can be displayed is 99
    string name = "F";
    if (this->strength < 100) {
        name += (strength / 10 + '0');
        name += (strength % 10 + '0');
    }
    else {
        // Antelope has strength 100+
        name = "-F-";
    }
    std::cout << name;
}


void Fox::action()
{
    this->age++;
    unsigned* newPosition = getNeighboringPosition();
    
	// Move to occupid position only if it's weaker
    if (world->entitiesField[newPosition[0]][newPosition[1]] != nullptr
		&& world->entitiesField[newPosition[0]][newPosition[1]]->getStrength() <= this->strength
        ) {
        collision(world->entitiesField[newPosition[0]][newPosition[1]]);
    }
    else if (world->entitiesField[newPosition[0]][newPosition[1]] != nullptr) {
		// Neighbouring position is occupied by stronger organism, so don't move
        std::cout << "COLLISION:[REFUSE] " << this->getName() << " (" << position[0] << "," << position[1] << "), ";
        std::cout << world->entitiesField[newPosition[0]][newPosition[1]]->getName() << "(";
        std::cout << world->entitiesField[newPosition[0]][newPosition[1]]->getX() << ",";
        std::cout << world->entitiesField[newPosition[0]][newPosition[1]]->getY() << ").\n";
    }
    else {
		//Unoccupied neighboring position, move there
        world->entitiesField[newPosition[0]][newPosition[1]] = this;
        world->entitiesField[getX()][getY()] = nullptr;
        position[0] = newPosition[0];
        position[1] = newPosition[1];
    }
    delete[] newPosition;
}


string Fox::getName() const
{
    return "Fox";
}


Organism* Fox::createClone(unsigned x, unsigned y) const
{
    return new Fox(world, x, y);
}


Fox::~Fox()
{
}
