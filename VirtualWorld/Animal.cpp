#include "Animal.h"
#include "World.h"

Animal::Animal(World* world, unsigned strength, unsigned initiative, unsigned posX, unsigned posY, unsigned age)
	: Organism(world, strength, initiative, posX, posY, age)
{
}

bool Animal::sameSpecies(Organism& entity)
{
	return this->getName() == entity.getName();
}

void Animal::breed()
{
	unsigned* freePosition = getUnoccupiedNeighboringPosition();
	if (freePosition != nullptr) {
		// Utworzenie nowego organizmu
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
        
        // Kolizja z tym samym organizmem
        std::cout << "COLLISION:[BREED] " << this->getName() << " (" << getX() << "," << getY() << "), ";
        std::cout << collidingEntity->getName() << " (" << collidingEntity->getX() << "," << collidingEntity->getY() << ").\n";
        // Rozmnożenie się
        breed();
        return;
    }
    else {
        // Sprawdzenie czy przypadkiem żółw nie odparł kolizji
        if (collidingEntity->repulsedAttack(this)) {
            std::cout << "COLLISION:[REFLECT] " << this->getName() << " (" << getX() << "," << getY() << "), ";
            std::cout << collidingEntity->getName() << " (" << collidingEntity->getX() << "," << collidingEntity->getY() << ").\n";
            return;
        }

        // Walka dwóch organizmów
        std::cout << "COLLISION:[FIGHT] " << this->getName() << " (" << getX() << "," << getY() << "), ";
        std::cout << collidingEntity->getName() << " (" << collidingEntity->getX() << "," << collidingEntity->getY() << ").\n";
        // Jeżeli siła jednego zwierzęcia jest wyższa od siły drugiego oraz jeżeli drugim organizmem nie jest HogWeed
        if (dynamic_cast<Hogweed*>(collidingEntity) || dynamic_cast<Belladonna*>(collidingEntity)) {
			// Zwierze, które zjadło HogWeed lub Belladonna umiera
			std::cout << "\t" << this->getName() << " ate " << collidingEntity->getName() << " and died.\n";
			world->entitiesField[getX()][getY()] = nullptr;
            world->entitiesField[collidingEntity->getX()][collidingEntity->getY()] = nullptr;
            world->entitiesList->remove(collidingEntity);
            world->entitiesList->remove(this);
            return;
        }
        
        if (strength > collidingEntity->getStrength() ||
			strength == collidingEntity->getStrength() && this->age > collidingEntity->getAge() ) {
            // Wygrana
            std::cout << "\tVictory of " << this->getName() << "\n";
            // Jeżeli to była guarana to zwiększamy siłę this organizmu
            if (typeid(*collidingEntity).hash_code() == typeid(Guarana).hash_code()) {
                std::cout << "\t\t" << this->getName() << " (" << getX() << "," << getY() << ") strength increased (+3).\n";
                strength += 3;
            }
            // Usunięcie organizmu z planszy
            world->entitiesField[getX()][getY()] = nullptr;
            position[0] = collidingEntity->getX();
            position[1] = collidingEntity->getY();
            world->entitiesField[getX()][getY()] = this;
            world->entitiesList->remove(collidingEntity);
        }
        else {
            // W przeciwnym wypadku przegrana
            // HogWeed to wilcze jagody, zjedzenie ich pokonuje każdy organizm
            std::cout << "\tDefeat of " << this->getName() << ".\n";
            world->entitiesField[getX()][getY()] = nullptr;
            world->entitiesList->remove(this);
        }         
    }
}


Animal::~Animal()
{
}
