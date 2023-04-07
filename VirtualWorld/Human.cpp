#include "Human.h"

Human::Human(World* world, unsigned posX, unsigned posY, unsigned age) : Animal(world, 5, 4, posX, posY, age)
{
}

void Human::draw()
{
	printf(" H ");
}

void Human::action()
{
	this->age++;
	char userMove;
	unsigned* posX = &this->position[0], *posY = &this->position[1];
	unsigned position[2] = { *posX, *posY };
	printf("Move (arrows) or use special ability (r):\n");
	printf("Human position(%d, %d)\n", position[0], position[1]);
	while (true) {
		userMove = getchar();
		if (userMove == 72 && *posX > 0) {
			(*posX)--;
			break;
		}
		else if (userMove == 80 && *posX < world->getHeight() - 1) {
			(*posX)++;
			break;
		}
		else if (userMove == 75 && *posY > 0) {
			(*posY)--;
			break;
		}
		else if (userMove == 77 && *posY < world->getWidth() - 1) {
			(*posY)++;
			break;
		}
		else if (userMove == 'r') {
			this->specialAbility();
			break;
		}
	}
	world->entitiesField[position[0]][position[1]] = nullptr;
	if (world->entitiesField[*posX][*posY] != nullptr) {
		world->entitiesField[*posX][*posY]->collision(this);
	} 
	else {
		world->entitiesField[*posX][*posY] = this;
	}
}

string Human::getName()
{
	return string();
}

void Human::specialAbility()
{
}

Organism* Human::createClone(unsigned x, unsigned y)
{
	return nullptr;
}

Human::~Human()
{
}
