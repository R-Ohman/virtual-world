#include "Animal.h"
#include "Human.h"

Animal::Animal(World* world, unsigned strength, unsigned initiative, unsigned posX, unsigned posY, unsigned age)
	: Organism(world, strength, initiative, posX, posY, age)
{
}

bool Animal::doSpeciesMatch(Organism& entity)
{
	return false;
}

void Animal::breed()
{
}

void Animal::action()
{
}

void Animal::collision(Organism* collidingEntity)
{
    if (doSpeciesMatch(*collidingEntity)) {
        if (typeid(*collidingEntity).hash_code() == typeid(Human).hash_code()) {
            return;
        }
        // Kolizja z tym samym organizmem
        std::cout << "Colliding entities: [MATCH] " << this->getName() << " (" << position[0] << "," << position[1] << "), ";
        std::cout << collidingEntity->getName() << " (" << collidingEntity->getX() << "," << collidingEntity->getY() << ").\n";
        // Rozmnożenie się
        breed();
        return;
    }
    else {
        // Sprawdzenie czy przypadkiem żółw nie odparł kolizji
        if (collidingEntity->repulsedAttack(this)) {
            std::cout << "Colliding entities: [REFLECT] " << this->getName() << " (" << position[0] << "," << position[1] << "), ";
            std::cout << collidingEntity->getName() << " (" << collidingEntity->getX() << "," << collidingEntity->getY() << ").\n";
            return;
        }

        // Walka dwóch organizmów
        std::cout << "Colliding entities: [FIGHT] " << this->getName() << " (" << position[0] << "," << position[1] << "), ";
        std::cout << collidingEntity->getName() << " (" << collidingEntity->getX() << "," << collidingEntity->getY() << ").\n";
        // Jeżeli siła jednego zwierzęcia jest wyższa od siły drugiego oraz jeżeli drugim organizmem nie jest HogWeed
        if (strength >= collidingEntity->getStrength() && typeid(*collidingEntity).hash_code() != typeid(Hogweed).hash_code()) {
            // Wygrana
            std::cout << "Victory of " << this->getName() << "\n";
            // Jeżeli to była guarana to zwiększamy siłę this organizmu
            if (typeid(*collidingEntity).hash_code() == typeid(Guarana).hash_code()) {
                std::cout << this->getName() << " (" << position[0] << "," << position[1] << ") strength increased.\n";
                strength += 3;
            }
            // Usunięcie organizmu z planszy
            world->entitiesField[position[0]][position[1]] = nullptr;
            position[0] = collidingEntity->getX();
            position[1] = collidingEntity->getY();
            world->entitiesField[position[0]][position[1]] = this;

            world->entitiesList->remove(collidingEntity);
        }
        else {
            // W przeciwnym wypadku przegrana
            // HogWeed to wilcze jagody, zjedzenie ich pokonuje każdy organizm
            std::cout << "Defeat of " << this->getName() << ".\n";
            world->entitiesField[position[0]][position[1]] = NULL;
            world->entitiesList->remove(this);
        }
    }
}


Animal::~Animal()
{
}
