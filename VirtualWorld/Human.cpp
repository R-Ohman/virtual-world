#include "Human.h"

Human::Human(World* world, unsigned posX, unsigned posY, unsigned age)
	: Animal(world, 5, 4, posX, posY, age)
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
		if (userMove == 'a' && *posX > 0) {
			(*posX)--;
			break;
		}
		else if (userMove == 'd' && *posX < world->getWidth() - 1) {
			(*posX)++;
			break;
		}
		else if (userMove == 'w' && *posY > 0) {
			(*posY)--;
			break;
		}
		else if (userMove == 's' && *posY < world->getHeight() - 1) {
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
	return "Human";
}

void Human::specialAbility()
{
}

Organism* Human::createClone(unsigned x, unsigned y)
{
	return new Human(world, x, y);
}

Human::~Human()
{
}
