#include "Animal.h"
#include "World.h"

Animal::Animal(World* world, unsigned strength, unsigned initiative, unsigned posX, unsigned posY, unsigned age)
	: Organism(world, strength, initiative, posX, posY, age)
{
}


bool Animal::sameSpecies(const Organism& entity) const
{
	return this->getName() == entity.getName();
}


void Animal::breed() const
{
	// Create the same organism in the neighboring position
	unsigned* freePosition = getUnoccupiedNeighboringPosition();

	if (freePosition != nullptr) {
		std::cout << "\tBREEDING: " << this->getName() << "(" << freePosition[0] << ", " << freePosition[1] << ")\n";
		createClone(freePosition[0], freePosition[1]);
		// Zwolnienie pamięci
		delete[] freePosition;
	}
}


void Animal::action()
{
	this->age++;

	unsigned* newPosition = getNeighboringPosition();

	std::cout << "MOVING:" << this->getName() << " from (" << getX() << ", " << getY() << ") to (" << newPosition[0] << ", " << newPosition[1] << ").\n";
	if (world->entitiesField[newPosition[0]][newPosition[1]] != nullptr) {
		collision(world->entitiesField[newPosition[0]][newPosition[1]]);
	}
	else {
		world->entitiesField[newPosition[0]][newPosition[1]] = this;
		world->entitiesField[getX()][getY()] = nullptr;
		position[0] = newPosition[0];
		position[1] = newPosition[1];
	}
	delete[] newPosition;
}


void Animal::collision(Organism* collidingEntity)
{
	if (sameSpecies(*collidingEntity)) {
		// If the same species, then create a new organism
		std::cout << "COLLISION:[BREED] " << this->getName() << " (" << getX() << "," << getY() << "), ";
		std::cout << collidingEntity->getName() << " (" << collidingEntity->getX() << "," << collidingEntity->getY() << ").\n";

		breed();
		return;
	}

	if (collidingEntity->repulsedAttack(this)) {
		std::cout << "COLLISION:[REFLECT] " << this->getName() << " (" << getX() << "," << getY() << "), ";
		std::cout << collidingEntity->getName() << " (" << collidingEntity->getX() << "," << collidingEntity->getY() << ").\n";
		return;
	}

	// Fight
	std::cout << "COLLISION:[FIGHT] " << this->getName() << " (" << getX() << "," << getY() << "), ";
	std::cout << collidingEntity->getName() << " (" << collidingEntity->getX() << "," << collidingEntity->getY() << ").\n";
	
	if (dynamic_cast<Hogweed*>(collidingEntity) || dynamic_cast<Belladonna*>(collidingEntity)) {
		// Animal who eats Hogweed or Belladonna dies
		std::cout << "\t" << this->getName() << " ate " << collidingEntity->getName() << " and died.\n";

		// Delete both organisms (animal and eaten plant) from the world
		world->entitiesField[getX()][getY()] = nullptr;
		world->entitiesField[collidingEntity->getX()][collidingEntity->getY()] = nullptr;
		world->entitiesList->remove(collidingEntity);
		world->entitiesList->remove(this);
		return;
	}

	// If current organism is stronger (or older) than the colliding one, then it wins
	if (this->strength > collidingEntity->getStrength() ||
		this->strength == collidingEntity->getStrength() && this->age > collidingEntity->getAge()
		) {
		std::cout << "\tVictory of " << this->getName() << "\n";
		
		if (dynamic_cast<Guarana*>(collidingEntity)) {
			// Eating Guarana increases strength
			std::cout << "\t\t" << this->getName() << " (" << getX() << "," << getY() << ") strength increased (+"<< GUARANA_BONUS << ").\n";
			this->strength += GUARANA_BONUS;
		}
		
		// Delete animal from current position and move it to new position
		world->entitiesField[getX()][getY()] = nullptr;
		position[0] = collidingEntity->getX();
		position[1] = collidingEntity->getY();
		world->entitiesField[getX()][getY()] = this;

		// Delete organism who lost the fight
		world->entitiesList->remove(collidingEntity);
		return;
	}
	
	// Current animal loses the fight, so delete it from the world
	std::cout << "\tDefeat of " << this->getName() << ".\n";
	world->entitiesField[getX()][getY()] = nullptr;
	world->entitiesList->remove(this);
}


Animal::~Animal()
{
}
