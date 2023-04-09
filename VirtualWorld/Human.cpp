#include "Human.h"

Human::Human(World* world, unsigned posX, unsigned posY, unsigned age, unsigned regeneration)
	: Animal(world, 5, 4, posX, posY, age)
{
	humanRegeneration = regeneration;
}

void Human::draw()
{
	string name = "H";
	name += (strength / 10 + '0');
	name += (strength % 10 + '0');
	std::cout << name;
}

void Human::action()
{
	this->age++;
	if (this->humanRegeneration > 0) {
		this->humanRegeneration--;
	};
	char userMove;
	unsigned* posX = &this->position[0], *posY = &this->position[1];
	unsigned newPosition[2] = { *posX, *posY };
	printf("\nHuman position(%d, %d)\n", *posX, *posY);
	printf("Move (arrows) or use special ability (r):\n");
	
	while (true) {
		userMove = getchar();
		if (userMove == 'a' && *posX > 0) {
			newPosition[0] -= 1;
			break;
		}
		else if (userMove == 'd' && *posX < world->getWidth() - 1) {
			newPosition[0] += 1;
			break;
		}
		else if (userMove == 'w' && *posY > 0) {
			newPosition[1] -= 1;
			break;
		}
		else if (userMove == 's' && *posY < world->getHeight() - 1) {
			newPosition[1] += 1;
			break;
		}
		else if (userMove == 'r') {
			if (humanRegeneration == 0) {
				printf("\tHuman's superpower is activated! Make a move.\n");
				humanRegeneration = 10;

			}
			else if (humanRegeneration > 5) {
				printf("\tYou have already activated your superpower!\n");
				printf("\tIt will be disactivated in %d turns.\n", humanRegeneration - 5);
			}
			else {
				printf("\tYou will be able to activate it in %d turns!\n", humanRegeneration);
			}
		}
	}
	world->entitiesField[*posX][*posY] = nullptr;
	std::cout << "\nMOVING: " << this->getName() << " from (" << getX() << ", " << getY() << ") to (" << newPosition[0] << ", " << newPosition[1] << ").\n";

	if (humanRegeneration > 5) {
		// Zabija sasiadow, porusza sie i ponownie zabija sasiadow
		this->specialAbility();
		*posX = newPosition[0];
		*posY = newPosition[1];
		world->entitiesField[*posX][*posY] = this;
		this->specialAbility();
	}
	else {
		if (world->entitiesField[newPosition[0]][newPosition[1]] != nullptr) {
			collision(world->entitiesField[newPosition[0]][newPosition[1]]);
		}
		else {
			*posX = newPosition[0];
			*posY = newPosition[1];
			world->entitiesField[*posX][*posY] = this;
		}
	}
}

int Human::getRegeneration()
{
	return humanRegeneration;
}

string Human::getName()
{
	return "Human";
}

void Human::specialAbility()
{
	unsigned* posX = &this->position[0], *posY = &this->position[1];
	for (int i = -1; i < 2; i += 2) {
		if (*posX + i >= 0 && *posX + i < world->getWidth()) {
			if (world->entitiesField[*posX + i][*posY] != nullptr) {
				std::cout << "MURDER: " << getName() << " (" << *posX << ", " << *posY << ") ";
				std::cout << "murdered " << world->entitiesField[*posX + i][*posY]->getName() << " (" << *posX + i << ", " << *posY << ")\n";
				world->entitiesList->remove(world->entitiesField[*posX + i][*posY]);
				world->entitiesField[*posX + i][*posY] = nullptr;
			}
		}

		if (*posY + i >= 0 && *posY + i < world->getHeight()) {
			if (world->entitiesField[*posX][*posY + i] != nullptr) {
				std::cout << "MURDER: " << getName() << " (" << *posX << ", " << *posY << ") ";
				std::cout << "murdered " << world->entitiesField[*posX + i][*posY]->getName() << " (" << *posX + i << ", " << *posY << ")\n";
				world->entitiesList->remove(world->entitiesField[*posX][*posY + i]);
				world->entitiesField[*posX][*posY + i] = nullptr;
			}
		}
	}
}

Organism* Human::createClone(unsigned x, unsigned y)
{
	return new Human(world, x, y);
}

Human::~Human()
{
	world->~World();
}
