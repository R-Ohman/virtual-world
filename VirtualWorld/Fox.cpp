#include "Fox.h"
#include "World.h"

Fox::Fox(World* currentWorld, unsigned posX, unsigned posY, unsigned age)
	: Animal(currentWorld, 3, 7, posX, posY, age)
{
}

void Fox::draw()
{
    string name = "F";
    name += (strength / 10 + '0');
    name += (strength % 10 + '0');
    std::cout << name;
}

void Fox::action()
{
    this->age++;

    unsigned* newPosition = getNeighboringPosition();
    // Rusz się tylko wtedy gdy jesteś w stanie pokonać organizm, który jest na tym polu
    if (world->entitiesField[newPosition[0]][newPosition[1]] != nullptr
		&& world->entitiesField[newPosition[0]][newPosition[1]]->getStrength() <= this->strength
        ) {
        collision(world->entitiesField[newPosition[0]][newPosition[1]]);
    }
    else if (world->entitiesField[newPosition[0]][newPosition[1]] != nullptr) {
        // Nie przejście na nową pozycję
        std::cout << "COLLISION:[REFUSE] " << this->getName() << " (" << position[0] << "," << position[1] << "), ";
        std::cout << world->entitiesField[newPosition[0]][newPosition[1]]->getName() << "(";
        std::cout << world->entitiesField[newPosition[0]][newPosition[1]]->getX() << ",";
        std::cout << world->entitiesField[newPosition[0]][newPosition[1]]->getY() << ").\n";
    }
    else {
        world->entitiesField[newPosition[0]][newPosition[1]] = this;
        world->entitiesField[getX()][getY()] = nullptr;
        position[0] = newPosition[0];
        position[1] = newPosition[1];
    }
    delete[] newPosition;
}

string Fox::getName()
{
    return "Fox";
}

Organism* Fox::createClone(unsigned x, unsigned y)
{
    return new Fox(world, x, y);
}

Fox::~Fox()
{
}
